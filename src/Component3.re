let str = ReasonReact.string;

type state = {
  value: int
};

type action =
  | Increment
  | Reset
  | Double;

module DoubleButton = {
  let component = ReasonReact.statelessComponent("DoubleButton");

  let make = (~label, ~send, _children) => {
    ...component,
    render: _self => 
      <button className="btn btn-primary btn-sm"
              onClick=(_ => send(Double))>
        (str(label))
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
        (str("Increment"))
      </button>
      <button className="btn btn-default btn-sm"
              onClick=(_ => self.send(Reset))>
        (str("Reset"))
      </button>
      <DoubleButton label="Double" send=self.send />
      <span>
        (self.state.value |. string_of_int |. str)
      </span>
    </div>,
};