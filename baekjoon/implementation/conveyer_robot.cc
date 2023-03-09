#include <deque>
#include <iostream>

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, K;
  std::cin >> N >> K;
  int num = 1, count = 0;

  std::deque<std::pair<int, bool>> convey(2 * N);
  for (int i = 0; i < 2 * N; i++) {
    std::cin >> convey[i].first;
  }

  while (count != K) {
    // rotate
    convey.push_front(convey.back());
    convey.pop_back();
    convey[N - 1].second = false;

    // move
    for (int ptr = N - 2; ptr >= 0; ptr--) {
      if (convey[ptr].second && !convey[ptr + 1].second &&
          convey[ptr + 1].first) {
        convey[ptr].second = false;
        convey[ptr + 1].first--;
        if (!convey[ptr + 1].first)
          count++;
        convey[ptr + 1].second = true;

        convey[N - 1].second = false;
      }
    }

    // put
    if (!convey[0].second && convey[0].first) {
      convey[0].second = true;
      convey[0].first--;
      if (!convey[0].first)
        count++;
    }

    if (count >= K) {
      std::cout << num;
      break;
    }
    num++;
  }

  return 0;
}