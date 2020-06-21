
def sumOfArr(num_arr):
	sum_of_arr = 0
	for num in num_arr:
		sum_of_arr += num
	return sum_of_arr

def solution(M, m, c):
	N = len(m)
	max_cost = sumOfArr(c)
	dp = [[0 for col in range(0, N)] for row in range(0, max_cost + 1)]

	for cost in range(0, max_cost + 1):
		for n in range(0, N):
			if cost < c[n]:
				if n > 0:
					dp[cost][n] = dp[cost][n - 1]
			else:
				if n > 0:
					dp[cost][n] = max(m[n] + dp[cost - c[n]][n - 1], dp[cost][n - 1])
				else:
					dp[cost][n] = m[n]

	for cost in range(0, max_cost + 1):
		if dp[cost][N - 1] >= M:
			return cost
	
	return -1

M = (int(input().split(' ')[1]))
m = list(map(int, input().split(' ')))
c = list(map(int, input().split(' ')))

print(solution(M, m, c))