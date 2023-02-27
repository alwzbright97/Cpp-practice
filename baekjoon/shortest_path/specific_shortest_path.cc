#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

constexpr int MAX = 801;
constexpr int INF = INT_MAX;

int N, E;
std::vector<std::pair<int, int>> adj[MAX];
std::vector<int> dist(MAX, INF);

void dijkstra(int start) {
  std::fill(dist.begin(), dist.begin() + (N + 1), INF);

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int cost = pq.top().first;
    int here = pq.top().second;

    pq.pop();

    if (dist[here] < cost)
      continue;

    for (int i = 0; i < adj[here].size(); i++) {
      int there = adj[here][i].first;
      int next_dist = cost + adj[here][i].second;

      if (dist[there] > next_dist) {
        dist[there] = next_dist;
        pq.push({next_dist, there});
      }
    }
  }

  return;
}

int main() {
  std::cin >> N >> E;

  for (int i = 0; i < E; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  int path_1, path_2;

  int v1, v2;
  std::cin >> v1 >> v2;

  // From 1
  dijkstra(1);
  int dist_1_to_v1 = dist[v1];
  int dist_1_to_v2 = dist[v2];

  // From v1 to v2
  dijkstra(v1);
  int dist_v1_to_v2 = dist[v2];

  // From v1 to N
  int dist_v1_to_N = dist[N];

  // From v2 to N
  dijkstra(v2);
  int dist_v2_to_N = dist[N];

  if (dist_v1_to_v2 == INF) {
    std::cout << -1;
    return 0;
  }

  // 1 - v1 - v2 - N
  if (dist_1_to_v1 == INF || dist_v2_to_N == INF) {
    path_1 = INF;
  } else {
    path_1 = dist_1_to_v1 + dist_v1_to_v2 + dist_v2_to_N;
  }

  // 1 - v2 - v1 - N
  if (dist_1_to_v2 == INF || dist_v1_to_N == INF) {
    path_2 = INF;
  } else {
    path_2 = dist_1_to_v2 + dist_v1_to_v2 + dist_v1_to_N;
  }

  if (path_1 == INF && path_2 == INF) {
    std::cout << -1;
    return 0;
  }

  std::cout << std::min(path_1, path_2);
  return 0;
}