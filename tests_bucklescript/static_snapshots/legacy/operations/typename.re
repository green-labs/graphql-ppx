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
    type t_first_inner_inner = {
      .
      "__typename": string,
      "field": string,
    };
    type t_first_inner = {
      .
      "__typename": string,
      "inner": Js.Nullable.t(t_first_inner_inner),
    };
    type t_first = {
      .
      "__typename": string,
      "inner": Js.Nullable.t(t_first_inner),
    };
    type t = {. "first": t_first};
    type t_variables = Js.Json.t;
  };
  let query = "query   {\nfirst: nestedObject  {\n__typename  \ninner  {\n__typename  \ninner  {\n__typename  \nfield  \n}\n\n}\n\n}\n\n}\n";
  type t_first_inner_inner = {
    .
    "__typename": string,
    "field": string,
  };
  type t_first_inner = {
    .
    "__typename": string,
    "inner": option(t_first_inner_inner),
  };
  type t_first = {
    .
    "__typename": string,
    "inner": option(t_first_inner),
  };
  type t = {. "first": t_first};
  type t_variables = Js.Json.t;
  let parse: Raw.t => t =
    value => {
      let first = {
        let value = value##first;
        let inner = {
          let value = value##inner;
          switch (Js.toOption(value)) {
          | Some(value) =>
            Some(
              {
                let inner = {
                  let value = value##inner;
                  switch (Js.toOption(value)) {
                  | Some(value) =>
                    Some(
                      {
                        let field = {
                          let value = value##field;
                          value;
                        }
                        and __typename = {
                          let value = value##__typename;
                          value;
                        };
                        {"__typename": __typename, "field": field};
                      },
                    )
                  | None => None
                  };
                }
                and __typename = {
                  let value = value##__typename;
                  value;
                };
                {"__typename": __typename, "inner": inner};
              },
            )
          | None => None
          };
        }
        and __typename = {
          let value = value##__typename;
          value;
        };
        {"__typename": __typename, "inner": inner};
      };
      {"first": first};
    };
  let serialize: t => Raw.t =
    value => {
      let first = {
        let value = value##first;
        let inner = {
          let value = value##inner;
          switch (value) {
          | Some(value) =>
            Js.Nullable.return(
              {
                let inner = {
                  let value = value##inner;
                  switch (value) {
                  | Some(value) =>
                    Js.Nullable.return(
                      {
                        let field = {
                          let value = value##field;
                          value;
                        }
                        and __typename = {
                          let value = value##__typename;
                          value;
                        };
                        {"__typename": __typename, "field": field};
                      },
                    )
                  | None => Js.Nullable.null
                  };
                }
                and __typename = {
                  let value = value##__typename;
                  value;
                };
                {"__typename": __typename, "inner": inner};
              },
            )
          | None => Js.Nullable.null
          };
        }
        and __typename = {
          let value = value##__typename;
          value;
        };
        {"__typename": __typename, "inner": inner};
      };
      {"first": first};
    };
  let make = () => {
    "query": query,
    "variables": Js.Json.null,
    "parse": parse,
  };
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module MyQuery {
  // This is the stringified representation of your query, which gets sent to the server.
  let query: string;

  // This is the main type of the result you will get back.
  // You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  type t;

  // This function turns your raw result from the server into the reason/ocaml representation of that result.
  // Depending on your graphql client library, this process should happen automatically for you.
  let parse: Raw.t => t;

  // This function will prepare your data for sending it back to the server.
  // Depending on your graphql client library, this process should happen automatically for you.
  let serialize: t => Raw.t;

  // The definition tuple is primarily used to interact with client libraries.
  // The types are equivalent to: (parse, query, serialize).
  // Your client library will use these values to provide the properly parsed / serialized data for you.
  let definition: (
    Raw.t => t,
    string,
    t => Raw.t
  );

  // This is the representation of your raw result coming from the server.
  // It should not be necessary to access the types inside for normal use cases.
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
