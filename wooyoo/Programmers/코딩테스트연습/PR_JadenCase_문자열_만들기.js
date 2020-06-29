// 프로그래머스 JadenCase 문자열 만들기

function solution(s) {
  s = s.substr(0, 1).toUpperCase() + s.substr(1).toLowerCase();
  for (let i = 0; i < s.length - 1; i++) {
    if (s[i] == " ") {
      s = s.substr(0, i + 1) + s.substr(i + 1, 1).toUpperCase() + s.substr(i + 2);
    }
  }

  return s;
}
