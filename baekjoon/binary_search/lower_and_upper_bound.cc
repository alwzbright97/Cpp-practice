#include <algorithm>
#include <iostream>

constexpr int MAX = 200000;

int N, C;
unsigned int arr[MAX];

int lower_bound(int value) {
  int low = 0, high = N;
  int mid;
  while (low < high) {
    mid = (low + high) / 2;
    if (arr[mid] >= value) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return low;
}
int upper_bound(int value) {
  int low = 0, high = N - 1;
  int mid;
  while (low < high) {
    mid = (low + high) / 2;
    if (arr[mid] > value) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return low;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> N; // >> C;

  for (size_t i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + N);

  std::cout << lower_bound(4) << "\n" << upper_bound(4);

  return 0;
}
