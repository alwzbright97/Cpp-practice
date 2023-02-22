#include <algorithm>
#include <iostream>
#include <vector>

int count = 0;
std::vector<std::vector<int>> adj;
std::vector<int> visited;

void dfs(int n) {
  visited[n] = ++count;
  for (std::vector<int>::reverse_iterator riter = adj[n].rbegin();
       riter != adj[n].rend(); riter++) {
    if (visited[*riter] == 0) {
      dfs(*riter);
    }
  }
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, M, R;
  std::cin >> N >> M >> R;

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

  dfs(R);

  for (int i = 1; i <= N; i++) {
    std::cout << visited[i] << "\n";
  }

  return 0;
}