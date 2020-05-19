// 프로그래머즈 멀쩡한 사각형

// 기울기를 구한 후, y = ax라는 식을 생성
// 그리고 x를 1을 기준으로, a(x-1)은 내림, ax는 올림을 한다.
// 그리고 이 값의 차가 잘린 종이 개수

function solution(w, h) {
  var answer = 0;
  //var gradient = h / w;
  // 원래는 gradient로 따로 변수를 만들어주려했으나
  // 오차 때문에 테스트 케이스 하나가 제대로 돌아가지 않음
  //console.log(gradient);
  for (let i = 0; i < w; i++) {
    let lowerPaper = Math.floor((h * i) / w);
    let higherPaper = Math.ceil((h * (i + 1)) / w);
    //console.log(lowerPaper, higherPaper);
    answer += higherPaper - lowerPaper;
  }
  answer = w * h - answer;
  return answer;
}
