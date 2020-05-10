// 프로그래머즈 가장 먼 노드
// 그래프로 그린 후, bfs로 거리 탐색하면 된다.

function solution(n, edge) {
  var answer = 0;

  // 간선과 edge 연결 확인을 위한 그래프 생성
  var graph = [];
  for (let i = 0; i <= n; i++) {
    graph.push([]);
  }

  for (let e of edge) {
    graph[e[0]].push(e[1]);
    graph[e[1]].push(e[0]);
  }

  var node_dis = new Array();
  for (let i = 0; i <= n; i++) {
    node_dis[i] = -1;
  }

  // bfs를 위한 큐 생성
  var queue = [1];
  node_dis[1] = 0;

  var most_far_dis = 0;
  while (queue.length != 0) {
    let node = queue.shift();
    let distance = node_dis[node];

    for (let n of graph[node]) {
      if (node_dis[n] == -1) {
        queue.push(n);
        node_dis[n] = distance + 1;
        // 가장 먼 노드의 길이 저장
        most_far_dis = Math.max(most_far_dis, node_dis[n]);
      }
    }
  }

  for (let d of node_dis) {
    if (d === most_far_dis) answer++;
  }
  return answer;
}
