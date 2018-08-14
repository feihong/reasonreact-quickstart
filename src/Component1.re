let str = ReasonReact.string;

/* This is the basic, stateless component. */
let component = ReasonReact.statelessComponent("Component1");

/* The component itself is stateless, but we use a ref to maintain state
   inside the closure. */
let handleClick = {
  let counter = ref(0);

  (_event) => {
    counter := counter^ + 1;
    let mesg = Printf.sprintf("You have clicked %d times", counter^);
    Js.log(mesg);
  }
};

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Component1 message="hello" />`

   Which desugars to

   `ReasonReact.element(Component1.make(~message="hello", [||]))` */
let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div>
      <span>(message->str)</span>
      <button className="btn btn-default btn-sm"
              onClick=handleClick>
        (str("Click me!"))
      </button>
    </div>,
};
