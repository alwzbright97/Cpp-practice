/*
Prim Algorithm

BFS처럼 하나의 점에서 점차 퍼져나가는 형태

시간 복잡도
E x logE = E x log V

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
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int next_node;
  int cost;

  bool operator<(Edge right) const {
    if (cost > right.cost) return true;
    if (cost < right.cost) return false;

    if (next_node > right.next_node) return true;
    if (next_node < right.next_node) return false;

    return false;
  }
};

int V, E;

vector<Edge> adj[MAX];
bool visited[MAX];

long long answer = 0;

int main(int argc, char** argv) {
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int node_A, node_B, cost;
    cin >> node_A >> node_B >> cost;
    adj[node_A].push_back({node_B, cost});
    adj[node_B].push_back({node_A, cost});
  }

  priority_queue<Edge> pq;

  int srt_node = 1;
  visited[srt_node] = 1;

  for (int i = 0; i < adj[srt_node].size(); i++) {
    Edge edge = adj[srt_node][i];
    pq.push(edge);
  }

  long long sum = 0;

  while (!pq.empty()) {
    Edge now = pq.top();
    int cur_node = now.next_node;
    int cur_cost = now.cost;

    pq.pop();

    if (visited[cur_node]) continue;

    visited[cur_node] = 1;
    sum += cur_cost;

    for (int i = 0; i < adj[cur_node].size(); i++) {
      Edge edge = adj[cur_node][i];

      pq.push(edge);
    }
  }

  cout << sum;

  return 0;
}