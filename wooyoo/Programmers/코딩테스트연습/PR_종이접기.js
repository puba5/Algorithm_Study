// 프로그래머스  종이접기

function solution(n) {
  var answer = [];
  for (let i = 0; i < n; i++) {
    let newAnswer = [];
    for (let j = 0; j < 2 ** i; j++) {
      newAnswer.push(j % 2);
      if (j === 2 ** i - 1) continue;
      newAnswer.push(answer[j]);
    }
    answer = newAnswer;
  }
  return answer;
}
