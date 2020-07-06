// 프로그래머스 N개의 최소 공배수
// 그냥 무식하게 숫자를 하나씩 증가시키면서 공배수가 맞는지 확인

function solution(arr) {
  let answer = Math.max(...arr) - 1;
  while (answer++) {
    let isAnswer = true;
    arr.map((number) => {
      if (answer % number != 0) {
        isAnswer = false;
      }
    });
    if (isAnswer) return answer;
  }
  return answer;
}
