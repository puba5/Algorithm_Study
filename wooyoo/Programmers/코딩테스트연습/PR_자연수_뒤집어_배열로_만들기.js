// 프로그래머스 자연수 뒤집어 배열로 만들기

function solution(n) {
  var answer = [];
  let a = [...String(n)];
  a = a.reverse();

  // while(1){
  //     if(a[0]=='0'){
  //         a.shift();
  //     }else{
  //         break;
  //     }
  // }
  for (let i = 0; i < a.length; i++) {
    a[i] = Number(a[i]);
  }
  return a;
}
