#include <iostream>
#include <queue>
#include <string>
#include <vector>
int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<bool>> arr(N, std::vector<bool>(M, false));
  std::vector<std::vector<int>> dist(N, std::vector<int>(M, 0));
  std::queue<std::pair<int, int>> q;
  std::string str;

  for (int i = 0; i < N; i++) {
    std::cin >> str;
    for (int j = 0; j < M; j++) {
      arr[i][j] = (str[j] - '0');
    }
  }

  q.push(std::make_pair(0, 0));
  arr[0][0] = false;
  dist[0][0] = 1;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    // up
    if (y - 1 >= 0 && arr[x][y - 1]) {
      q.push(std::make_pair(x, y - 1));
      arr[x][y - 1] = false;
      dist[x][y - 1] = dist[x][y] + 1;
    }
    // down
    if (y + 1 < M && arr[x][y + 1]) {
      q.push(std::make_pair(x, y + 1));
      arr[x][y + 1] = false;
      dist[x][y + 1] = dist[x][y] + 1;
    }
    // left
    if (x - 1 >= 0 && arr[x - 1][y]) {
      q.push(std::make_pair(x - 1, y));
      arr[x - 1][y] = false;
      dist[x - 1][y] = dist[x][y] + 1;
    }
    // right
    if (x + 1 < N && arr[x + 1][y]) {
      q.push(std::make_pair(x + 1, y));
      arr[x + 1][y] = false;
      dist[x + 1][y] = dist[x][y] + 1;
    }
  }

  // std::cout << "Input\n";
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     std::cout << arr[i][j];
  //   }
  //   std::cout << "\n";
  // }

  // std::cout << "Answer\n";
  std::cout << dist[N - 1][M - 1] << "\n";

  return 0;
}