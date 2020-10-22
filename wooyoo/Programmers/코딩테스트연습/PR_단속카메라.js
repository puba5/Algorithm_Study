// 차례로 탐색하면서 차가 나올 때 감시카메라를 설치한다.

function solution(routes) {
  var answer = 0;
  routes.sort((a, b) => a[0] - b[0]);

  let detectingCarList = [];

  for (let route of routes) {
    if (detectingCarList.length === 0) {
      detectingCarList.push(route);
      continue;
    }
    detectingCarList.sort((a, b) => a[1] - b[1]);

    if (route[0] > detectingCarList[0][1]) {
      answer += 1;
      detectingCarList = [route];
      continue;
    }
    detectingCarList.push(route);
  }

  return detectingCarList.length ? answer + 1 : answer;
}
