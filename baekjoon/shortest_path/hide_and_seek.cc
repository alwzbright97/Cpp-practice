#include <iostream>
#include <queue>
#include <vector>

constexpr int MAX = 100001;

int dist[MAX];

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::queue<int> q;

  int N, K;
  std::cin >> N >> K;

  std::fill(dist, dist + MAX, MAX);

  dist[N] = 0;
  q.push(N);

  while (!q.empty()) {
    int here = q.front();

    q.pop();

    if (here == K) {
      std::cout << dist[here];
      return 0;
    }

    if (here * 2 < MAX && dist[here * 2] > dist[here]) {
      q.push(here * 2);
      dist[here * 2] = dist[here];
    }

    if (here + 1 < MAX && dist[here + 1] > dist[here]) {
      q.push(here + 1);
      dist[here + 1] = dist[here] + 1;
    }
    if (here - 1 >= 0 && dist[here - 1] > dist[here]) {
      q.push(here - 1);
      dist[here - 1] = dist[here] + 1;
    }
  }

  return 0;
}