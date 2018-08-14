let str = ReasonReact.string;

type state = {
  value: int
};

type action =
  | Increment
  | Reset
  | Double;

/* Note how this stateless component takes a send argument */
module DoubleButton = {
  let component = ReasonReact.statelessComponent("DoubleButton");

  let make = (~label, ~send, _children) => {
    ...component,
    render: _self =>
      <button className="btn btn-primary btn-sm"
              onClick=(_ => send(Double))>
        (label->str)
      </button>
  };
};

let component = ReasonReact.reducerComponent("Component3");

let make = (~startValue, _children) => {
  ...component,

  initialState: () => {value: startValue},

  reducer: (action, state) =>
    switch (action) {
    | Increment => ReasonReact.Update({value: state.value + 1})
    | Reset => ReasonReact.Update({value: startValue})
    | Double => ReasonReact.Update({value: state.value * 2})
    },

  render: self =>
    <div>
      <button className="btn btn-default btn-sm"
              onClick=(_ => self.send(Increment))>
        ("Increment"->str)
      </button>
      <button className="btn btn-default btn-sm"
              onClick=(_ => self.send(Reset))>
        ("Reset"->str)
      </button>
      <DoubleButton label="Double" send=self.send />
      <span>
        (self.state.value->string_of_int->str)
      </span>
    </div>,
};
