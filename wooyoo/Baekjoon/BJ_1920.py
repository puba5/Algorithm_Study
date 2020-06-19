# 백준 1920 수찾기 
# 이분탐색 문제 

def binary_search(numList, finding_num):
    start = 0
    end = len(numList) - 1

    while start <= end:
        mid = int((start + end) / 2)
        # print(finding_num, mid)
        if numList[mid] == finding_num:
            return 1
        elif numList[mid] > finding_num:
            end = mid - 1
        else:
            start = mid + 1
    return 0


n = input()
numList = list(map(int, input().split()))
m = input()
queryList = list(map(int, input().split()))

numList.sort()

# print(numList)

for num in queryList:
    print(binary_search(numList, num))
