#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 51
#define endl '\n'

using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int answer = 0;

int N, L, R;

bool isOpen = true;
int n_people;
queue<pair<int, int>> q;
vector<pair<int, int>> v;

void printPopulation() {
  cout << "=====" << answer << "=====" << endl;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      cout << map[j][i] << ' ';
    }
    cout << endl;
  }
}

void resetVisited() {
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      visited[j][i] = false;
    }
  }
}

void movePopulation(int x, int y) {

  q.push({x, y});
  visited[y][x] = true;

  while (!q.empty()) {
    pair<int, int> current = q.front();
    int current_value = map[current.second][current.first];
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = current.first + dx[dir], ny = current.second + dy[dir];

      if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx])
        continue;

      int diff = abs(current_value - map[ny][nx]);

      if (diff > R || diff < L)
        continue;

      v.push_back({nx, ny});
      q.push({nx, ny});
      visited[ny][nx] = true;
      n_people += map[ny][nx];
    }
  }

  return;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> L >> R;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      cin >> map[j][i];
    }
  }

  while (isOpen) {
    isOpen = false;
    for (int j = 0; j < N; j++) {
      for (int i = 0; i < N; i++) {
        if (!visited[j][i]) {
          v.clear();
          v.push_back({i, j});
          n_people = map[j][i];
          movePopulation(i, j);
        }

        if (v.size() > 1) {
          isOpen = true;
          int value = n_people / v.size();

          for (int i = 0; i < v.size(); i++) {
            map[v[i].second][v[i].first] = value;
          }
        }
      }
    }

    resetVisited();

    // printPopulation();

    if (isOpen) {
      answer++;
    }
  }

  cout << answer << endl;

  return 0;
}