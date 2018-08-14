open Belt;
open Jest;

describe("Basic", () => {
  open Expect;

  test("mod", () =>
    expect(7 mod 4) |> toBe(3))
});

describe("Component2", () => {
  open Expect;
  open Component2;

  test("getMode Hanzi", () =>
    getMode(`Hanzi)->expect |> toBe(`Hanzi));

  test("getMode Emoji", () =>
    getMode(`Emoji)->expect |> toBe(`Emoji));

  test("getMode Either", () =>
    100
    |. Array.makeBy(_ => getMode(`Either))
    |. Array.every(x => x != `Either)
    |. expect
    |> toBe(true));
});
