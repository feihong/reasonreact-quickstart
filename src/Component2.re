let str = ReasonReact.string;

type coolChar = {
  text: string,
  caption: string,
}

/* State declaration */
type state = {
  chars: array(coolChar),
  mode: string,
};

/* Action declaration */
type action =
  | Fetch
  | Clear
  | CharLoaded(coolChar)
  | ChangeMode(string);

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Component2");

/* `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (_children) => {
  let getMode = (mode) =>
    if (mode == "Either") {
      switch (Random.int(2)) {
      | 0 => "Hanzi"
      | _ => "Emoji"
      }
    } else 
      mode;

  /* You need an extra annotation to help type inference */
  let fetchSomething = (state, send) => {  
    let mode = getMode(state.mode);
    /* send(CharLoaded({text: "W", caption: "wow"})); */
    switch (mode) {
    | "Hanzi" => ApiClient.getHanzi(hanzi => 
        {
          text: hanzi.text, 
          caption: Printf.sprintf("Code point: %d", hanzi.ordinal),
        } |. CharLoaded |. send)
    | "Emoji" => ApiClient.getEmoji(emoji => 
        {
          text: emoji.text, 
          caption: Printf.sprintf("%s (%s)", emoji.shortname, emoji.category),
        } |. CharLoaded |. send)
    | _ => ()
    }
  };

  {
    /* spread the other default fields of component here and override a few */
    ...component,

    initialState: () => {
      chars: [||], 
      mode: "Either"
    },

    didMount: self => self.send(Fetch),

    /* State transitions */
    reducer: (action, state) => ReasonReact.(
      switch (action) {
        | Fetch => SideEffects(self => fetchSomething(self.state, self.send))
        | Clear => Update({...state, chars: [||]})
        | ChangeMode(mode) => Update({...state, mode: mode})
        | CharLoaded(text) => 
            Update({
              ...state, 
              chars: Array.append(state.chars, [|text|])
            })
      }
    ),

    render: ({state, send}) => {
      let changeModeOption = (label) =>
        <option value=label>
          (str(label))
        </option>;

      <div>
        <div className="form-inline">
          <select className="form-control mr-2" 
                  value=state.mode
                  onChange=(evt =>
                    send(
                      ChangeMode(
                        (
                          evt 
                          |. ReactEventRe.Form.target 
                          |. ReactDOMRe.domElementToObj
                        )##value                      
                      )
                    )
                  )>
            (changeModeOption("Hanzi"))
            (changeModeOption("Emoji"))
            (changeModeOption("Either"))
          </select>
          <button className="btn btn-primary btn-sm mr-2"
                  onClick=(_ => send(Fetch))>
            (str("Generate"))
          </button>
          <button className="btn btn-primary btn-sm"
                  onClick=(_ => send(Clear))>
            (str("Clear"))
          </button>
        </div>
        <div className="chars">
          (
            state.chars 
            |> Array.mapi((i, cc) => 
                <span key=string_of_int(i) title=cc.caption>
                  (str(cc.text))
                </span>)
            |> ReasonReact.array
          )
        </div>
      </div>;
    },
  }
};
