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
    type t = {. "recursiveInput": string};
    type t_variables = {. "arg": t_variables_RecursiveInput}
    and t_variables_RecursiveInput = {
      .
      "otherField": Js.Json.t(string),
      "inner": Js.Json.t(t_variables_RecursiveInput),
      "enum": Js.Json.t(string),
    };
  };
  let query = "query ($arg: RecursiveInput!)  {\nrecursiveInput(arg: $arg)  \n}\n";
  type t = {. "recursiveInput": string};
  type t_variables = {. "arg": t_variables_RecursiveInput}
  and t_variables_RecursiveInput = {
    .
    "otherField": option(string),
    "inner": option(t_variables_RecursiveInput),
    "enum": option([ | `FIRST | `SECOND | `THIRD]),
  };
  let parse: Raw.t => t =
    value => {

      "recursiveInput": {
        let value = value##recursiveInput;

        value;
      },
    };
  let serialize: t => Raw.t =
    value => {
      let recursiveInput = {
        let value = value##recursiveInput;

        value;
      };
      {

        "recursiveInput": recursiveInput,
      };
    };
  let rec serializeVariables: t_variables => Js.Json.t =
    inp =>
      [|
        (
          "arg",
          (a => Some(serializeInputObjectRecursiveInput(a)))(inp##arg),
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
      |> Js.Json.object_
  and serializeInputObjectRecursiveInput:
    t_variables_RecursiveInput => Js.Json.t =
    inp =>
      [|
        (
          "otherField",
          (
            a =>
              switch (a) {
              | None => None
              | Some(b) => (a => Some(Js.Json.string(a)))(b)
              }
          )(
            inp##otherField,
          ),
        ),
        (
          "inner",
          (
            a =>
              switch (a) {
              | None => None
              | Some(b) =>
                (a => Some(serializeInputObjectRecursiveInput(a)))(b)
              }
          )(
            inp##inner,
          ),
        ),
        (
          "enum",
          (
            a =>
              switch (a) {
              | None => None
              | Some(b) =>
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
                  b,
                )
              }
          )(
            inp##enum,
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
    )
  and makeInputObjectRecursiveInput =
      (~otherField=?, ~inner=?, ~enum=?, ()): t_variables_RecursiveInput => {

    "otherField": otherField,

    "inner": inner,

    "enum": enum,
  };
  let makeWithVariables = variables => {
    "query": query,
    "variables": serializeVariables(variables),
    "parse": parse,
  };
  let definition = (parse, query, serialize);
};
