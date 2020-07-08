// 프로그래머스 예상 대진표
// 간단한 구현 문제
// 이진수의 특성을 이용

function solution(n, a, b) {
  var answer = 0;
  while (1) {
    if (a == b) {
      return answer;
    }
    a = parseInt((a + 1) / 2);
    b = parseInt((b + 1) / 2);
    answer++;
  }
  return answer;
}
