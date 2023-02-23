#include <iostream>
#include <queue>
#include <vector>

constexpr int MAX = 100001;

bool visited[MAX];

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, K;
  std::cin >> N >> K;
  std::queue<std::pair<int, int>> q;

  // pair(position, time)
  q.push(std::make_pair(N, 0));

  while (!q.empty()) {
    int pos = q.front().first;
    int sec = q.front().second;
    q.pop();

    if (pos == K) {
      std::cout << sec << "\n";
      break;
    }

    if ((pos - 1 >= 0) && !visited[pos - 1]) {
      q.push(std::make_pair(pos - 1, sec + 1));
      visited[pos - 1] = true;
    }
    if ((pos + 1 < MAX) && !visited[pos + 1]) {
      q.push(std::make_pair(pos + 1, sec + 1));
      visited[pos + 1] = true;
    }
    if ((pos * 2 < MAX) && !visited[pos * 2]) {
      q.push(std::make_pair(pos * 2, sec + 1));
      visited[pos * 2] = true;
    }
  }
  return 0;
}