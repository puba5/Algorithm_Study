// 겹치는 원소가 없는 튜플
// 튜플 () 을 집합으로 {}

// 집합의 집합들을 만든 후, 작은 집합부터 넣는다.

function solution(s) {
  var answer = [];
  var setList = [];
  var numString = "";
  var set = [];
  for (var i = 0; i < s.length; i++) {
    // 집합 구분자인지 숫자 구분자인지
    if (s[i] == ",") {
      // 쉼표일 때 집합 구분자가 아니라면 숫자를 넣어준다.
      if (numString != "") {
        set.push(Number(numString));
        numString = "";
      }
    } else if (s[i] == "{") {
      set = [];
    } else if (s[i] == "}") {
      // 마지막 원소는 쉼표로 구분이 안되므로, 그때 집합에 넣어준다
      if (numString != "") {
        set.push(Number(numString));
        numString = "";
      }
      // 마지막 빼고는 SetList에 넣어준다.
      if (set.length != 0) {
        setList.push(set);
        set = [];
      }
    } else {
      numString += s[i];
    }
  }

  // 집합 내부에 같은게 없도록
  setList.sort((a, b) => {
    return a.length - b.length;
  });

  for (var i = 0; i < setList.length; i++) {
    for (var j of setList[i]) {
      // 새로운 집합에 새로운 값이 있다면 answer에 넣어준다
      if (answer.indexOf(j) == -1) {
        answer.push(j);
      }
    }
  }

  return answer;
}
