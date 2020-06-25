import queue

APT = 0
NULL = -1

D = [(-1, 0), (0, 1), (1, 0), (0, -1)]

N = int(input())

apt_map = [[] for _ in range(0, N)]

for n in range(0, N):
	apt_map[n] = list(input())
	apt_map[n] = [int(apt_map[n][c]) + NULL for c in range(0, N)]

sector_num = 0
sector_cnt = []

for i in range(0, N):
	for j in range(0, N):
		if apt_map[i][j] != APT:
			continue

		sector_num += 1
		q = queue.Queue()
		apt_map[i][j] = sector_num
		q.put((i, j))
		
		cnt = 1

		while q.empty() != True:
			x, y = q.get()

			for (dx, dy) in D:
				nx, ny = x + dx, y + dy
				if ((nx < 0) or (N <= nx) or
					(ny < 0) or (N <= ny) or
					(apt_map[nx][ny] != APT)):
					continue

				apt_map[nx][ny] = sector_num
				q.put((nx, ny))
				cnt += 1

		sector_cnt.append(cnt)

	
print(sector_num)
sector_cnt.sort()

for i in sector_cnt:
	print(i)