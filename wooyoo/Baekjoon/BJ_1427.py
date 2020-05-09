# 백준 1427 소트인사이드
# 파이썬으로 풀어봤다. 

a = input()
a = list(a)
a.sort()
a.reverse()
for i in a:
    print(i, end="")
