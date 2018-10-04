open Belt;

module CssUnit = {
  type t =
    | Em(int)
    | Rem(int)
    | Px(int)
    | Vw(int)
    | Vh(int);

  let unwrap: t => string =
    v => {
      let (value, suffix) =
        switch (v) {
        | Em(v) => (v, "em")
        | Rem(v) => (v, "rem")
        | Px(v) => (v, "px")
        | Vw(v) => (v, "vw")
        | Vh(v) => (v, "vh")
        };
      string_of_int(value) ++ suffix;
    };

  let unwrapOpt: option(t) => option(string) = Option.map(_, unwrap);
};

[@bs.module "cool-react-lib"]
external reactClass: ReasonReact.reactClass = "default";

[@bs.obj]
external makeProps:
  (
    ~minWidth: string,
    ~maxWidth: string,
    ~minHeight: string,
    ~maxHeight: string,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~minWidth: CssUnit.t,
      ~maxWidth: CssUnit.t,
      ~minHeight: CssUnit.t,
      ~maxHeight: CssUnit.t,
      children,
    ) =>
  CssUnit.(
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~minWidth=minWidth->unwrap,
          ~maxWidth=maxWidth->unwrap,
          ~minHeight=minHeight->unwrap,
          ~maxHeight=maxHeight->unwrap,
          (),
        ),
      children,
    )
  );
