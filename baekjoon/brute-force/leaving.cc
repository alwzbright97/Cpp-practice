#include <iostream>

constexpr int MAX = 16;

int N;
int T[MAX], P[MAX];
int max_profit = 0;

void maxProfit(int n, int profit) {
  if (n == N + 1) {
    max_profit = std::max(profit, max_profit);
    return;
  }

  if (n + T[n] <= N + 1) {
    maxProfit(n + T[n], profit + P[n]);
  }
  maxProfit(n + 1, profit);

  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> T[i] >> P[i];
  }

  maxProfit(1, 0);

  std::cout << max_profit;

  return 0;
}