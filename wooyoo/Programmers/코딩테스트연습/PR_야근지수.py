# 프로그래머스 야근 지수
# 우선순위 큐를 이용한 문제 해답

import heapq


def solution(n, works):
    pq = []
    # pq = PriorityQueue()
    for i in works:
        heapq.heappush(pq, -1 * i)

    for _ in range(n):
        top = heapq.heappop(pq)
        if top == 0:
            break
        top += 1
        heapq.heappush(pq, top)

    answer = 0
    while len(pq) > 0:
        top = heapq.heappop(pq)
        answer += top * top

    return answer
