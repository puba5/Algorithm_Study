function solution(seoul) {
    var answer = '';
    var x = -1;
    
    for (var i in seoul) {
        if (seoul[i] == 'Kim') {
            x = i;
            break;
        }
    }
    
    answer = '김서방은 ' + x + '에 있다'
    return answer;
}