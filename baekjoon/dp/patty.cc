#include <iostream>

#define MAX 50

long long patty[MAX], bun[MAX], burger[MAX];

long long getNumPatty(int n, long long x) {
  if (n == 0) {
    return 1;
  }

  if (x == 1)
    return 0;
  if (x < burger[n - 1] + 1)
    return getNumPatty(n - 1, x - 1);

  if (x == burger[n - 1] + 1)
    return patty[n - 1];

  if (x == burger[n - 1] + 2)
    return patty[n - 1] + 1;

  if (x < burger[n - 1] * 2 + 2)
    return patty[n - 1] + 1 + getNumPatty(n - 1, x - burger[n - 1] - 2);

  return patty[n - 1] * 2 + 1;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N;
  long long X;

  patty[0] = 1;
  burger[0] = 1;

  for (int i = 1; i < MAX; i++) {
    patty[i] = patty[i - 1] * 2 + 1;
    bun[i] = bun[i - 1] * 2 + 2;
    burger[i] = patty[i] + bun[i];
  }

  std::cin >> N >> X;
  std::cout << getNumPatty(N, X);

  return 0;
}
