#include <iostream>
#include <queue>
#include <vector>

int T, M, N, K;

void bfs(std::vector<std::vector<bool>> &map, int x, int y, int &count) {
  count++;

  std::queue<std::pair<int, int>> q;

  q.push(std::make_pair(x, y));
  map[x][y] = false;
  // std::cout << "x: " << x << " y: " << y << "\n";

  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    // std::cout << "\tfalse - i: " << i << ", j: " << j
    //           << " - value: " << map[i][j] << "\n";
    q.pop();

    // up
    if (j - 1 >= 0 && map[i][j - 1]) {
      q.push(std::make_pair(i, j - 1));
      map[i][j - 1] = false;
    }
    // down
    if (j + 1 < N && map[i][j + 1]) {
      q.push(std::make_pair(i, j + 1));
      map[i][j + 1] = false;
    }
    // left
    if (i - 1 >= 0 && map[i - 1][j]) {
      q.push(std::make_pair(i - 1, j));
      map[i - 1][j] = false;
    }
    // right
    if (i + 1 < M && map[i + 1][j]) {
      q.push(std::make_pair(i + 1, j));
      map[i + 1][j] = false;
    }
  }

  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> T;

  std::vector<int> answer;

  while (T--) {
    std::cin >> M >> N >> K;
    int count = 0;
    std::vector<std::vector<bool>> map(M, std::vector<bool>(N, false));

    for (int i = 0; i < K; i++) {
      int x, y;
      std::cin >> x >> y;
      map[x][y] = true;
    }

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (map[i][j]) {
          bfs(map, i, j, count);
        }
      }
    }

    answer.push_back(count);
  }

  for (int i = 0; i < answer.size(); i++) {
    std::cout << answer[i] << "\n";
  }

  return 0;
}