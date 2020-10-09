const findPlace = (doubleQueue, value) => {
  let start = 0;
  let end = doubleQueue.length - 1;
  let mid;
  while (start <= end) {
    mid = parseInt((start + end) / 2);

    if (doubleQueue[mid] === value) return mid;

    if (doubleQueue[mid] < value) start = mid + 1;
    else end = mid - 1;
  }
  if (doubleQueue[mid] < value) return mid + 1;
  else return mid;
};

const insertValue = (doubleQueue, value) => {
  let insertIndex = findPlace(doubleQueue, value);
  doubleQueue.splice(insertIndex, 0, value);
};

const deleteValue = (doubleQueue, index) => {
  if (doubleQueue.length === 0) return;
  if (index === 1) {
    doubleQueue.pop();
    return;
  }
  if (index === -1) {
    doubleQueue.shift();
    return;
  }
};

function solution(operations) {
  const doubleQueue = [];

  for (let operation of operations) {
    let [command, value] = operation.split(" ");
    if (command === "D") {
      deleteValue(doubleQueue, Number(value));
    }
    if (command === "I") {
      insertValue(doubleQueue, Number(value));
    }
  }
  if (doubleQueue.length === 0) return [0, 0];
  return [doubleQueue[doubleQueue.length - 1], doubleQueue[0]];
}
