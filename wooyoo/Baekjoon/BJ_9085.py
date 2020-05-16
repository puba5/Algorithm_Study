# 백준 9085 더하기 

t = int(input())

for i in range(t):
    n = input()
    num_list = input().split()
    for j in range(len(num_list)):
        num_list[j] = int(num_list[j])
    print(sum(num_list))
