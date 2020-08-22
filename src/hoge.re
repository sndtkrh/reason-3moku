[@react.component]
let make = (~name) =>
  <div>
    {React.string("hogehoge" ++ name ++ name)}
  </div>
