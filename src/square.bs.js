// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";

function Square(Props) {
  var value = Props.value;
  var onClick = Props.onClick;
  var cell = value !== undefined ? value : "";
  return React.createElement("button", {
              className: "square",
              onClick: (function (param) {
                  return Curry._1(onClick, undefined);
                })
            }, cell);
}

var make = Square;

export {
  make ,
  
}
/* react Not a pure module */
