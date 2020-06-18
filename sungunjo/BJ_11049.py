
def setMinCost(mats, dp, n, m):
	min_cost = 3000000000
	for mid in range(n, m):
		min_cost = min(min_cost, (dp[n][mid] + dp[mid + 1][m] + (mats[n][0] * mats[mid][1] * mats[m][1])))

	dp[n][m] = min_cost


def solution(mats):
	dp = [[0 for col in range(0, len(mats))] for row in range(0, len(mats))]
	
	for k in range(1, len(mats)):
		for n in range(0, len(mats) - k):
			m = n + k
			setMinCost(mats, dp, n, m)


	return dp[0][-1]

N = int(input())

mats = []

for i in range(0, N):
	mats.append(list(map(int, input().split(' '))))

print(solution(mats))