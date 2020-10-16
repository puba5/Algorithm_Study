def solution(score, k) :
    score_len = len(score)
    answer = score_len
    d = {}
    over_k_diff = []
    for i in range(score_len - 1):
        diff = score[i] - score[i+1]
        if diff in d:           ###
            if d[diff] != 0:
                d[diff] += 1
            if d[diff] >= k - 1:
                over_k_diff.append(diff)
                d[diff] = 0                   ###
        else:
            d[diff] = 1

    chain = False

    for i in range(score_len - 1):
        if (score[i] - score[i+1]) in over_k_diff:
            if chain == True:
                answer = answer - 1                                          ##
            else:
                answer = answer - 2
                chain = True
        else:
            chain = False

    return answer


k = 2
score = [1300000000, 700000000, 668239490, 618239490, 568239490, 568239486, 518239486, 157658638, 157658634, 100000000, 100]
print(solution(score, k))
