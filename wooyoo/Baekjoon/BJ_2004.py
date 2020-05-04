# 백준 2004 조합 0의 개수 
# 수학적인 개념을 사용하여 속도를 줄이는게 관건
# 파이썬으로도 통과되서 좀 신기 

n, m = input().split()
n = int(n)
m = int(m)


def count(num):
    two = 2
    five = 5
    two_cnt = 0
    five_cnt = 0
    while two <= num:
        two_cnt += int(num / two)
        two *= 2
    while five <= num:
        five_cnt += int(num / five)
        five *= 5
    return two_cnt, five_cnt


n_two, n_five = count(n)
# print(count(n))
m_two, m_five = count(m)
# print(count(m))
m_two2, m_five2 = count(n - m)
# print(count(n-m))

all_two = n_two - m_two - m_two2
all_five = n_five - m_five - m_five2

answer = min(all_five, all_two)
print(answer)
