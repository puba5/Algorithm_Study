# 백준 15988
# DP 문제 
test_case = int(input())
MOD = 1000000009
dp_list = [1, 1, 2, 4]

for num in range(4, 1000001):
    dp_sum = (dp_list[num - 1] + dp_list[num - 2] + dp_list[num - 3]) % MOD
    dp_list.append(dp_sum)
    # print(dp_sum)

for _ in range(test_case):
    n = int(input())
    print(dp_list[n])
