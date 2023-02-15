#include <algorithm>
#include <iostream>

constexpr int MAX = 200000;

int N, C;
int arr[MAX];

bool check(int dist) {

  int current = 0;
  int low, high, mid;
  int value;

  for (int i = 0; i < C - 1; i++) {
    low = current + 1;
    high = N - 1;

    while (low < high) {
      mid = (low + high) / 2;
      value = arr[mid] - arr[current];

      if (value >= dist) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    if (arr[low] - arr[current] >= dist) {
      current = low;
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> C;

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + N);

  int low, mid, high;
  low = 1;
  high = arr[N - 1] - arr[0];
  while (low <= high) {
    mid = (low + high) / 2;

    if (check(mid)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  std::cout << low - 1;
}
