#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M;

int map[50][50];
int visited[50][50];

int num_virus = 0, num_empty = 0;
vector<pair<int, int>> virus_info;
int activate[10];
int answer = INT_MAX;

void BFS() {

  int num_current_empty = 0;
  int time = 0;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      visited[j][i] = -1;
    }
  }

  queue<pair<int, int>> q;

  for (int i = 0; i < M; i++) {
    int x = virus_info[activate[i]].first;
    int y = virus_info[activate[i]].second;

    q.push({x, y});
    visited[y][x] = 0;
  }

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N)
        continue;

      if (map[ny][nx] == 1 || visited[ny][nx] != -1)
        continue;

      q.push({nx, ny});
      visited[ny][nx] = visited[y][x] + 1;

      if (map[ny][nx] == 0) {
        num_current_empty++;
        time = visited[ny][nx];
      }
    }
  }

  if (num_empty == num_current_empty) {
    if (answer > time) {
      answer = time;
    }
  }

  return;
}

void selectVirus(int depth, int pointer) {
  if (pointer == num_virus + 1)
    return;

  if (depth == M) {
    BFS();

    return;
  }

  activate[depth] = pointer;
  selectVirus(depth + 1, pointer + 1);
  selectVirus(depth, pointer + 1);

  return;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      cin >> map[j][i];

      if (map[j][i] == 0) {
        num_empty++;
      } else if (map[j][i] == 2) {
        virus_info.push_back({i, j});
        num_virus++;
      }
    }
  }

  selectVirus(0, 0);

  if (answer == INT_MAX)
    answer = -1;

  cout << answer << endl;

  return 0;
}