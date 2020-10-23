const addStrongerPlayersToLoser = (winner, loser, playerResultList) => {
  let resultOfLoser = playerResultList[loser];
  let resultOfWinner = playerResultList[winner];
  let isChanged = false;

  for (let player in resultOfWinner) {
    if (resultOfWinner[player] === false) {
      if (resultOfLoser[player] !== false) {
        resultOfLoser[player] = false;
        isChanged = true;
      }
    }
  }
  resultOfLoser[winner] = false;
  return isChanged;
};

const addWeakerPlayersToWinner = (winner, loser, playerResultList) => {
  let resultOfLoser = playerResultList[loser];
  let resultOfWinner = playerResultList[winner];
  let isChanged = false;

  for (let player in resultOfLoser) {
    if (resultOfLoser[player] === true) {
      if (resultOfWinner[player] !== true) {
        resultOfWinner[player] = true;
        isChanged = true;
      }
    }
  }
  resultOfWinner[loser] = true;
  return isChanged;
};

function solution(n, results) {
  let answer = 0;
  let playerResultList = [];

  for (let i = 0; i <= n; i++) {
    playerResultList.push({});
  }

  for (let resule of results) {
    let [winner, loser] = resule;
    addWeakerPlayersToWinner(winner, loser, playerResultList);
    addStrongerPlayersToLoser(winner, loser, playerResultList);
  }

  let isChanged = true;

  while (isChanged) {
    for (let resule of results) {
      let [winner, loser] = resule;
      isChanged =
        addWeakerPlayersToWinner(winner, loser, playerResultList) |
        addStrongerPlayersToLoser(winner, loser, playerResultList);
    }
  }

  for (let resule of results) {
    let [winner, loser] = resule;
    addWeakerPlayersToWinner(winner, loser, playerResultList);
    addStrongerPlayersToLoser(winner, loser, playerResultList);
  }

  for (let playerResult of playerResultList) {
    if (Object.keys(playerResult).length === n - 1) answer += 1;
  }

  return answer;
}
