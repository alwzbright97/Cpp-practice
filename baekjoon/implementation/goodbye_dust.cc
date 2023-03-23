#include <iostream>
#include <vector>

int total = 2;
std::vector<std::vector<int>> map;

int high, low;
int R, C, T;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void diffusion() {
  std::vector<std::vector<int>> new_map(R, std::vector<int>(C));

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (map[y][x] > 4) {
        int moved_air = map[y][x] / 5;
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k], ny = y + dy[k];
          if (nx >= 0 && nx < C && ny >= 0 && ny < R && map[ny][nx] != -1) {
            new_map[ny][nx] += moved_air;
            map[y][x] -= moved_air;
          }
        }
      }
      new_map[y][x] += map[y][x];
    }
  }

  map = new_map;
}

void aircleaner() {
  map[high][0] = 0;
  map[low][0] = 0;

  total -= map[high - 1][0];
  total -= map[low + 1][0];
  int i, j;
  // upper side
  // left
  for (j = high - 1; j > 0; j--) {
    map[j][0] = map[j - 1][0];
  }
  // top
  for (i = 0; i < C - 1; i++) {
    map[0][i] = map[0][i + 1];
  }
  // right
  for (j = 0; j < high; j++) {
    map[j][C - 1] = map[j + 1][C - 1];
  }
  // bottom
  for (i = C - 1; i > 0; i--) {
    map[high][i] = map[high][i - 1];
  }

  // lower side
  // left
  for (j = low + 1; j < R - 1; j++) {
    map[j][0] = map[j + 1][0];
  }
  // top
  for (i = 0; i < C - 1; i++) {
    map[R - 1][i] = map[R - 1][i + 1];
  }
  // right
  for (j = R - 1; j > low; j--) {
    map[j][C - 1] = map[j - 1][C - 1];
  }
  // bottom
  for (i = C - 1; i > 0; i--) {
    map[low][i] = map[low][i - 1];
  }

  map[high][0] = -1;
  map[low][0] = -1;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> R >> C >> T;

  map = std::vector<std::vector<int>>(R, std::vector<int>(C));

  for (int j = 0; j < R; j++) {
    for (int i = 0; i < C; i++) {
      std::cin >> map[j][i];

      if (map[j][i] == -1) {
        if (high)
          low = j;
        else
          high = j;
      }

      total += map[j][i];
    }
  }

  while (T--) {
    diffusion();
    aircleaner();

    // std::cout << "T: " << T << "\n";
    // for (int j = 0; j < R; j++) {
    //   for (int i = 0; i < C; i++) {
    //     std::printf("%2d ", map[j][i]);
    //   }
    //   std::cout << "\n";
    // }
  }

  std::cout << total << "\n";

  return 0;
}