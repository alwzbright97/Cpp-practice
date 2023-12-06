#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int N, M, K;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int map[10][10];
int fertilizer[10][10];
int add[10][10];
deque<int> tree[10][10];
queue<pair<int, int>> breed_q;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M >> K;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      cin >> fertilizer[j][i];
      map[j][i] = 5;
    }
  }

  for (int i = 0; i < M; i++) {
    int row, col, age;
    cin >> row >> col >> age;
    tree[row - 1][col - 1].push_back(age);
  }

  int num_tree = M;

  for (int k = 0; k < K; k++) {

    // spring & summer & winter
    for (int j = 0; j < N; j++) {
      for (int i = 0; i < N; i++) {

        sort(tree[j][i].begin(), tree[j][i].end());

        int q_size = tree[j][i].size();

        for (int t = 0; t < q_size; t++) {
          int age = tree[j][i].front();

          tree[j][i].pop_front();

          if (map[j][i] >= age) {
            map[j][i] -= age;
            tree[j][i].push_back(age + 1);

            if ((age + 1) % 5 == 0) {
              breed_q.push({i, j});
            }
          } else {
            add[j][i] += (age / 2);
            num_tree--;
          }
        }

        map[j][i] += (add[j][i] + fertilizer[j][i]);
        add[j][i] = 0;
      }
    }

    // autumn & winter
    while (!breed_q.empty()) {
      int x = breed_q.front().first;
      int y = breed_q.front().second;

      breed_q.pop();

      for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
          continue;

        tree[ny][nx].push_back(1);
        num_tree++;
      }
    }
  }

  cout << num_tree << endl;

  return 0;
}
