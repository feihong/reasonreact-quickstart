let str = ReasonReact.string;

type mode = 
  | Hanzi
  | Emoji
  | Both;

/* State declaration */
type state = {
  chars: array(string),
  mode: mode,
};

/* Action declaration */
type action =
  | Fetch
  | CharLoaded(string)
  | ChangeMode(mode);

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Component2");

/* let fetchSomething = self: component => {
  let mode = self.state.mode;
  switch (mode) {
  | Hanzi => ApiClient.getHanzi(hanzi => 
  |   self.send(CharLoaded(hanzi.text)))
  | Emoji => ApiClient.getEmoji(emoji => 
  |   self.send(CharLoaded(emoji.text))) 
  | _ => ()
  }
}; */

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (_children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {chars: [||], mode: Hanzi},

  didMount: self => self.send(Fetch),

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | ChangeMode(mode) => ReasonReact.Update({...state, mode: mode})
    | Fetch => ReasonReact.SideEffects(self => {
        ApiClient.getHanzi(hanzi => self.send(CharLoaded(hanzi.text)));
        ApiClient.getEmoji(emoji => self.send(CharLoaded(emoji.text)));
      })
    | CharLoaded(text) => 
        ReasonReact.Update({
          ...state, 
          chars: Array.append(state.chars, [|text|])
        })
    },

  render: self => {
    let changeModeOption = (label, mode) =>
      <option onClick=(_evt => self.send(ChangeMode(mode)))>
        (str(label))
      </option>;

    <div>
      <select>
        (changeModeOption("Hanzi", Hanzi))
        (changeModeOption("Emoji", Emoji))
        (changeModeOption("Both", Both))
      </select>
      <button className="btn btn-primary btn-sm"
              onClick=(_ => self.send(Fetch))>
        (str("Generate"))
      </button>
      <div className="chars">
        (
          self.state.chars 
          |> Array.map(ch => <span key=ch>(str(ch))</span>)
          |> ReasonReact.array
        )
      </div>
    </div>;
  },
};
