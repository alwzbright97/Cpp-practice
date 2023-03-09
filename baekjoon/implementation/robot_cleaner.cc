#include <iostream>
#include <vector>

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

std::vector<std::vector<int>> room;
std::vector<std::vector<bool>> clean;

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int count = 0;
  int N, M;
  int row, column, direction;

  std::cin >> N >> M;
  std::cin >> row >> column >> direction;
  room = std::vector<std::vector<int>>(N, std::vector<int>(M));
  clean = std::vector<std::vector<bool>>(N, std::vector<bool>(M));

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      std::cin >> room[j][i];
    }
  }
  int x = column, y = row;

  while (true) {
    if (!room[y][x] && !clean[y][x]) {
      count++;
      clean[y][x] = count;
    }

    bool is_clean = true;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (!room[ny][nx] && !clean[ny][nx]) {
        is_clean = false;
        break;
      }
    }

    if (is_clean) {
      int back_direction = (direction + 2) % 4;
      int nx = x + dx[back_direction];
      int ny = y + dy[back_direction];

      if (!room[ny][nx]) {
        x = nx, y = ny;
        continue;
      } else {
        std::cout << count << "\n";
        break;
      }
    } else {
      direction = (direction + 3) % 4;

      int nx = x + dx[direction];
      int ny = y + dy[direction];
      if (!room[ny][nx] && !clean[ny][nx]) {
        x = nx, y = ny;
        continue;
      }
    }
  }

  // for (int j = 0; j < N; j++) {
  //   for (int i = 0; i < M; i++) {
  //     std::printf("%2d ", clean[j][i]);
  //   }
  //   std::cout << "\n";
  // }

  return 0;
}