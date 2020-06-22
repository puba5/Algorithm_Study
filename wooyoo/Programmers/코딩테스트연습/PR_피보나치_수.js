// 프로그래머스 피보나치 수

function solution(n) {
  const MOD = 1234567;
  let fiboList = [0, 1];
  for (let i = 2; i <= n; i++) {
    fiboList[i] = (fiboList[i - 1] + fiboList[i - 2]) % MOD;
    fiboList.push(fiboList[i]);
  }
  return fiboList[n];
}
