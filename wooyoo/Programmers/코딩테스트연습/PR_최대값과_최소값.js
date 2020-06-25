function solution(s) {
  let numList = s.split(" ");
  let numberList = numList.map((a) => Number(a));
  let max = Math.max.apply(null, numberList);
  let min = Math.min.apply(null, numberList);
  return min + " " + max;
}
