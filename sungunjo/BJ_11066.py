def minCost(dp, start, end):
	min_val = dp[start][start] + dp[start + 1][end]
	for mid in range(start + 1, end):
		min_val = min(min_val, dp[start][mid] + dp[mid + 1][end])

	return min_val

def solution(nums):
	dp = [[0 for col in range(0, len(nums))] for row in range(0, len(nums))]
	mem = [[nums[col] for col in range(0, len(nums))] for row in range(0, len(nums))]
	
	for k in range(1, len(nums)):
		for i in range(0 + k, len(nums)):
			start = i - k
			end = i

			mem[start][end] = mem[start][end - 1] + nums[end];
			
			dp[start][end] = minCost(dp, start, end) + mem[start][end]

	return dp[0][len(nums) - 1];

T = int(input())
for _ in range(0, T):
	K = int(input())
	nums = list(map(int, input().split(' ')))
	
	print(solution(nums));
