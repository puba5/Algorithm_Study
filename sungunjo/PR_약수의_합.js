function solution(n) {
    var answer = 0;
    
    for (var num = 1; num <= n; num++) {
        if (n % num == 0) {
            answer += num
        }
    }
    return answer;
}