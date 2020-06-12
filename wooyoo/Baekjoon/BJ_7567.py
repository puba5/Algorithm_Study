# 백준 7567 그릇
# 그릇은 10cm, 겹치면 5cm 추가
# 그릇의 방향이 반대이면 10cm를 더하고, 같으면 5cm를 더한다

dishes = input()

dishes_height = 10
for i in range(1, len(dishes)):
    if dishes[i] == dishes[i - 1]:
        dishes_height += 5
    else:
        dishes_height += 10

print(dishes_height)
