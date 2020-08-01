// 프로그래머스
// 카카오 2018 블라인드 채용

const NUMBER = "0123456789ABCDEF";

// 진법을 변환시키는 함수
// 진법 n, 변환할 숫자 number
function changeNumber(n, number) {
  let ret = "";
  if (number == 0) {
    return "0";
  }
  while (number !== 0) {
    ret = NUMBER[number % n] + ret;
    number = Math.floor(number / n);
  }
  return ret;
}

// 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p
function solution(n, t, m, p) {
  var answer = "";
  let numberList = "";
  for (let i = 0; i <= t * m; i++) {
    numberList += changeNumber(n, i);
  }
  for (let i = 0; i < t; i++) {
    answer += numberList[i * m + p - 1];
  }
  return answer;
}
