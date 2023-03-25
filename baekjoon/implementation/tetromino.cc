#include <iostream>
#define MAX 500

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int answer = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int depth, int count) {
  if (depth == 4) {
    if (answer < count)
      answer = count;
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
      if (!visited[ny][nx] && map[ny][nx]) {
        visited[ny][nx] = true;

        dfs(nx, ny, depth + 1, count + map[ny][nx]);

        visited[ny][nx] = false;
      }
    }
  }
  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      std::cin >> map[j][i];
    }
  }

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      visited[j][i] = true;
      dfs(i, j, 1, map[j][i]);
      visited[j][i] = false;

      if (j + 2 < N && i + 1 < M) {
        int count =
            map[j][i] + map[j + 1][i] + map[j + 1][i + 1] + map[j + 2][i];
        if (count > answer)
          answer = count;
      }

      if (j + 2 < N && i - 1 >= 0) {
        int count =
            map[j][i] + map[j + 1][i] + map[j + 1][i - 1] + map[j + 2][i];
        if (count > answer)
          answer = count;
      }

      if (j + 1 < N && i + 2 < M) {
        int count =
            map[j][i] + map[j][i + 1] + map[j + 1][i + 1] + map[j][i + 2];
        if (count > answer)
          answer = count;
      }

      if (j - 1 >= 0 && i + 2 < M) {
        int count =
            map[j][i] + map[j][i + 1] + map[j - 1][i + 1] + map[j][i + 2];
        if (count > answer)
          answer = count;
      }
    }
  }

  std::cout << answer;

  return 0;
}