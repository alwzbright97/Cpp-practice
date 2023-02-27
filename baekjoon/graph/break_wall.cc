#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  std::vector<std::vector<bool>> arr(N, std::vector<bool>(M));
  std::vector<std::vector<std::vector<int>>> visited(
      N, std::vector<std::vector<int>>(M, std::vector<int>(2)));
  std::queue<std::tuple<int, int, int>> q;

  std::string str;

  for (int j = 0; j < N; j++) {
    std::cin >> str;
    for (int i = 0; i < M; i++) {
      arr[j][i] = str[i] - '0';
    }
  }

  q.push({0, 0, 1});
  visited[0][0][1] = 1;

  while (!q.empty()) {
    int x = std::get<0>(q.front());
    int y = std::get<1>(q.front());
    int block = std::get<2>(q.front());

    q.pop();

    if (x == M - 1 && y == N - 1) {
      std::cout << visited[y][x][block];
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
        if (arr[ny][nx] && block) {
          q.push({nx, ny, 0});
          visited[ny][nx][0] = visited[y][x][block] + 1;
        } else if (!arr[ny][nx] && !visited[ny][nx][block]) {
          q.push({nx, ny, block});
          visited[ny][nx][block] = visited[y][x][block] + 1;
        }
      }
    }
  }

  std::cout << -1;

  return 0;
}