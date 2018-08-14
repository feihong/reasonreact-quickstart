open Belt;

let str = ReasonReact.string;

[@bs.deriving jsConverter]
type mode = [
  | `Hanzi
  | `Emoji
  | `Either
]

type coolChar = {
  text: string,
  caption: string,
}

/* State declaration */
type state = {
  chars: list(coolChar),
  mode: mode,
}

/* Action declaration */
type action =
  | Fetch
  | Clear
  | CharLoaded(coolChar)
  | ChangeMode(mode);

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Component2");

let getMode = fun
  | `Either =>
      switch (Random.int(2)) {
      | 0 => `Hanzi
      | _ => `Emoji
      }
  | x => x;

/* `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (_children) => {
  /* You need an extra annotation to help type inference */
  let fetchSomething = ({ReasonReact.state, send}) => {
    switch (getMode(state.mode)) {
    | `Hanzi => ApiClient.getHanzi(hanzi =>
        {
          text: hanzi.text,
          caption: Printf.sprintf("Code point: %d", hanzi.ordinal),
        } |. CharLoaded |. send)
    | `Emoji => ApiClient.getEmoji(emoji =>
        {
          text: emoji.text,
          caption: Printf.sprintf("%s (%s)", emoji.shortname, emoji.category),
        } |. CharLoaded |. send)
    | _ => ()
    }
  };

  let event2Mode = evt =>
    evt
    |. ReactEvent.Form.target
    |. x => x##value
    |. modeFromJs
    |. Option.getWithDefault(`Either);

  {
    ...component,

    initialState: () => {
      chars: [],
      mode: `Either
    },

    didMount: self => self.send(Fetch),

    reducer: (action, state) => ReasonReact.(
      switch (action) {
        | Fetch => SideEffects(self => fetchSomething(self))
        | Clear => Update({...state, chars: []})
        | ChangeMode(mode) => Update({...state, mode: mode})
        | CharLoaded(text) =>
            Update({...state, chars: [text, ...state.chars]})
      }
    ),

    render: ({state, send}) => {
      let modeOption = (i, mode) => {
        let label = mode->modeToJs;
        <option key=string_of_int(i) value=label>
          (label->str)
        </option>
      };

      <div>
        <div className="form-inline">
          <select className="form-control mr-2"
                  value=modeToJs(state.mode)
                  onChange=(evt => evt->event2Mode->ChangeMode->send)>
            (
              [|`Hanzi, `Emoji, `Either|]
              |. Array.mapWithIndex(modeOption)
              |. ReasonReact.array
            )
          </select>
          <button className="btn btn-primary btn-sm mr-2"
                  onClick=(_ => send(Fetch))>
            ("Generate"->str)
          </button>
          <button className="btn btn-primary btn-sm"
                  onClick=(_ => send(Clear))>
            ("Clear"->str)
          </button>
        </div>
        <div className="chars">
          (
            state.chars
            |. List.mapWithIndex((i, cc) =>
                <span key=string_of_int(i) title=cc.caption>
                  (cc.text->str)
                </span>)
            |. List.toArray
            |. ReasonReact.array
          )
        </div>
      </div>;
    },
  }
};
