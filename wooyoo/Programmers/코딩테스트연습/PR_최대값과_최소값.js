// 프로그래머스 최대값과 최소값

function solution(s) {
  let numList = s.split(" ");
  let numberList = numList.map((a) => Number(a));
  let max = Math.max.apply(null, numberList);
  let min = Math.min.apply(null, numberList);
  return min + " " + max;
}
