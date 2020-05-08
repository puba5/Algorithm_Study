// 2019 카카오 개발자 겨울 인턴십
// 불량 사용자
// 배열의 크기는 최대 8
// 원소 길이는 최대 8
// 따라서 그냥 모든 경우의 수 해보면 될 것 같다.

function banCheck(user_id, banned_id, banned_id_str_index, bannedList, answerList) {
  //console("F");
  // 밴 되는지 확인, 완전탐색을 위한 재귀함수

  // 만약 모든 밴을 봤다면 끝낸다.
  if (bannedList.length === banned_id.length) {
    bannedList.sort();
    //console.log(bannedList);
    var tmpArray = JSON.parse(JSON.stringify(bannedList));
    console.log(bannedList.equals(tmpArray));
    console.log(tmpArray);
    if (answerList.indexOf(tmpArray) == -1) {
      answerList.push(tmpArray);
    }
    return;
  }
  if (banned_id_str_index >= banned_id.length) {
    return;
  }
  // 현재 찾는 정지 유저
  let banned = banned_id[banned_id_str_index];
  // 정지 유저와 일치하는 유저를 찾는다.
  for (var user of user_id) {
    // 이 유저는 정지 당하지 않았고
    //
    if (banned.length === user.length && bannedList.indexOf(banned) == -1) {
      var same = 1;

      for (var cmp = 0; cmp < banned.length; cmp++) {
        if (banned[cmp] != "*" && banned[cmp] != user[cmp]) {
          same = 0;
        }
      }
      if (same) {
        bannedList.push(user);
        banCheck(user_id, banned_id, banned_id_str_index + 1, bannedList, bannedList);
        bannedList.pop();
      }
    }
  }
}

function solution(user_id, banned_id) {
  var answer = 0;
  var list = [];
  var answerList = [];
  banCheck(user_id, banned_id, 0, list, answerList);
  console.log("answer is");
  console.log(answerList);
  return answer;
}
