// 프로그래머스 멀리 뛰기

const MOD = 1234567;

function solution(n) {
  let dp = [1, 1];
  for (let i = 2; i <= n; i++) {
    dp.push((dp[i - 1] + dp[i - 2]) % MOD);
  }
  console.log(dp);
  return dp[n];
}
