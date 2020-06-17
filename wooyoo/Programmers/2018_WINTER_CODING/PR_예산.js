// 카카오 윈터 코딩 예산
// 자바스크립트에서 sort를 할 시, 숫자 같은 경우에도 ASCII 문자 기준으로 sort되므로, 비교 함수를 새로 정의해주어야한다.

function solution(d, budget) {
  let sum = 0;
  d = d.sort((a, b) => a - b);
  let i = 0;
  console.log(typeof d[0]);
  for (; i < d.length; i++) {
    sum += d[i];
    if (sum > budget) {
      return i;
    }
  }
  return i;
}
