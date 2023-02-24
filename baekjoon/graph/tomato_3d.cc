#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int M, N, H;
  std::cin >> M >> N >> H;

  std::vector<std::vector<std::vector<int>>> arr(
      H, std::vector<std::vector<int>>(N, std::vector<int>(M)));
  std::queue<std::tuple<int, int, int>> q;

  for (int k = 0; k < H; k++) {
    for (int j = 0; j < N; j++) {
      for (int i = 0; i < M; i++) {
        std::cin >> arr[k][j][i];

        if (arr[k][j][i] == 1) {
          q.push({i, j, k});
        }
      }
    }
  }

  while (!q.empty()) {
    int x = std::get<0>(q.front());
    int y = std::get<1>(q.front());
    int z = std::get<2>(q.front());

    q.pop();

    for (int i = 0; i < 6; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int nz = z + dz[i];

      if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H) {
        if (!arr[nz][ny][nx]) {
          arr[nz][ny][nx] = arr[z][y][x] + 1;
          q.push({nx, ny, nz});
        }
      }
    }
  }

  int max = 1;

  for (int k = 0; k < H; k++) {
    for (int j = 0; j < N; j++) {
      for (int i = 0; i < M; i++) {
        if (arr[k][j][i] == 0) {
          std::cout << -1;
          return 0;
        }
        max = std::max(arr[k][j][i], max);
      }
    }
  }

  std::cout << max - 1;

  return 0;
}