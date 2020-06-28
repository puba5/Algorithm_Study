// 카카오 2018 블라인드 테스트
// 뉴스 클러스터링
// 문자열 처리 문제

function solution(str1, str2) {
  var answer = 0;
  // 두글자씩 끊은 문자열들을 담을 배열
  let subset1 = [];
  let subset2 = [];

  str1 = str1.toUpperCase();
  str2 = str2.toUpperCase();
  // 대문자 알파벳만 저장
  let alphabet = /[A-Z][A-Z]/;

  for (let i = 0; i < str1.length - 1; i++) {
    // 두 글자 모두 알파벳일 때만 저장
    if (str1.substr(i, 2).search(alphabet) == 0) {
      subset1.push(str1.substr(i, 2));
    }
  }

  for (let i = 0; i < str2.length - 1; i++) {
    // 두 글자 모두 알파벳일 때만 저장
    if (str2.substr(i, 2).search(alphabet) == 0) {
      subset2.push(str2.substr(i, 2));
    }
  }

  subset1.sort();
  subset2.sort();

  let index1 = 0;
  let index2 = 0;
  let totalLen = 0;
  let dupLen = 0;

  while (index1 < subset1.length && index2 < subset2.length) {
    if (subset1[index1] == subset2[index2]) {
      dupLen += 1;
      index1 += 1;
      index2 += 1;
    } else if (subset1[index1] > subset2[index2]) {
      index2 += 1;
    } else if (subset1[index1] < subset2[index2]) {
      index1 += 1;
    }
    totalLen += 1;
  }
  totalLen += subset1.length - index1 + subset2.length - index2;
  if (totalLen == 0) {
    return 65536;
  }
  answer = parseInt((dupLen / totalLen) * 65536);
  return answer;
}

// aa aa , aa aa aa
