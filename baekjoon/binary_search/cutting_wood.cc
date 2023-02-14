#include <algorithm>
#include <iostream>

constexpr unsigned int MAX = 1000000;
unsigned int arr[MAX];

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  unsigned int answer = 0;

  unsigned int N, M;

  std::cin >> N >> M;

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + N);

  unsigned int low = 0, high = arr[N - 1], mid;
  int value;
  unsigned long long count;

  while (low <= high) {
    mid = (low + high) / 2;

    // std::cout << low << " | " << mid << " | " << high << "\n";

    count = 0;

    for (int i = 0; i < N; i++) {
      value = arr[i] - mid;
      count += (value > 0) ? value : 0;
    }

    // std::cout << ">>>" << count << "\n";

    if (count >= M) {
      low = mid + 1;
      answer = std::max(answer, mid);
    } else {
      high = mid - 1;
    }
  }

  std::cout << answer << "\n";

  return 0;
}