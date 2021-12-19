// 프로그래머스 3진법 뒤집기

const changeNumber = (number) => {
  return number.toString(3);
};

function solution(n) {
  let reversed3Num = changeNumber(n).split('').reverse().join('');
  return parseInt(reversed3Num, 3);
}
