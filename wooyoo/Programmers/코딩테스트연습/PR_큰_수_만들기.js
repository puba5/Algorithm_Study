// 간단한 문제
// k+2개 중 제일 큰 수 2개만 남긴다
// 스택을 사용하면 쉽게 풀 수 있을 듯

function solution(number, k) {
  let stack = [number[0]];
  for (let i = 1; i < number.length; i++) {
    while (k && stack.length && stack[stack.length - 1] < number[i]) {
      stack.pop();
      k--;
    }
    stack.push(number[i]);
  }
  while (k) {
    stack.pop();
    k--;
  }
  return stack.join("");
}
