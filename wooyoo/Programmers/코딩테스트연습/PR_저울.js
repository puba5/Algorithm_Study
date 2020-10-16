// 프로그래머스 저울 문제

function solution(weight) {
  let answer = 0;

  weight.sort((a, b) => a - b);
  for (let i of weight) {
    if (answer + 1 < i) {
      return answer + 1;
    } else {
      answer += i;
    }
  }

  return answer + 1;
}
