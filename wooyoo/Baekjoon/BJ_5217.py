# 백준 5217 쌍의 합

t = int(input())

for i in range(t):
    n = int(input())
    print("Pairs for {}:".format(n), end="")
    for j in range(1, int((n + 1) / 2)):
        if j == 1:
            print(" {} {}".format(j, n - j), end="")
        else:
            print(", {} {}".format(j, n - j), end="")
    print()
