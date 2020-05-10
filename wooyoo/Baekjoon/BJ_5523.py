# 백준 5523 경기 결과
# input 속도가 느리므로 sys.stdin.readline으로 입력 받는다

import sys
n = sys.stdin.readline()

a_win = 0
b_win = 0

for i in range(int(n)):
    a_score, b_score = sys.stdin.readline().split()
    if int(a_score) > int(b_score):
        a_win += 1
    elif int(b_score) > int(a_score):
        b_win += 1

print(a_win, end=" ")
print(b_win)
