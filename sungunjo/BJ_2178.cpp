#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _node {
    int x;
    int y;
    
    _node(int _x, int _y) : x(_x), y(_y) {}
} Node;

Node d[4] = {
    Node(-1, 0),
    Node(0, 1),
    Node(1, 0),
    Node(0, -1)
};

int main() {
    int N, M;

    scanf ("%d %d", &N, &M);
    vector<vector<int> > map(N, vector<int>(M, 0));
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            int input;
            scanf("%d", &input);
            map[n][m] = input - 1;
        }
    }

    queue<Node> q;

    q.push(Node(0, 0));
    map[0][0] = 1;
    while (q.empty() == false) {
        Node now_pos = q.front(); q.pop();
        int now_cnt = map[now_pos.x][now_pos.y];

        if ((now_pos.x == N - 1) && (now_pos.y == M - 1)) {
            printf("%d\n", now_cnt);
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            Node next_pos = Node(now_pos.x + d[i].x, now_pos.y + d[i].y);
            int next_cnt = now_cnt + 1;

            if ((next_pos.x < 0) || (next_pos.y < 0) ||
                (next_pos.x >= N) || (next_pos.y >= M) ||
                (map[next_pos.x][next_pos.y] != 0)) {
                continue;
            }

            q.push(next_pos);
            map[next_pos.x][next_pos.y] = next_cnt;
        }
    }

    return -1;
}