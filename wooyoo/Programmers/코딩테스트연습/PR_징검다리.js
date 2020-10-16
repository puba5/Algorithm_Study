const getRockDistanceList = (rocksWithStartEnd) => {
  let rocksDistance = [];
  for (let i = 1; i < rocksWithStartEnd.length; i++) {
    rocksDistance.push(rocksWithStartEnd[i] - rocksWithStartEnd[i - 1]);
  }
  return rocksDistance;
};

const checkPossibleMinDistance = (minDistance, rocksWithStartEnd, removedRockCnt) => {
  let rockDistance = getRockDistanceList(rocksWithStartEnd);

  for (let i = 0; i < rockDistance.length; i++) {
    if (rockDistance[i] < minDistance) {
      removedRockCnt -= 1;
      if (removedRockCnt < 0) return false;
      rockDistance[i + 1] += rockDistance[i];
    }
  }

  return true;
};

function solution(distance, rocks, n) {
  var answer = 0;
  rocks.sort((a, b) => a - b);

  let rocksWithStartEnd = [0, ...rocks, distance];

  let start = 0;
  let end = distance;

  while (start <= end) {
    let mid = parseInt((start + end) / 2);

    if (checkPossibleMinDistance(mid, rocksWithStartEnd, n)) {
      start = mid + 1;
      answer = mid;
    } else {
      end = mid - 1;
    }
  }
  return answer;
}
