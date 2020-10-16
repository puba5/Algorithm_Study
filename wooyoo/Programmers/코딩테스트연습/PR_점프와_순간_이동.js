// 다이나믹 프로그래밍 문제
// 다시 뒤로 갈 수 없다는 것을 이용
// 다이나믹인줄 알았는데, 그냥 이진수의 원리를 이용하는 문제
// 다이나믹으로하면 10억이라는 제한조건때문에 메모리 초과난다

function solution(n) {
  var ans = 0;
  let tmp = n;
  while (tmp) {
    if (tmp % 2 != 0) {
      ans++;
    }
    tmp = parseInt(tmp / 2);
  }
  return ans;
}
