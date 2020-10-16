#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, M, K;
int map[15][15];
int A[15][15];
vector<int> tree[15][15];
pair<int, int> d[8];

void spring() {
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      if (!tree[r][c].empty()) {
        vector<int>::iterator iter;
        for (iter = tree[r][c].begin(); iter != tree[r][c].end(); iter++) {
          if (map[r][c] >= *iter) {
            map[r][c] -= *iter;
            (*iter)++;
          } else {
            (*iter) *= -1;
          }
        }
      }
    }
  }
}

void summer() {
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      if (!tree[r][c].empty()) {
        vector<int>::iterator iter;
        for (iter = tree[r][c].begin(); iter != tree[r][c].end();) {
          if (*iter < 0) {
            map[r][c] -= (*iter) / 2;
            iter = tree[r][c].erase(iter);
          } else {
            iter++;
          }
        }
      }
    }
  }
}

void fall() {
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      if (!tree[r][c].empty()) {
        vector<int>::iterator iter;
        for (iter = tree[r][c].begin(); iter != tree[r][c].end(); iter++) {
          if (*iter % 5 == 0) {
            for (int i = 0; i < 8; i++) {
              int nr = r + d[i].first;
              int nc = c + d[i].second;
              if (0 < nr && nr <= N && 0 < nc && nc <= N) {
                tree[nr][nc].insert(tree[nr][nc].begin(), 1);
              }
            }
          }
        }
      }
    }
  }
}

void winter() {
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      map[r][c] += A[r][c];
    }
  }
}


int main() {
  d[0] = make_pair(-1, -1);
  d[1] = make_pair(-1, 0);
  d[2] = make_pair(-1, 1);
  d[3] = make_pair(0, -1);
  d[4] = make_pair(0, 1);
  d[5] = make_pair(1, -1);
  d[6] = make_pair(1, 0);
  d[7] = make_pair(1, 1);

  cin >> N >> M >> K;
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      cin >> A[r][c];
      map[r][c] = 5; 
    }
  }
  for (int m = 0; m < M; m++) {
    int x, y, z;
    cin >> x >> y >> z;

    tree[x][y].push_back(z);
  }
  
  for (int k = 0; k < K; k++) {
    spring();
    summer();
    fall();
    winter();
  }

  int ans = 0;
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      if (!tree[r][c].empty()) {
        ans += tree[r][c].size();
      }
    }
  }

  cout << ans << endl;

  return 0;
}
