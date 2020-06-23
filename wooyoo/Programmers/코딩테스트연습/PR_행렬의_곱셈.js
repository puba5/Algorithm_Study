// 프로그래머스 행렬의 곱셈
// 간단한 구현 문제

function solution(arr1, arr2) {
  var answer = [];
  // (i*k) (k*j) 두 행렬의 곱
  for (let i = 0; i < arr1.length; i++) {
    let row = [];
    for (let j = 0; j < arr2[0].length; j++) {
      let calculateResult = 0;
      for (let k = 0; k < arr1[0].length; k++) {
        calculateResult += arr1[i][k] * arr2[k][j];
      }
      row.push(calculateResult);
    }
    answer.push(row);
  }
  return answer;
}
