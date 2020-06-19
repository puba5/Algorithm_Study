// 프로그래머스 2018 블라인드 다트게임

function resultParsing(dartResultList) {
  let returnString = "";
  // 숫자를 찾기 위한
  let numString = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"];
  // 처음 두 글자를 저장
  returnString += dartResultList.shift();
  returnString += dartResultList.shift();
  while (dartResultList != "" && !(dartResultList[0] in numString)) {
    returnString += dartResultList.shift();
  }
  let returnArray = [];
  if (returnString[1] in numString) {
    returnArray.push(Number(returnString.substr(0, 2)));
    returnArray.push(returnString.substr(2, 1));
    returnArray.push(returnString.substr(3));
  } else {
    returnArray.push(Number(returnString.substr(0, 1)));
    returnArray.push(returnString.substr(1, 1));
    returnArray.push(returnString.substr(2));
  }
  return returnArray;
}

function scoreCount(scoreList, scoreInfo) {
  let score = 0;
  let ret = 0;
  if (scoreInfo[1] == "S") {
    score = scoreInfo[0];
  } else if (scoreInfo[1] == "D") {
    score = Math.pow(scoreInfo[0], 2);
  } else if (scoreInfo[1] == "T") {
    score = Math.pow(scoreInfo[0], 3);
  }
  if (scoreInfo[2] == "#") {
    score *= -1;
  } else if (scoreInfo[2] == "*") {
    score *= 2;
    ret += scoreList[scoreList.length - 1];
  }
  scoreList.push(score);
  ret += score;
  return ret;
}

function solution(dartResult) {
  var answer = 0;
  let dartResultList = [...dartResult];

  let scoreList = [0];
  for (let i = 0; i < 3; i++) {
    let scoreInfo = resultParsing(dartResultList);
    answer += scoreCount(scoreList, scoreInfo);
  }

  return answer;
}
