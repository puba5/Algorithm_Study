// 카카오 2018 블라인드 비밀지도
// 간단한 구현 문제

function solution(n, arr1, arr2) {
  var answer = [];

  for (let i = 0; i < n; i++) {
    let sharpLine = [];

    for (let j = 0; j < n; j++) {
      let arr1Element = arr1[i] % 2;
      let arr2Element = arr2[i] % 2;
      sharpLine.push(arr1Element + arr2Element);
      arr1[i] = parseInt(arr1[i] / 2);
      arr2[i] = parseInt(arr2[i] / 2);
    }
    sharpLine = sharpLine.reverse();
    let sharpString = [];
    for (let j of sharpLine) {
      if (j == 0) {
        sharpString += " ";
      } else {
        sharpString += "#";
      }
    }
    answer.push(sharpString);
  }

  return answer;
}
