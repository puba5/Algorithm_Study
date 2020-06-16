// 프로그래머즈_x만큼_간격이_있는_n개의_숫자

function solution(x, n) {
  var answer = [];
  for (let i = 0; i < n; i++) {
    answer.push(i * x + x);
  }
  return answer;
}
