DX = [-1, 1, 0, 0]
DY = [0, 0, -1, 1]

def dfs (road_map, visited, x, y):
	if visited[x][y] >= 0:
		return visited[x][y]
		
	if (x == len(road_map) - 1) and (y == len(road_map[0]) - 1):
		visited[x][y] = 1
		return 1

	visited[x][y] = 0
	
	for d in range(0, len(DX)):
		nx = x + DX[d];
		ny = y + DY[d];
		if ((nx < 0) or (len(road_map) <= nx) or 
		(ny < 0) or (len(road_map[0]) <= ny) or
		(road_map[x][y] <= road_map[nx][ny])):
			continue

		visited[x][y] += dfs(road_map, visited, nx, ny);

	return visited[x][y];

M, N = input().split(' ')
M = int(M)
N = int(N)
road_map = []
visited = [[-1 for col in range(0, N)] for row in range(0, M)]

for m in range(0, M):
	road_map.append(list(map(int, input().split(' '))))

print(dfs(road_map, visited, 0, 0))