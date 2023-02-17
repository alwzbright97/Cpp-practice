#include <algorithm>
#include <climits>
#include <iostream>

constexpr int MAX = 502;

int arr[MAX];
int dp[MAX][MAX];

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);
  int N;
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i] >> arr[i + 1];
  }
  for (int d = 1; d <= N; d++) {
    for (int x = 0; x + d <= N; x++) {
      int y = x + d;
      dp[x][y] = INT_MAX;
      for (int m = x; m <= y; m++) {
        int value = dp[x][m] + dp[m + 1][y] + arr[x] * arr[m + 1] * arr[y + 1];
        dp[x][y] = std::min(dp[x][y], value);
        // printf("x: %d\ty: %d\tm: %d\tvalue: %d\n", x, y, m, value);
      }
    }
  }
  /*
    for (int i = 0; i < N; i++) {
      printf("arr[%d] = (%d, %d)\n", i, arr[i], arr[i + 1]);
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("dp[%d][%d] = %d\t", i, j, dp[i][j]);
      }
      printf("\n");
    }
  */
  printf("%d", dp[0][N - 1]);

  return 0;
}