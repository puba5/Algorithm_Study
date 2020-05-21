function solution(n) {
  const MOD = 1000000007;
  var dp = new Array(60001);

  dp[0] = 1;
  dp[1] = 1;

  for (let i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
    dp[i] %= MOD;
    // console.log(i, dp[i])
  }

  var answer = dp[n];
  return answer;
}
