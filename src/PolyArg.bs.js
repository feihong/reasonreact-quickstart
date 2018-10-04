// Generated by BUCKLESCRIPT VERSION 4.0.3, PLEASE EDIT WITH CARE

import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as CoolReactLib from "cool-react-lib";

function unwrap(v) {
  var match;
  switch (v.tag | 0) {
    case 0 : 
        match = /* tuple */[
          v[0],
          "em"
        ];
        break;
    case 1 : 
        match = /* tuple */[
          v[0],
          "rem"
        ];
        break;
    case 2 : 
        match = /* tuple */[
          v[0],
          "px"
        ];
        break;
    case 3 : 
        match = /* tuple */[
          v[0],
          "vw"
        ];
        break;
    case 4 : 
        match = /* tuple */[
          v[0],
          "vh"
        ];
        break;
    
  }
  return String(match[0]) + match[1];
}

function unwrapOpt(__x) {
  return Belt_Option.map(__x, unwrap);
}

var CssUnit = /* module */[
  /* unwrap */unwrap,
  /* unwrapOpt */unwrapOpt
];

function make(minWidth, maxWidth, minHeight, maxHeight, children) {
  return ReasonReact.wrapJsForReason(CoolReactLib.default, {
              minWidth: unwrap(minWidth),
              maxWidth: unwrap(maxWidth),
              minHeight: unwrap(minHeight),
              maxHeight: unwrap(maxHeight)
            }, children);
}

export {
  CssUnit ,
  make ,
  
}
/* ReasonReact Not a pure module */