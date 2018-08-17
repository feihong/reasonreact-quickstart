open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let setup = (~message) =>
  Enzyme.shallow(<Component1 message />);

let message = wrapper =>
  wrapper
  |> Enzyme.find("span")
  |> Enzyme.first;


describe("Component1", () => {
  open Expect;

  test("renders message", () => {
    let wrapper = setup(~message="Funky Munky");
    wrapper
    |. message
    |. Enzyme.text
    |. expect
    |> toBe("Funky Munky")
  });
});
