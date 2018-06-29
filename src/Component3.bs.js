// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE

import * as Block from "bs-platform/lib/es6/block.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as ReasonReact from "reason-react/src/ReasonReact.js";

function str(prim) {
  return prim;
}

var component = ReasonReact.statelessComponent("DoubleButton");

function make(label, send, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("button", {
                          className: "btn btn-primary btn-sm",
                          onClick: (function () {
                              return Curry._1(send, /* Double */2);
                            })
                        }, label);
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

var DoubleButton = /* module */[
  /* component */component,
  /* make */make
];

var component$1 = ReasonReact.reducerComponent("Component3");

function make$1(startValue, _) {
  return /* record */[
          /* debugName */component$1[/* debugName */0],
          /* reactClassInternal */component$1[/* reactClassInternal */1],
          /* handedOffState */component$1[/* handedOffState */2],
          /* willReceiveProps */component$1[/* willReceiveProps */3],
          /* didMount */component$1[/* didMount */4],
          /* didUpdate */component$1[/* didUpdate */5],
          /* willUnmount */component$1[/* willUnmount */6],
          /* willUpdate */component$1[/* willUpdate */7],
          /* shouldUpdate */component$1[/* shouldUpdate */8],
          /* render */(function (self) {
              return React.createElement("div", undefined, React.createElement("button", {
                              className: "btn btn-default btn-sm",
                              onClick: (function () {
                                  return Curry._1(self[/* send */3], /* Increment */0);
                                })
                            }, "Increment"), React.createElement("button", {
                              className: "btn btn-default btn-sm",
                              onClick: (function () {
                                  return Curry._1(self[/* send */3], /* Reset */1);
                                })
                            }, "Reset"), ReasonReact.element(/* None */0, /* None */0, make("Double", self[/* send */3], /* array */[])), React.createElement("span", undefined, String(self[/* state */1][/* value */0])));
            }),
          /* initialState */(function () {
              return /* record */[/* value */startValue];
            }),
          /* retainedProps */component$1[/* retainedProps */11],
          /* reducer */(function (action, state) {
              switch (action) {
                case 0 : 
                    return /* Update */Block.__(0, [/* record */[/* value */state[/* value */0] + 1 | 0]]);
                case 1 : 
                    return /* Update */Block.__(0, [/* record */[/* value */startValue]]);
                case 2 : 
                    return /* Update */Block.__(0, [/* record */[/* value */(state[/* value */0] << 1)]]);
                
              }
            }),
          /* subscriptions */component$1[/* subscriptions */13],
          /* jsElementWrapped */component$1[/* jsElementWrapped */14]
        ];
}

export {
  str ,
  DoubleButton ,
  component$1 as component,
  make$1 as make,
  
}
/* component Not a pure module */
