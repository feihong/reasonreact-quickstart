let str = ReasonReact.string;

type state = {
  value: int
};

type action =
  | Increment
  | Reset
  | Double;

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
      <button className="btn btn-default btn-sm"
              onClick=(_ => self.send(Double))>
        (str("Double"))
      </button>
      <span>
        (self.state.value |. string_of_int |. str)
      </span>
    </div>,
};