type hanzi = {
  text: string,
  ordinal: int,
}

type emoji = {
  shortname: string,
  text: string,
  category: string,
}

module Decode = {
  let hanzi = json => Json.Decode.{
    text: json |> field("text", string),
    ordinal: json |> field("ordinal", int),
  };

  let emoji = json => Json.Decode.{
    shortname: json |> field("shortname", string),
    text: json |> field("text", string),
    category: json |> field("category", string),
  };
}

let getHanzi = callback => {
  Js.Promise.(
    Axios.get("/hanzi")
    |> then_(res => {
      res##data |> Decode.hanzi |> callback |> resolve
    })
    |> catch(err => Js.log(err) |> resolve)
    |> ignore
  );
};

let getEmoji = callback => {
  Js.Promise.(
    Axios.get("/emoji")
    |> then_(res => {
      res##data |> Decode.emoji |> callback |> resolve
    })
    |> catch(err => Js.log(err) |> resolve)
    |> ignore
  );
};