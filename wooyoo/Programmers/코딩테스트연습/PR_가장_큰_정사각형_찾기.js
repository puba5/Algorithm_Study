function check(size, startX, startY, board) {
  for (let i = startX; i < size; i++) {
    for (let j = startY; j < size; j++) {
      if (board[i][j] == 0) {
        return false;
      }
    }
  }

  return true;
}

function solution(board) {
  var answer = 0;
  let sizeLength = Math.min(board.length, board[0].length);
  for (let size = sizeLength; size > 0; size--) {
    for (let startX = 0; startX < board[0].length - size + 1; startX++) {
      for (let startY = 0; startY < board.length - size + 1; startY++) {
        //console.log(size, startX, startY);
        if (check(size, startX, startY, board)) {
          return size * size;
        }
      }
    }
  }

  return answer;
}
