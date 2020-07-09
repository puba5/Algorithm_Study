function solution(numbers, hand) {
  var answer = "";
  let rightX = 3;
  let rightY = 2;
  let leftX = 3;
  let leftY = 0;
  for (let number of numbers) {
    let x, y;
    if (number == 0) {
      x = 3;
      y = 1;
    } else {
      x = parseInt((number - 1) / 3);
      y = (number - 1) % 3;
    }
    let gapRight = Math.abs(rightX - x) + Math.abs(rightY - y);
    let gapLeft = Math.abs(leftX - x) + Math.abs(leftY - y);
    if (y == 0) {
      answer += "L";
      leftX = x;
      leftY = y;
    } else if (y == 2) {
      answer += "R";
      rightX = x;
      rightY = y;
    } else {
      if (gapRight == gapLeft) {
        if (hand == "left") {
          answer += "L";
          leftX = x;
          leftY = y;
        } else if (hand === "right") {
          answer += "R";
          rightX = x;
          rightY = y;
        }
      } else if (gapRight > gapLeft) {
        answer += "L";
        leftX = x;
        leftY = y;
      } else if (gapLeft > gapRight) {
        answer += "R";
        rightX = x;
        rightY = y;
      }
    }
  }
  return answer;
}
