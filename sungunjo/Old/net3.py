def solution(vote) :
    answer = 0
    for i in range(len(vote)):
        k = i
        q = [] 
        for j in range(3):
            k = vote[k] - 1
            if k < 0 :
                break
            q.append(k)
        if i == k:
            answer += 1
            for t in q:
                vote[t] = 0
        else:

    return answer

vote = [2, 3, 1, 5, 6, 3]

print(str(solution(vote)))
