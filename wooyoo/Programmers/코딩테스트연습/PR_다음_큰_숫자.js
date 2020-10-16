// 프로그래머스 다음 큰 숫자
// 제한 사항은 n은 1,000,000 이하의 자연수
// 2의 개수를 세는 시간 log(n)
// 최악의 경우 모든 자연수를 체크하므로 n
// n*log(n)

function countTwo(number) {
  let ret = 0;
  while (number != 0) {
    ret += number % 2;
    number = parseInt(number / 2);
  }
  return ret;
}

function solution(n) {
  let twoNum = countTwo(n);
  while (n++) {
    if (twoNum == countTwo(n)) {
      return n;
    }
  }
}
