function solution(board, aloc, bloc) {
  const ROW = board.length;
  const COL = board[0].length;

  const serializedBoard = board.reduce((acc, row) => acc.concat(row), []);

  const getBoard = (sboard, row, col) => sboard[row * COL + col];
  const setBoard = (sboard, row, col, newItem) =>
    sboard.map((item, idx) => (idx === row * COL + col ? newItem : item));

  const isValidLoc = ([row, col]) =>
    row >= 0 && row < ROW && col >= 0 && col < COL;

  const getChoices = (board, loc) => {
    const [row, col] = loc;
    const allChoices = [
      [row + 1, col],
      [row - 1, col],
      [row, col + 1],
      [row, col - 1],
    ];
    const possibleChoices = allChoices.filter(
      ([row, col]) => isValidLoc([row, col]) && getBoard(board, row, col)
    );
    return possibleChoices;
  };

  const A = "A";
  const B = "B";

  const progressMove = (board, myloc, enemyloc) => {
    const choices = getChoices(board, myloc);
    if (getBoard(board, myloc[0], myloc[1]) === 0) {
      console.log("error");
    }

    // 같은 발판위에 있을 때, 자신이 움직여서 발판이 사라지면 즉시 승리함
    const [mylocRow, mylocCol] = myloc;
    const [enemylocRow, enemylocCol] = enemyloc;
    if (
      mylocRow === enemylocRow &&
      mylocCol === enemylocCol &&
      choices.length > 0
    ) {
      const isWin = true;
      return [true, 1]; // 자기가 움직여야 승리하므로 1
    }

    // 움직일 곳이 없으면 패배
    if (choices.length === 0) {
      return [false, 0]; // 움직일 수 없으므로 0
    }

    const enemyChoiceResult = choices.map((myChoice) => {
      const newBoard = setBoard(board, mylocRow, mylocCol, 0);
      return progressMove(newBoard, enemyloc, myChoice);
    });

    const winnableList = enemyChoiceResult.filter(([isWin, count]) => !isWin);

    // 이기는게 있다면 이기는 것중 가장 count가 작은 것을 선택
    if (winnableList.length > 0) {
      const minCount = Math.min(...winnableList.map(([isWin, count]) => count));
      return [true, minCount + 1];
    }
    // 다 지는 수라면 가장 count가 큰 것을 선택
    const maxCount = Math.max(
      ...enemyChoiceResult.map(([isWin, count]) => count)
    );
    return [false, maxCount + 1];
  };

  const [isWin, count] = progressMove(serializedBoard, aloc, bloc);
  return count;
}
