// 누가봐도 DP 문제 

function solution(land) {
    var answer = 0;
    let before_ground = [0,0,0,0]
    let after_ground = [0,0,0,0]

    for(let i = 0; i < land.length; i++){
        before_ground = [...after_ground]

        for(let j=0;j<4;j++){
            let maxNum = 0;
            for(let k=0;k<4;k++){
                if(k!=j){
                    maxNum = Math.max(maxNum, before_ground[k])
                }
            }
            after_ground[j] = land[i][j] + maxNum
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    answer = Math.max(...after_ground)

    return answer;
}
