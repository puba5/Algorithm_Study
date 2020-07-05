// 프로그래머스 폰켓몬

function solution(nums) {
  let pocketmonSet = new Set(nums);
  return Math.min(parseInt(nums.length / 2), pocketmonSet.size);
}
