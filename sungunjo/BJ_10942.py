import sys

IS_FEL = 1
IS_NOT_FEL = 0
NOT_YET = -2

def solution(cache, arr, S, E):
	if (S >= E):
		return IS_FEL

	if cache[S][E] != NOT_YET:
		return cache[S][E]
	
	if arr[S] != arr[E]:
		cache[S][E] = IS_NOT_FEL
		return cache[S][E]
	else:
		cache[S][E] = solution(cache, arr, S + 1, E - 1)
		return cache[S][E]

N = int(input())
arr = [int(i) for i in sys.stdin.readline().split()]
M = int(input())

cache = [[NOT_YET for col in range(0, N)] for row in range(0, N)]

for _ in range(0, M):
	S, E = [int(i) for i in sys.stdin.readline().split()]

	print(solution(cache, arr, S - 1, E - 1))