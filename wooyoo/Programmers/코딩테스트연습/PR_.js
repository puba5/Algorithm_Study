// 간단한 문제
// k+2개 중 제일 큰 수 2개만 남긴다

function solution(number, k) {
  let num_list = [...number];
  let cnt = k;

  for (let j = 0; j < num_list.length - 1; j++) {
    if (num_list[j] < num_list[j + 1]) {
      cnt--;
      num_list.splice(j, 1);

      if (j == 0) {
        j--;
      } else {
        j -= 2;
      }

      if (cnt == 0) {
        break;
      }
    }
  }
  while (cnt--) {
    num_list.splice(-1);
  }
  return num_list.join("");
}
