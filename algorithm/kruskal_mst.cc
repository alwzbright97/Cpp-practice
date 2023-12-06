/*
Kruskal Algorithm


Input:
V E
E개의 줄에 걸쳐 간선에 대한 정보 입력
  A B cost

3 3
1 2 1
2 3 2
1 3 3

Output:
최소 스패닝 트리의 총 가중치 출력

5
*/
#define MAX 100001

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int node_A, node_B;
  int cost;

  bool operator<(Edge right) const {
    if (cost < right.cost) return true;
    if (cost > right.cost) return false;

    if (node_A < right.node_A) return true;
    if (node_A > right.node_A) return false;

    if (node_B < right.node_B) return true;
    if (node_B > right.node_B) return false;

    return false;
  }
};

int parent[MAX];

int V, E;
vector<Edge> vec_edge;

int Find(int x) {
  if (x == parent[x]) return x;

  return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  int parent_x = Find(x);
  int parent_y = Find(y);

  if (parent_x == parent_y) return;

  parent[parent_x] = parent_y;

  return;
}

int main() {
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int node_A, node_B, cost;
    cin >> node_A >> node_B >> cost;

    vec_edge.push_back({node_A, node_B, cost});
  }

  sort(vec_edge.begin(), vec_edge.end());

  for (int i = 1; i <= V; i++) {
    parent[i] = i;
  }

  long long sum = 0;
  for (int i = 0; i < vec_edge.size(); i++) {
    Edge cur = vec_edge[i];

    if (Find(cur.node_A) == Find(cur.node_B)) continue;

    Union(cur.node_A, cur.node_B);
    sum += cur.cost;
  }

  cout << sum;

  return 0;
}