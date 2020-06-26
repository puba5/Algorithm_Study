function solution(n) {
    var answer = '';
    var a = ['수', '박'];
    
    for (var i = 0; i < n; i++) {
        answer += a[i % 2];
    }
    return answer;
}