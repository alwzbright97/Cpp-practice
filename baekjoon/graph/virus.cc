#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<bool> visited;
int count = -1;

void dfs(int n) {
  visited[n] = true;
  count++;

  for (std::vector<int>::iterator iter = adj[n].begin(); iter < adj[n].end();
       iter++) {
    if (!visited[*iter]) {
      dfs(*iter);
    }
  }

  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, M;
  std::cin >> N >> M;

  adj.resize(N + 1);
  visited.resize(N + 1);

  for (int i = 0; i < M; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  std::cout << count << "\n";

  return 0;
}