// 프로그래머스 숫자의 표현
// 투 포인터 문제

function solution(n) {
  var answer = 0;
  // 시작과 끝 값
  let str = 0;
  let end = 0;
  // 그리고 현재 전체 합
  let sum = 0;

  while (end <= n) {
    if (sum < n) {
      end++;
      sum += end;
    } else if (sum == n) {
      answer += 1;
      end += 1;
      sum += end;
    } else {
      sum -= str;
      str += 1;
    }
  }
  return answer;
}
