#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int count = 0;

std::vector<std::vector<int>> adj;
std::queue<int> q;
std::vector<int> visited;
std::vector<bool> discovered;

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, M, R;
  std::cin >> N >> M >> R;

  adj.resize(N + 1);
  visited.resize(N + 1);
  discovered.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= N; i++) {
    std::sort(adj[i].begin(), adj[i].end());
  }

  // bfs
  q.push(R);
  discovered[R] = true;

  while (!q.empty()) {
    int here = q.front();
    q.pop();

    visited[here] = ++count;

    for (std::vector<int>::iterator iter = adj[here].begin();
         iter != adj[here].end(); iter++) {
      if (!discovered[*iter]) {
        q.push(*iter);
        discovered[*iter] = true;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    std::cout << visited[i] << "\n";
  }

  return 0;
}