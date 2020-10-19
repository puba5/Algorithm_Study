const sortByCost = (a, b) => a[2] - b[2];

const findParent = (parentList, island) => {
  if (parentList[island] === island) return island;

  parentList[island] = findParent(parentList, parentList[island]);
  return parentList[island];
};

const getTotalCost = (parentList, costs) => {
  let answer = 0;
  console.log(parentList);

  for (let bridge of costs) {
    let islandA = bridge[0];
    let islandB = bridge[1];
    let cost = bridge[2];
    if (findParent(parentList, islandA) === findParent(parentList, islandB)) continue;

    answer += cost;
    parentList[findParent(parentList, islandB)] = findParent(parentList, islandA);

    console.log(parentList);
  }
  return answer;
};

function solution(n, costs) {
  let parentList = new Array(n + 1).fill(0).map((value, index) => index);

  costs.sort(sortByCost);

  return getTotalCost(parentList, costs);
}
