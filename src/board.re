let calculate_winner = (squares) => {
  let lines = [
    [|0, 1, 2|],
    [|3, 4, 5|],
    [|6, 7, 8|],
    [|0, 3, 6|],
    [|1, 4, 7|],
    [|2, 5, 8|],
    [|0, 4, 8|],
    [|2, 4, 6|]
  ];
  List.fold_left(
    ((win, r) => {
      switch (win) {
      | Some(w) => Some(w)
      | None =>
        let p = Array.get(squares, Array.get(r, 0));
        let q = Array.get(squares, Array.get(r, 1));
        let r = Array.get(squares, Array.get(r, 2));
        if (p == q && p == r) {p} else {None}
      }
    }),
    None,
    lines
  )
};

[@react.component]
let make = () => {
  let ((squares, x_is_next), setSt) =
    React.useState(() => (Array.make(9, None), true));

  let handleClick = (i) => {
    switch (calculate_winner(squares),
            Array.get(squares, i)) {
    | (None, None) =>
      let squares' = Array.copy(squares);
      let player = if (x_is_next) {"X"} else {"O"};
      Array.set(squares', i, Some(player))
            setSt(_ => (squares', !x_is_next))
    | _ => ()
    }
  };

  let render_square = (i) =>
    <Square value={Array.get(squares, i)}
        onClick={() => handleClick(i)} />;

  let statu_message =
    switch (calculate_winner(squares)) {
    | Some(w) => "Winner: " ++ w
    | None =>
      "Next player: " ++
      (x_is_next ? "X" : "O")
    };

  <div>
    <div className="status">
        {React.string(statu_message)}
    </div>
    <div className="board-row">
    {render_square(0)}
    {render_square(1)}
    {render_square(2)}
    </div>
    <div className="board-row">
    {render_square(3)}
    {render_square(4)}
    {render_square(5)}
    </div>
    <div className="board-row">
    {render_square(6)}
    {render_square(7)}
    {render_square(8)}
    </div>
  </div>
};

