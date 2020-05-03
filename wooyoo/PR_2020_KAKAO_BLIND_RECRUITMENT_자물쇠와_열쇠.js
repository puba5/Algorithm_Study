// 2020_KAKAO_BLIND_RECRUITMENT_자물쇠와_열쇠

function check(x, y, key, big_lock, lockSize) {
  for (var i = 0; i < key.length; i++) {
    for (var j = 0; j < key.length; j++) {
      big_lock[i + x][j + y] += key[i][j];
    }
  }
  //console.log(big_lock);
  for (var i = 0; i < lockSize; i++) {
    for (var j = 0; j < lockSize; j++) {
      if (big_lock[i + key.length - 1][j + key.length - 1] != 1) {
        return false;
      }
    }
  }
  return true;
}

function rotateArray(array) {
  var newArray = [];
  for (var i = 0; i < array.length; i++) {
    var newSmallArray = [];
    for (var j = 0; j < array.length; j++) {
      newSmallArray.push(0);
    }
    newArray.push(newSmallArray);
  }

  for (var i = 0; i < array.length; i++) {
    for (var j = 0; j < array.length; j++) {
      newArray[j][array.length - i - 1] = array[i][j];
    }
  }

  return newArray;
}

function solution(key, lock) {
  var answer = false;
  var big_lock = [];
  for (var i = 0; i < lock.length + 2 * key.length - 2; i++) {
    var small_lock = [];
    for (var j = 0; j < lock.length + 2 * key.length - 2; j++) {
      if (
        i < key.length - 1 ||
        j < key.length - 1 ||
        i > lock.length + key.length - 2 ||
        j > lock.length + key.length - 2
      ) {
        small_lock.push(0);
      } else {
        small_lock.push(lock[i - key.length + 1][j - key.length + 1]);
      }
    }
    // console.log(small_lock);
    big_lock.push(small_lock);
  }

  //키를 돌리기 위해 반복문 4번

  for (var k = 0; k < 4; k++) {
    key = rotateArray(key);
    //console.log(key);
    // 키를 다 꼽아본다
    for (var i = 0; i < lock.length + key.length - 1; i++) {
      for (var j = 0; j < lock.length + key.length - 1; j++) {
        var bigLock = JSON.parse(JSON.stringify(big_lock));
        if (check(i, j, key, bigLock, lock.length) == true) {
          return true;
        }
      }
    }
  }
  return answer;
}
