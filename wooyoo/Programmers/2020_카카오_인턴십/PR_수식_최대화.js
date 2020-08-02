// 프로그래머스 2020 카카오 인턴십
// 수식 최대화

function solution(expression) {
  let expressionList = parseExpression(expression);
  return Math.max(
    orderCalculate(expressionList, "+", "-", "*"),
    orderCalculate(expressionList, "+", "*", "-"),
    orderCalculate(expressionList, "-", "+", "*"),
    orderCalculate(expressionList, "-", "*", "+"),
    orderCalculate(expressionList, "*", "-", "+"),
    orderCalculate(expressionList, "*", "+", "-")
  );
}

function parseExpression(expression) {
  let expressionList = [];
  let number = "";
  for (let i = 0; i < expression.length; i++) {
    if (expression[i] === "*" || expression[i] === "+" || expression[i] === "-") {
      expressionList.push(Number(number));
      number = "";
      expressionList.push(expression[i]);
    } else {
      number += expression[i];
    }
  }
  expressionList.push(Number(number));
  return expressionList;
}

function orderCalculate(expressionList, mathSignFirst, mathSignSecond, mathSignThird) {
  let result = calculateExpression(
    mathSignThird,
    calculateExpression(mathSignSecond, calculateExpression(mathSignFirst, expressionList))
  )[0];
  return Math.abs(result);
}

function calculateExpression(mathSign, expression) {
  switch (mathSign) {
    case "+":
      return calculatePlus(expression);

    case "-":
      return calculateMinus(expression);

    case "*":
      return calculateTime(expression);
  }
}

function calculatePlus(expression) {
  let retArray = [];
  for (let i = 0; i < expression.length; i++) {
    if (expression[i] === "+") {
      retArray[retArray.length - 1] += expression[i + 1];
      i++;
    } else {
      retArray.push(expression[i]);
    }
  }
  return retArray;
}

function calculateMinus(expression) {
  let retArray = [];
  for (let i = 0; i < expression.length; i++) {
    if (expression[i] === "-") {
      retArray[retArray.length - 1] -= expression[i + 1];
      i++;
    } else {
      retArray.push(expression[i]);
    }
  }
  return retArray;
}

function calculateTime(expression) {
  let retArray = [];
  for (let i = 0; i < expression.length; i++) {
    if (expression[i] === "*") {
      retArray[retArray.length - 1] *= expression[i + 1];
      i++;
    } else {
      retArray.push(expression[i]);
    }
  }
  return retArray;
}
