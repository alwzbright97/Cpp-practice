#include <iostream>

constexpr int MAX = 15;
int N, count = 0;
int chessboard[MAX];

bool isOkay(int n) {
  for (int i = 0; i < n; i++) {
    if (chessboard[i] == chessboard[n] ||
        std::abs(chessboard[n] - chessboard[i]) == n - i)
      return false;
  }
  return true;
}

void nQueen(int n) {
  if (n == N) {
    count++;
    return;
  }

  for (int i = 0; i < N; i++) {
    chessboard[n] = i;
    if (isOkay(n)) {
      nQueen(n + 1);
    }
  }

  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  nQueen(0);
  std::cout << count;

  return 0;
}