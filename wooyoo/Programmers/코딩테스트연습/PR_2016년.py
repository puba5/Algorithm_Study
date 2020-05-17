# 프로그래머즈 2016년

def solution(a, b):
    answer = ''
    days_of_month = [31,29,31,30,31,30,31,31,30,31,30,31]
    # 1월 1일이 금요일이므로, 0은 THU
    day_list = ["THU","FRI","SAT","SUN","MON","TUE","WED"] 
    day_count = 0
    for i in range(a-1):
        day_count += days_of_month[i]
    day_count += b
    answer = day_list[(day_count%7)]
    return answer
