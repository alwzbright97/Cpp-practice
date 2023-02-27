#include <climits>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int V, E, K;
  std::cin >> V >> E >> K;

  std::vector<std::vector<std::pair<int, int>>> adj(V + 1);
  std::vector<int> dist(V + 1, INT_MAX);
  std::priority_queue<std::pair<int, int>> pq;

  for (int i = 0; i < E; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  // std::cout << "Input Data\n";
  // for (int i = 1; i <= V + 1; i++) {
  //   std::cout << "adj[" << i << "]\n";
  //   for (int j = 0; j < adj[i].size(); j++) {
  //     std::cout << "{" << adj[i][j].first << ", " << adj[i][j].second <<
  //     "}\n";
  //   }
  // }

  dist[K] = 0;
  pq.push({0, K});

  while (!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();

    if (dist[here] < cost)
      continue;

    for (int i = 0; i < adj[here].size(); i++) {
      int there = adj[here][i].first;
      int next_dist = cost + adj[here][i].second;

      if (dist[there] > next_dist) {
        dist[there] = next_dist;
        pq.push({-next_dist, there});
      }
    }
  }

  for (int i = 1; i <= V; i++) {
    if (dist[i] == INT_MAX) {
      std::cout << "INF\n";
    } else {
      std::cout << dist[i] << "\n";
    }
  }

  return 0;
}