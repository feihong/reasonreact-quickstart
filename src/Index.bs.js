// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE

import * as ReactDOMRe from "reason-react/src/ReactDOMRe.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as Component1$ReactTemplate from "./Component1.bs.js";
import * as Component2$ReactTemplate from "./Component2.bs.js";

var message = "你好世界！";

ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, Component1$ReactTemplate.make(message, /* array */[])), "index1");

ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, Component2$ReactTemplate.make("Hello!", /* array */[])), "index2");

export {
  message ,
  
}
/*  Not a pure module */
