// 1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
// 2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
// 3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

// 객체 양식
// const albumInformation = {
//     classic: {
//         count: 10,
//         songList : [[playCount, songId],]
//     }
// }

const getAlbumInformation = (genres, plays) => {
  const albumInformation = {};
  for (let songId = 0; songId < genres.length; songId++) {
    let genre = genres[songId];
    let play = plays[songId];

    if (!albumInformation[genre]) {
      albumInformation[genre] = {
        count: play,
        songList: [[play, songId]],
      };
      continue;
    }
    albumInformation[genre].count += play;
    albumInformation[genre].songList.push([play, songId]);
  }
  return albumInformation;
};

const getBestSong = (album) => {
  album.songList.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : b[0] - a[0]));

  if (album.songList.length < 2) return [album.songList[0][1]];
  return [album.songList[0][1], album.songList[1][1]];
};

function solution(genres, plays) {
  var answer = [];
  const albumInformation = getAlbumInformation(genres, plays);
  let albumList = [];
  for (let album in albumInformation) {
    albumList.push([albumInformation[album].count, album]);
  }

  albumList.sort((a, b) => b[0] - a[0]);

  for (let album of albumList) {
    let albumName = album[1];

    answer = [...answer, ...getBestSong(albumInformation[albumName])];
  }
  return answer;
}
