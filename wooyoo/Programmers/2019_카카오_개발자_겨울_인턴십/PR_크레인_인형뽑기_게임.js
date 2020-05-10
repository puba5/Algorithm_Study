function take_doll(board, x, depth) {
  let doll_type = 0;
  for (let i = 0; i < depth; i++) {
    if (board[i][x] != 0) {
      doll_type = board[i][x];
      board[i][x] = 0;
      return doll_type;
    }
  }
  return doll_type;
}

function solution(board, moves) {
  var answer = 0;
  let bucket = [];

  let new_doll;
  for (let i of moves) {
    //   console.log(board);
    new_doll = take_doll(board, i - 1, board.length);
    if (new_doll !== 0) {
      if (bucket[0] === new_doll) {
        bucket.shift();
        answer++;
      } else {
        bucket.unshift(new_doll);
      }
    }
    //   console.log(bucket);
  }
  return answer * 2;
}
