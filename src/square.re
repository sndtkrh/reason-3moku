[@react.component]
let make = (~value, ~onClick) => {
  let cell =
    switch (value) {
    | Some(s) => s
    | None => ""
    };
  <button className="square" onClick={_ => onClick()}>
    {React.string(cell)}
  </button>
};
