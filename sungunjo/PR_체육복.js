
function solution(n, lost, reserve) {
    var answer = n - lost.length;
    
   for (var i = 0; i < lost.length; i++) {
        for (var j = 0; j < reserve.length; j++) {
            if (reserve[j] === -1) {
                continue;
            }
            if (lost[i] === reserve[j]) {
                lost[i] = -1;
                reserve[j] = -1;
                answer += 1;
            } 
        }
    }
    
    
    for (var i = 0; i < lost.length; i++) {
        if (lost[i] === -1) {
            continue;
        }
        for (var j = 0; j < reserve.length; j++) {
            if (reserve[j] === -1) {
                continue;
            }
            if ((lost[i] === (reserve[j] - 1)) ||
                (lost[i] === (reserve[j] + 1))) {
                reserve[j] = -1;
                answer += 1;
                break;
            } 
        }
    }
    
    return answer;
}