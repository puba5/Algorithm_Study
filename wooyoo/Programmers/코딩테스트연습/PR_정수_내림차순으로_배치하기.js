// 프로그래머스_정수_내림차순으로_배치하기

function solution(n) {
  return Number([...String(n)].sort().reverse().join(""));
}
