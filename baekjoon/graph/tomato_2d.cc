#include <iostream>
#include <queue>
#include <vector>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int M, N;
  std::cin >> M >> N;
  std::vector<std::vector<int>> arr(N, std::vector<int>(M));
  std::queue<std::pair<int, int>> q;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      std::cin >> arr[j][i];

      if (arr[j][i] == 1) {
        q.push(std::make_pair(i, j));
      }
    }
  }

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
        if (arr[ny][nx] == 0) {
          arr[ny][nx] = arr[y][x] + 1;
          q.push(std::make_pair(nx, ny));
        }
      }
    }
  }

  // std::cout << "Result\n";
  // for (int j = 0; j < N; j++) {
  //   for (int i = 0; i < M; i++) {
  //     std::cout << arr[j][i] << " ";
  //   }
  //   std::cout << "\n";
  // }

  int max = 1;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (arr[j][i] == 0) {
        std::cout << -1 << "\n";
        return 0;
      }
      max = std::max(arr[j][i], max);
    }
  }

  std::cout << max - 1 << "\n";

  return 0;
}