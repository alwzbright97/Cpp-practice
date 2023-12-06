/*
SWEA 1953 : 탈주범 검거


7종류의 구조물

1 : 상하좌우
2 : 상하
3 : 좌우
4 : 상우
5 : 하우
6 : 하좌
7 : 상좌

시간 제한
  최대 50 TC - 1초
  세로 N, 가로 M (5 <= N, M, <= 50)
  세로 R <- (0 <= R <= N - 1), 가로 (0 <= C <= M - 1)
  탈출 소요 시간 L, (1 <= L <= 20)

지도 입력
숫자 1 ~ 7 해당 위치의 터널 구조물 타입을 의미
숫자 0은 터널이 없는 장소

*/
#include <iostream>
#include <queue>

using namespace std;

struct Coord {
  int y, x;
};

int T;
int N, M;
int R, C, L;
int answer;

// 상 하 좌 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int ternel[8][4] = {
    {0, 0, 0, 0},  // 0번
    {1, 1, 1, 1},  // 1번 상하좌우
    {1, 1, 0, 0},  // 2번 상하
    {0, 0, 1, 1},  // 3번 좌우
    {1, 0, 0, 1},  // 4번 상우
    {0, 1, 0, 1},  // 5번 하우
    {0, 1, 1, 0},  // 6번 하좌
    {1, 0, 1, 0}   // 7번 상좌
};

int MAP[51][51];
int visited[51][51];

void input() {
  cin >> N >> M >> R >> C >> L;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      cin >> MAP[j][i];

      visited[j][i] = 0;
    }
  }
}

void solution() {
  answer = 0;
  queue<Coord> q;

  q.push({R, C});
  visited[R][C] = 1;

  while (!q.empty()) {
    Coord now = q.front();
    int y = now.y;
    int x = now.x;

    int c_ternel = MAP[y][x];

    answer++;
    q.pop();

    // 시간이 1부터 시작하니
    // 현재 방문한 점이 L시간보다 더 지난 경우
    // 더 진행하지 않는다.
    if (visited[y][x] >= L) continue;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

      if (visited[ny][nx]) continue;

      if (!ternel[c_ternel][i]) continue;

      int n_ternel = MAP[ny][nx];

      // 현재 방향이 상,좌일 때, 다음 진행 터널이 하,우가 뚫려있지 않은 경우
      if (i % 2 == 0 && !ternel[n_ternel][i + 1]) continue;

      // 현재 방향이 하,우일 때, 다음 진행 터널이 상,좌가 뚫려있지 않은 경우
      if (i % 2 == 1 && !ternel[n_ternel][i - 1]) continue;

      q.push({ny, nx});
      visited[ny][nx] = visited[y][x] + 1;
    }
  }

  return;
}

void output() {
  cout << "output\n";
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      cout << visited[j][i] << " ";
    }
    cout << "\n";
  }
}

int main() {
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    input();
    solution();
    // output();
    cout << "#" << test_case << " " << answer << "\n";
  }

  return 0;
}