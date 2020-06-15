// PR_최대공약수와_최소공배수

function solution(n, m) {
  var answer = [];
  let minNumber = Math.min(n, m);
  let gcd = 0;
  for (let i = 1; i <= minNumber; i++) {
    if (n % i == 0 && m % i == 0) {
      gcd = i;
    }
  }
  answer.push(gcd);
  answer.push((n * m) / gcd);
  return answer;
}
