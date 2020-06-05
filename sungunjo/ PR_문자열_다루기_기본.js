function solution(s) {
    var answer = true;
    if (s.length != 4 && s.length != 6) {
        answer = false;
    } else {
        for (var i = 0; i < s.length; i++) {
            if (isNaN(Number(s[i]))) {
                answer = false;
                break;
            }
        }
    }
    return answer;
}