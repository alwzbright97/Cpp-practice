#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> order;
std::queue<int> q;

void dfs(int n) {
  visited[n] = true;
  order.push_back(n);

  for (std::vector<int>::iterator iter = adj[n].begin(); iter < adj[n].end();
       iter++) {
    if (!visited[*iter]) {
      dfs(*iter);
    }
  }

  return;
}

void bfs(int n) {
  q.push(n);

  while (!q.empty()) {
    int here = q.front();
    q.pop();
    visited[here] = true;
    order.push_back(here);

    for (std::vector<int>::iterator iter = adj[here].begin();
         iter < adj[here].end(); iter++) {
      if (!visited[*iter]) {
        q.push(*iter);
        visited[*iter] = true;
      }
    }
  }

  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, M, V;
  std::cin >> N >> M >> V;

  adj.resize(N + 1);
  visited.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= N; i++) {
    std::sort(adj[i].begin(), adj[i].end());
  }

  // DFS
  dfs(V);
  for (std::vector<int>::iterator iter = order.begin(); iter < order.end();
       iter++) {
    std::cout << *iter << " ";
  }
  std::cout << "\n";

  // reset
  order.clear();
  std::fill(visited.begin(), visited.end(), false);

  // BFS
  bfs(V);
  for (std::vector<int>::iterator iter = order.begin(); iter < order.end();
       iter++) {
    std::cout << *iter << " ";
  }
  std::cout << "\n";

  return 0;
}