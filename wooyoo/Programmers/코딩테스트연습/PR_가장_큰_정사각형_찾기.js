// 프로그래머스 가장 큰 정사각형 찾기
// 정사각형의 크기는 이분탐색으로 탐색 가능
// 인줄 알았는데 dp문제였다 ㅠㅠ
// 푼게 아쉬워 남겨둡니다.
function check(size, startX, startY, board) {
  for (let i = 0; i < size; i++) {
    for (let j = 0; j < size; j++) {
      if (board[i + startX][j + startY] == 0) {
        return false;
      }
    }
  }
  return true;
}

function allCheck(board, mid) {
  for (let startX = 0; startX < board.length - mid + 1; startX++) {
    for (let startY = 0; startY < board[0].length - mid + 1; startY++) {
      if (check(mid, startX, startY, board)) {
        return mid * mid;
      }
    }
  }
  return 0;
}

function solution(board) {
  var answer = 0;
  // let sizeLength = Math.min(board.length, board[0].length);
  // // 이분 탐색 이용
  // let start = 1;
  // let end = sizeLength;
  // while (start <= end) {
  //   let mid = parseInt((start + end) / 2);
  //   let checkResult = allCheck(board, mid);
  //   answer = Math.max(checkResult, answer);
  //   if (checkResult) {
  //     start = mid + 1;
  //   } else {
  //     end = mid - 1;
  //   }
  // }

  for (let x = 0; x < board.length; x++) {
    for (let y = 0; y < board[0].length; y++) {
      if (x == 0 || y == 0) {
        answer = Math.max(answer, board[x][y]);
      } else {
        if (board[x][y] != 0) {
          board[x][y] = Math.min(board[x - 1][y - 1], board[x - 1][y], board[x][y - 1]) + 1;
          answer = Math.max(board[x][y], answer);
        }
      }
    }
  }

  return answer * answer;
}
