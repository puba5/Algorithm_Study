// 프로그래머스 짝지어 제거하기
// 문자 제거 문제인데, 스택의 개념을 이용하여 풀면 쉽게 풀린다.
// 스택 하나와 큐 하나라고 생각하고, 문자를 하나씩 집어넣은 후, 스택의 탑과 큐의 프론트가 같으면 pop!
// 이러면 배열을 한번만 봐도 된다.

function solution(s) {
  let stack = [];

  for (let i = 0; i < s.length; i++) {
    stack.push(s[i]);
    while (stack.length !== 0 && stack[stack.length - 1] == s[i + 1]) {
      stack.pop();
      i++;
    }
  }
  if (stack.length == 0) {
    return 1;
  } else {
    return 0;
  }
}
