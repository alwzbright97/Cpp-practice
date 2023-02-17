#include <iostream>

constexpr int MAX = 1000;
unsigned long long mod[MAX];

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;
  unsigned long long sum = 0, cnt = 0;

  unsigned int input;
  for (int i = 0; i < N; i++) {
    std::cin >> input;
    sum += input;
    mod[sum % M]++;
  }

  cnt += mod[0];
  for (int i = 0; i < M; i++) {
    cnt += mod[i] * (mod[i] - 1) / 2;
  }

  std::cout << cnt;

  return 0;
}