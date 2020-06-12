function solution(s) {
    var answer = '';
    if (s.length % 2 == 1) {
        answer = s[Math.floor(s.length / 2)];
        console.log(answer);
    } else {
        answer = s[s.length / 2 - 1] + s[s.length / 2];
    }
    return answer;
}