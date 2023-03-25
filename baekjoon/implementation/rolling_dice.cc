#include <iostream>

constexpr int MAX = 20;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dice[6];
int map[MAX][MAX];
int M, N, x, y, K;

void rollingDice(int direction) {
  int temp = dice[5];

  int nx = x + dx[direction - 1];
  int ny = y + dy[direction - 1];

  if (nx < 0 || nx >= M || ny < 0 || ny >= N)
    return;

  x = nx, y = ny;

  if (direction == 1) {
    dice[5] = dice[4];
    dice[4] = dice[2];
    dice[2] = dice[1];
    dice[1] = temp;
  } else if (direction == 2) {
    dice[5] = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[4];
    dice[4] = temp;
  } else if (direction == 3) {
    dice[5] = dice[3];
    dice[3] = dice[2];
    dice[2] = dice[0];
    dice[0] = temp;
  } else {
    dice[5] = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[3];
    dice[3] = temp;
  }

  if (!map[y][x]) {
    map[y][x] = dice[5];
  } else {
    dice[5] = map[y][x];
    map[y][x] = 0;
  }

  std::cout << dice[2] << "\n";

  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  // std::memset(dice, 0, 4 * 3 * 2);
  // std::memset(map, 0, 4 * MAX * MAX);

  std::cin >> N >> M >> y >> x >> K;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      std::cin >> map[j][i];
    }
  }

  int direction;

  while (K--) {
    std::cin >> direction;
    rollingDice(direction);
  }

  return 0;
}