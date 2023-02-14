#include <algorithm>
#include <iostream>

constexpr int MAX = 10000;

unsigned int arr[MAX];

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, K;
  unsigned int maximum = 0;
  unsigned int answer = 0;

  std::cin >> N >> K;
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];

    if (maximum < arr[i]) {
      maximum = arr[i];
    }
  }

  unsigned int low = 1, high = maximum;

  while (low <= high) {
    unsigned int mid = (low + high) / 2;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
      cnt += arr[i] / mid;
    }

    if (cnt >= K) {
      low = mid + 1;
      answer = std::max(answer, mid);
    } else {
      high = mid - 1;
    }
  }

  std::cout << answer << "\n";

  return 0;
}