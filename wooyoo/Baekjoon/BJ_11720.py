# 백준 11720 숫자의 합
# 파이썬으로 풀어봤다.
n = input()
a = input()
a = list(a)
a.sort()
a.reverse()
sum_num = 0
for i in a:
    sum_num += int(i)

print(sum_num)
