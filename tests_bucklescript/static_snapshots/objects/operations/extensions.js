// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


function ExtendQuery(M) {
  var use = function (param) {
    
  };
  return {
          use: use
        };
}

var Parent = {
  ExtendQuery: ExtendQuery
};

var Raw = { };

var query = "query Bla  {\nlists  {\nnullableOfNullable  \nnullableOfNonNullable  \nnonNullableOfNullable  \nnonNullableOfNonNullable  \n}\n\n}\n";

function parse(value) {
  var value$1 = value.lists;
  var value$2 = value$1.nonNullableOfNonNullable;
  var nonNullableOfNonNullable = value$2.map((function (value) {
          return value;
        }));
  var value$3 = value$1.nonNullableOfNullable;
  var nonNullableOfNullable = value$3.map((function (value) {
          if (!(value == null)) {
            return value;
          }
          
        }));
  var value$4 = value$1.nullableOfNonNullable;
  var nullableOfNonNullable = !(value$4 == null) ? value$4.map((function (value) {
            return value;
          })) : undefined;
  var value$5 = value$1.nullableOfNullable;
  var nullableOfNullable = !(value$5 == null) ? value$5.map((function (value) {
            if (!(value == null)) {
              return value;
            }
            
          })) : undefined;
  return {
          lists: {
            nullableOfNullable: nullableOfNullable,
            nullableOfNonNullable: nullableOfNonNullable,
            nonNullableOfNullable: nonNullableOfNullable,
            nonNullableOfNonNullable: nonNullableOfNonNullable
          }
        };
}

function serialize(value) {
  var value$1 = value.lists;
  var value$2 = value$1.nonNullableOfNonNullable;
  var nonNullableOfNonNullable = value$2.map((function (value) {
          return value;
        }));
  var value$3 = value$1.nonNullableOfNullable;
  var nonNullableOfNullable = value$3.map((function (value) {
          if (value !== undefined) {
            return value;
          } else {
            return null;
          }
        }));
  var value$4 = value$1.nullableOfNonNullable;
  var nullableOfNonNullable = value$4 !== undefined ? value$4.map((function (value) {
            return value;
          })) : null;
  var value$5 = value$1.nullableOfNullable;
  var nullableOfNullable = value$5 !== undefined ? value$5.map((function (value) {
            if (value !== undefined) {
              return value;
            } else {
              return null;
            }
          })) : null;
  return {
          lists: {
            nullableOfNullable: nullableOfNullable,
            nullableOfNonNullable: nullableOfNonNullable,
            nonNullableOfNullable: nonNullableOfNullable,
            nonNullableOfNonNullable: nonNullableOfNonNullable
          }
        };
}

function makeVariables(param) {
  
}

function makeDefaultVariables(param) {
  
}

var Z__INTERNAL = {
  graphql_module: 0
};

var Bla$prime = {
  Raw: Raw,
  query: query,
  parse: parse,
  serialize: serialize,
  makeVariables: makeVariables,
  makeDefaultVariables: makeDefaultVariables,
  Z__INTERNAL: Z__INTERNAL
};

function use(param) {
  
}

var Bla = {
  Raw: Raw,
  query: query,
  parse: parse,
  serialize: serialize,
  makeVariables: makeVariables,
  makeDefaultVariables: makeDefaultVariables,
  Z__INTERNAL: Z__INTERNAL,
  use: use
};

exports.Parent = Parent;
exports.Bla$prime = Bla$prime;
exports.Bla = Bla;
/* No side effect */