open Jest;

describe("Basic", () => {
  open Expect;

  test("mod", () =>
    expect(7 mod 4) |> toBe(3))
});
