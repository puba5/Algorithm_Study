// 정수 제곱근 판별
// for문으로 확인하면 된다.

function solution(n) {
  var answer = 0;
  for (let i = 1; i * i <= 50000000000000; i++) {
    if (n < i * i) {
      answer = -1;
      break;
    }
    if (i * i == n) {
      answer = (i + 1) * (i + 1);
      break;
    }
  }
  return answer;
}
