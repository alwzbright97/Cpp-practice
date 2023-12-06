/*
SWEA 2382 : 미생물 격리

가로 세로 N 정사각형

미생물 군집
  미생물 수
  이동방향 - 상하좌우

미생물 약품 셀에 도착
  군집 내 미생물의 절반이 죽고,
  이동방향이 반대
이동 후 두 개 이상의 군집이 한 셀에 모이는 경우
  이동방향은 가장 많은 군집의 이동방향

시간 제한
  최대 50개 테스트 케이스
  5 <= N <= 100
  군집 수 5 <= K <= 1000
  격리시간 1 <= M <= 1000
  최초 약품 X
  최초 둘 이상 X
  군집 내 미생물 10000 이하 정수
  동일한 경우 X
  군집 정보
    세로, 가로, 미생물 수, 이동 방향

50 X 1000 X 1000 = 50,000,000 (5천만) <= 5초
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

struct Colony {
  int y, x;
  int num;
  int direction;
  int max;
};

int dir_convert[5] = {0, 0, 2, 3, 1};
// 상우하좌
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// T : 테스트 케이스
int T;

// N : 방 크기 / M : 격리 시간 / K : 미생물 군집 수
int N, M, K;

//
int answer;

queue<Colony> q;
Colony MAP[101][101];

void input() {
  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int y, x, num, direction;
    cin >> y >> x >> num >> direction;
    q.push({y, x, num, dir_convert[direction], 0});
  }

  return;
}

void queueToMap() {
  while (!q.empty()) {
    Colony now = q.front();
    q.pop();

    int x = now.x;
    int y = now.y;

    int direction = now.direction;
    int num = now.num;

    int nx = x + dx[direction];
    int ny = y + dy[direction];

    MAP[ny][nx].num += num;

    if (MAP[ny][nx].max < num) {
      MAP[ny][nx].direction = direction;
      MAP[ny][nx].max = num;
    }
  }
}

void mapToQueue() {
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      if (MAP[j][i].num == 0) continue;

      if (j == 0 || i == 0 || j == N - 1 || i == N - 1) {
        MAP[j][i].direction = (MAP[j][i].direction + 2) % 4;
        MAP[j][i].num /= 2;
      }

      q.push({j, i, MAP[j][i].num, MAP[j][i].direction, 0});

      MAP[j][i].num = 0;
      MAP[j][i].max = 0;
      MAP[j][i].direction = 0;
    }
  }

  return;
}

void getTotalNum() {
  answer = 0;
  while (!q.empty()) {
    Colony now = q.front();
    // cout << "(" << now.y << "," << now.x << ") " << now.num << ", "
    // << now.direction << "\n";
    q.pop();
    answer += now.num;
  }
}

void solution() {
  for (int i = 0; i < M; i++) {
    queueToMap();
    mapToQueue();
  }
  getTotalNum();
}

int main(int argc, char** argv) {
  // freopen("input.txt", "r", stdin);

  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    input();
    solution();
    cout << "#" << test_case << " " << answer << "\n";
  }

  return 0;
}