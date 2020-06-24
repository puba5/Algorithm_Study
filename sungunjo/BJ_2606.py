import queue

C = int(input())
N = int(input())

network = [[] for _ in range(0, C)]
isInfected = [False for _ in range(0, C)]

for n in range (0, N):
	A, B = input().split()
	A = int(A) - 1
	B = int(B) - 1

	network[A].append(B)
	network[B].append(A)

q = queue.Queue(C)
isInfected[0] = True
q.put(0)
ans = 0

while q.empty() != True:
	com = q.get()
	for nextCom in network[com]:
		if isInfected[nextCom] == True:
			continue;
		isInfected[nextCom] = True
		q.put(nextCom)
		ans += 1

print(ans)

