#include <cstring>
#include <iostream>

#define MAX 999

int board[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void makeSnail(int N) {
  int x = N / 2, y = N / 2;

  board[y][x] = 1;

  int direction = 0, n = 1, num = 2;

  while (true) {
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < n; i++) {
        x = x + dx[direction];
        y = y + dy[direction];

        if (x < 0 || x >= N || y < 0 || y >= N)
          return;

        board[y][x] = num++;
      }
      direction = (direction + 1) % 4;
    }

    n++;
  }

  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  memset(board, 0, sizeof(board));

  int N, target, x, y;
  std::cin >> N >> target;

  makeSnail(N);

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      std::cout << board[j][i] << ' ';
      if (board[j][i] == target)
        y = j + 1, x = i + 1;
    }
    std::cout << '\n';
  }
  std::cout << y << ' ' << x;

  return 0;
}
