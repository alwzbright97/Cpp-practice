#include <algorithm>
#include <iostream>
#include <vector>

constexpr int MAX = 1000001;

std::vector<int> adj[MAX];
int visited[MAX];
int count = 0;
int N, M, R;

void dfs(int r) {
  count++;
  visited[r] = count;

  for (int i = 0; i < adj[r].size(); i++) {
    int next = adj[r][i];
    if (visited[next] == 0) {
      dfs(next);
    }
  }

  return;
}
int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M >> R;

  for (int i = 0; i < M; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < N; i++) {
    std::sort(adj[i].begin(), adj[i].end());
  }

  dfs(R);

  for (int i = 1; i <= N; i++) {
    std::cout << visited[i] << "\n";
  }

  return 0;
}