function solution(x) {
    let sum = 0;
    let tmp = x;
    while (tmp > 0) {
        sum += (tmp % 10);
        tmp = Math.floor(tmp / 10);
    }
    let answer = (x % sum === 0);
    
    return answer;
}