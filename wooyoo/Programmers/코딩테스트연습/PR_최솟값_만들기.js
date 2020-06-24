// 프로그래머스 최솟값 만들기
// JS sort 함수 사용을 항상 주의할 것!!!!!!

function solution(A, B) {
  var answer = 0;

  A.sort((a, b) => a - b);
  B.sort((a, b) => b - a);

  for (let i = 0; i < A.length; i++) {
    answer += A[i] * B[i];
  }
  console.log(A);
  console.log(B);
  return answer;
}
