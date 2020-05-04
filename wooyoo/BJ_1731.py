# 백준 1731 추론 

num = int(input())

num_list = list()

for i in range(num):
    a = int(input())
    num_list.append(a)

if (num_list[1] - num_list[0]) == (num_list[2] - num_list[1]):
    print(num_list[len(num_list) - 1] + num_list[1] - num_list[0])
else:
    print(int(num_list[len(num_list) - 1] * (num_list[1] / num_list[0])))
