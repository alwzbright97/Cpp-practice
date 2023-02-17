#include <algorithm>
#include <iostream>

constexpr int MAX = 501;
int sum[MAX], dp[MAX][MAX];

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);
  int T, K, input;
  std::cin >> T;

  while (T--) {
    std::cin >> K;
    for (int i = 1; i <= K; ++i) {
      std::cin >> input;
      sum[i] = sum[i - 1] + input;
    }

    for (int d = 1; d < K; d++) {
      for (int x = 1; x + d <= K; x++) {
        int y = x + d;
        dp[x][y] = INT_MAX;
        for (int m = x; m < y; m++) {
          dp[x][y] =
              std::min(dp[x][y], dp[x][m] + dp[m + 1][y] + sum[y] - sum[x - 1]);
        }
      }
    }

    printf("%d\n", dp[1][K]);
    /*
    for (int i = 0; i < K + 1; i++) {
      printf("sum[%d] = %d\n", i, sum[i]);
    }

    for (int i = 0; i <= K; i++) {
      for (int j = 0; j <= K; j++) {
        printf("dp[%d][%d] = %d\t", i, j, dp[i][j]);
      }
      printf("\n");
    }
    */
  }

  return 0;
}