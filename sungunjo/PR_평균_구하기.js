function solution(arr) {
    var answer = 0;
    var sum = 0;
    for (var idx in arr) {
        sum += arr[idx];
    }
    
    answer = (sum / arr.length);
    return answer;
}