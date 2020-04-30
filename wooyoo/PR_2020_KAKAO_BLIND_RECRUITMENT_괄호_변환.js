// 프로그래머즈 2020_KAKAO_BLIND_RECRUITMENT_괄호_변환

function stringV(v) {
  console.log(v);
  if (v.length == 0) {
    return "";
  }
  var rightOrNot = 0;
  var isRight = 0;
  for (var i = 0; i < v.length; i++) {
    if (v[i] == "(") {
      rightOrNot++;
    } else if (v[i] == ")") {
      rightOrNot--;
      if (rightOrNot < 0) {
        isRight = 1;
      }
    }
    if (rightOrNot == 0) {
      if (isRight == 0) {
        console.log("Same");
        return v.substring(0, i + 1) + stringV(v.substring(i + 1));
      } else {
        console.log("NotSame");
        var newString = v.substring(1, i);
        var retString = "";
        for (var j = 0; j < newString.length; j++) {
          if (newString[j] == "(") {
            retString += ")";
          } else {
            retString += "(";
          }
        }
        return "(" + stringV(v.substring(i + 1)) + ")" + retString;
      }
    }
  }
  return v;
}

function solution(p) {
  var answer = stringV(p);

  return answer;
}
