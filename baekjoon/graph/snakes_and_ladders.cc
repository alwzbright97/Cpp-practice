#include <iostream>
#include <queue>
#include <vector>

constexpr int MAX = 101;

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;

  std::vector<int> arr(MAX, 0);
  std::vector<bool> visited(MAX, false);
  std::queue<std::pair<int, int>> q;

  for (int i = 0; i < N + M; i++) {
    int u, v;
    std::cin >> u >> v;
    arr[u] = v;
  }

  visited[1] = true;
  q.push({1, 0});

  while (!q.empty()) {
    int pos = q.front().first;
    int turn = q.front().second;

    // std::cout << "turn: " << turn << " pos: " << pos << "\n";

    q.pop();

    if (pos == 100) {
      std::cout << turn;
      return 0;
    }

    if (arr[pos] != 0) {
      visited[pos] = true;
      pos = arr[pos];
    }

    for (int i = 1; i <= 6; i++) {
      int next = pos + i;
      if ((next <= 100) && (!visited[next])) {
        visited[next] = true;
        q.push({next, turn + 1});
      }
    }
  }

  return 0;
}