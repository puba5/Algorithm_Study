// 프로그래머스 올바른 괄호
// 스택 문제

function solution(s) {
  let stack = [];
  s = [...s];
  for (let i of s) {
    stack.push(i);
    while (stack.length > 1 && stack[stack.length - 2] == "(" && stack[stack.length - 1] == ")") {
      stack.pop();
      stack.pop();
    }
  }
  // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
  if (stack.length == 0) {
    return true;
  } else {
    return false;
  }
}
