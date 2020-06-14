function solution(arr, divisor) {
    var answer = [];
    
    for (var i in arr) {
        if (arr[i] % divisor === 0) {
            answer[answer.length] = arr[i];
        }
    }
    
    answer.sort(function (a, b) {
        return a - b;
    });
    if (answer.length === 0) {
        answer[0] = -1;
    }
    return answer;
}