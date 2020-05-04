# 백준 14425 문자열 집합
# 맵 자료구조를 사용하여 구현
# 파이썬에서는 딕셔너리 활용

m, s = input().split()
s = int(s)
m = int(m)
# dictionary를 이용하여 map을 구현
dict1 = {}

for i in range(m):
    tmp = input()
    dict_tmp = {tmp: 1}
    dict1.update(dict_tmp)

answer = 0
for i in range(s):
    tmp = input()
    if tmp in dict1:
        answer += 1

print(answer)
