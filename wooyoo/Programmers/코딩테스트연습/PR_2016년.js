function solution(a, b) {
    var answer = '';
    let days_of_month = [31,29,31,30,31,30,31,31,30,31,30,31];
    // 1월 1일이 금요일이므로, 0은 THU
    let day_list = ["THU","FRI","SAT","SUN","MON","TUE","WED"];
    let day_count = 0;
    for(let i = 0; i< a-1;i++){
        day_count+= days_of_month[i];
    }
    day_count += b;
    answer= day_list[day_count%7]
    return answer;
}
