// 프로그래머스 없는 숫자 더하기

const getTotalSum = (maxNum) => (maxNum * (maxNum + 1)) / 2;

function solution(numbers) {
  let sum = 0;

  numbers.forEach((number) => {
    sum -= number;
  });

  sum += getTotalSum(9);

  return sum;
}
