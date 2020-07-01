from collections import deque
import sys

BEFORE_BREAK = 0
AFTER_BREAK = 1

NULL = 0
WALL = 1
VISITED = 2

D = [{'x': -1, 'y': 0}, {'x': 0, 'y': 1}, {'x': 1, 'y': 0}, {'x': 0, 'y': -1}]

N, M = map(int, sys.stdin.readline().split())

board = [[[0 for col in range(0, M)] for row in range(0, N)] for level in range(0, 2)]

for n in range(0, N):
	line = sys.stdin.readline()
	for m in range(0, M):
		board[BEFORE_BREAK][n][m] = int(line[m])
		board[AFTER_BREAK][n][m] = int(line[m])

q = deque()
board[BEFORE_BREAK][0][0] = VISITED
q.append((BEFORE_BREAK, 0, 0, 1))

ans = -1

while q.__len__() > 0:
	cb, cx, cy, ct  = q.popleft()

	if cx == N - 1 and cy == M - 1:
		ans = ct
		break

	for d in D:
		nb, nx, ny, nt = (cb, cx + d['x'], cy + d['y'], ct + 1)

		if not 0 <= nx < N or not 0 <= ny < M or board[nb][nx][ny] == VISITED:
			continue

		if board[nb][nx][ny] == WALL:
			if nb == AFTER_BREAK:
				continue
			nb = AFTER_BREAK

		board[nb][nx][ny] = VISITED
		q.append((nb, nx, ny, nt))

print(ans)