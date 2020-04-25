[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];
module MyQuery = {
  module Raw = {
    type t = {. "enumInput": string};
    type t_variables = {. "arg": string};
  };
  let query = "query ($arg: SampleField!)  {\nenumInput(arg: $arg)  \n}\n";
  type t = {. "enumInput": string};
  type t_variables = {. "arg": [ | `FIRST | `SECOND | `THIRD]};
  let parse: Raw.t => t =
    value => {

      "enumInput": {
        let value = value##enumInput;

        value;
      },
    };
  let serialize: t => Raw.t =
    value => {
      let enumInput = {
        let value = value##enumInput;

        value;
      };
      {

        "enumInput": enumInput,
      };
    };
  let serializeVariables: t_variables => Js.Json.t =
    inp =>
      [|
        (
          "arg",
          (
            a =>
              Some(
                switch (a) {
                | `FIRST => Js.Json.string("FIRST")
                | `SECOND => Js.Json.string("SECOND")
                | `THIRD => Js.Json.string("THIRD")
                },
              )
          )(
            inp##arg,
          ),
        ),
      |]
      |> Js.Array.filter(
           fun
           | (_, None) => false
           | (_, Some(_)) => true,
         )
      |> Js.Array.map(
           fun
           | (k, Some(v)) => (k, v)
           | (k, None) => (k, Js.Json.null),
         )
      |> Js.Dict.fromArray
      |> Js.Json.object_;
  let make = (~arg, ()) => {
    "query": query,
    "variables":
      serializeVariables(
        {

          "arg": arg,
        }: t_variables,
      ),
    "parse": parse,
  }
  and makeVariables = (~arg, ()) =>
    serializeVariables(
      {

        "arg": arg,
      }: t_variables,
    );
  let makeWithVariables = variables => {
    "query": query,
    "variables": serializeVariables(variables),
    "parse": parse,
  };
  let definition = (parse, query, serialize);
};
