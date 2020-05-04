//2020_KAKAO_BLIND_RECRUITMENT_문자열_압축

function solution(s) {
  var sLen = s.length;
  var answer = sLen;

  // 몇 개씩 끊어 읽을 건지 비교
  for (var i = 1; i <= Number(sLen / 2); i++) {
    var str = 0;
    var shortLen = sLen;

    // 문자열 비교
    while (str < sLen) {
      // 몇개가 중복되는지
      var dup = 0;
      // 만약 끊어서 읽었을 때 같으면
      while (str + i + i <= sLen && s.substr(str, i) == s.substr(str + i, i)) {
        //console.log(s[str]);
        dup++;
        str += i;
      }
      str += i;

      // 중복된만큼 뺀 후 (숫자)를 더한다
      if (dup != 0) {
        // 숫자는 10의 자리, 100의 자리면 자리수가 바뀌므로, 문자열로 변환한 후 길이를 구한다
        shortLen -= dup * i - (dup + 1).toString().length;
      }
    }

    answer = Math.min(answer, shortLen);
  }

  return answer;
}

console.log(solution("aaaaaaaaaa"));
