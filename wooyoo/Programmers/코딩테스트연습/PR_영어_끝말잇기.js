// 프로그래머스 영어 끝말잇기
// set을 활용

function solution(n, words) {
  var answer = [0, 0];

  let wordSet = new Set([words[0]]);

  for (let i = 1; i < words.length; i++) {
    if (wordSet.has(words[i])) {
      return [(i % n) + 1, parseInt(i / n) + 1];
    } else {
      wordSet.add(words[i]);
    }
    if (words[i][0] != words[i - 1][words[i - 1].length - 1]) {
      return [(i % n) + 1, parseInt(i / n) + 1];
    }
  }

  return answer;
}
