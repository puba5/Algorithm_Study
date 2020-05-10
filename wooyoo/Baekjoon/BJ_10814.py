# 백준 10814 나이순 정렬

n = int(input())
user_list = []
for i in range(n):
    age, name = input().split()
    user_list.append((int(age), i, name))

user_list.sort()

for i in user_list:
    print(i[0], end=" ")
    print(i[2])
