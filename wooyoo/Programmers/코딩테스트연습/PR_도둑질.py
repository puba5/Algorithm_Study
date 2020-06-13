# dp 문제
# 연속해서 털지 못하므로, index -2,-3 중에서 최대 값을 구한다

def solution(money):
    answer = 0
    # 첫번째 집을 털 경우 => 마지막 집을 털지 못한다
    dp_first = [0, 0, money[0]]
    # 첫번째 집을 털지 않을 경우
    dp_not = [0, 0, 0]

    for i in range(1, len(money)):
        dp_first.append(money[i])
        dp_not.append(money[i])

    # print(new_money)
    for i in range(3, len(dp_first)):
        if i == len(dp_first) - 1:
            dp_first[i] = max(dp_first[i - 2], dp_first[i - 3])
            dp_not[i] = dp_not[i] + max(dp_not[i - 2], dp_not[i - 3])
        else:
            if dp_first[i - 2] > dp_first[i - 3]:
                dp_first[i] = dp_first[i] + dp_first[i - 2]
            else:
                dp_first[i] = dp_first[i] + dp_first[i - 3]
            if dp_not[i - 2] > dp_not[i - 3]:
                dp_not[i] = dp_not[i] + dp_not[i - 2]
            else:
                dp_not[i] = dp_not[i] + dp_not[i - 3]

        answer = max(answer, dp_first[i], dp_not[i])

    return answer
