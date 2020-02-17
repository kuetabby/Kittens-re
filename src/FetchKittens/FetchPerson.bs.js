'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");

function FetchPerson(Props) {
  var match = React.useState((function () {
          return /* LoadingPerson */0;
        }));
  var setState = match[1];
  var state = match[0];
  React.useEffect((function () {
          fetch("https://jsonplaceholder.typicode.com/users").then((function (res) {
                      return res.json();
                    })).then((function (jsonRes) {
                    Curry._1(setState, (function (_prevState) {
                            return /* DataPerson */[jsonRes];
                          }));
                    return Promise.resolve(/* () */0);
                  })).catch((function (_err) {
                  Curry._1(setState, (function (_prevState) {
                          return /* ErrorFetchingPerson */1;
                        }));
                  return Promise.resolve(/* () */0);
                }));
          return ;
        }), ([]));
  var containerStyle = {
    display: "flex",
    flexWrap: "wrap",
    justifyContent: "space-evenly"
  };
  var personStyle = {
    border: "2px solid #48a9dc",
    margin: "1em",
    padding: "1em",
    textAlign: "center",
    width: "40%"
  };
  return React.createElement("div", {
              style: containerStyle
            }, typeof state === "number" ? (
                state !== 0 ? "An error occurred!" : "Loading..."
              ) : Belt_Array.mapWithIndex(state[0], (function (i, person) {
                      return React.createElement("div", {
                                  key: String(i),
                                  style: personStyle
                                }, React.createElement("img", {
                                      alt: "kittens",
                                      src: "https://robohash.org/" + (String(person.id) + "?set=set4&size=200x200"),
                                      width: "70%"
                                    }), React.createElement("p", undefined, "Name: ", person.name), React.createElement("p", undefined, "Company: ", person.company.name));
                    })));
}

var A = /* alias */0;

var L = /* alias */0;

var make = FetchPerson;

exports.A = A;
exports.L = L;
exports.make = make;
/* react Not a pure module */
