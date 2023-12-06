#include <iostream>
#include <queue>

using namespace std;

struct Cell {
  // 원본 생명력
  int origin_life;
  // 생명력
  int life;
  // 상태값 (0: 죽은 상태, 1: 활성 상태, 2: 비활성 상태)
  int state;
  // 좌표값
  int y, x;

  bool operator<(Cell right) const {
    // 수명이 클 수록 우선 순위가 높다.
    if (origin_life < right.origin_life)
      return true;

    if (origin_life < right.origin_life)
      return false;

    // 선택의 영역(디버깅 할 때 편하게 보기 위해서)
    // -> 좌표값이 앞에 나올수록 우선 순위가 높다.
    if (y > right.y)
      return true;
    if (y < right.y)
      return false;

    if (x > right.x)
      return true;
    if (x < right.x)
      return false;

    return false;
  }
};

int N, M, K;
int MAP[651][651];
int visited[651][651];
priority_queue<Cell> pq;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 1시간에 해당하는 것
void bfs() {
  priority_queue<Cell> tmp_pq;

  while (!pq.empty()) {
    tmp_pq.push(pq.top());
    pq.pop();
  }

  while (!tmp_pq.empty()) {
    Cell now = tmp_pq.top();
    tmp_pq.pop();
    // 상태값 확인

    int new_life = now.life - 1;
    if (now.state == 2) {
      // 비활성 -> life--
      // life가 0 이면 활성 상태로 변경
      if (new_life > 0) {
        // 원본, 생명력, 상태값, y, x
        pq.push({now.origin_life, new_life, now.state, now.y, now.x});
      } else {
        pq.push({now.origin_life, now.origin_life, 1, now.y, now.x});
      }
    } else {
      // 활성 -> life--
      // life가 0보다 크면 활성 상태로 유지 / 번식
      if (new_life > 0) {
        pq.push({now.origin_life, new_life, now.state, now.y, now.x});
      } else {

        for (int i = 0; i < 4; i++) {
          int new_y = now.y + dy[i];
          int new_x = now.x + dx[i];

          if (new_y < 0 || new_y > 650)
            continue;
          if (new_x < 0 || new_x > 650)
            continue;
          if (visited[new_y][new_x])
            continue;

          pq.push({now.origin_life, new_life, 2, now.y, now.x});
        }
      }
    }
  }
}

int main() {
  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    // 초기화
    for (int j = 0; j < 650; j++) {
      for (int i = 0; i < 650; i++) {
        visited[j][i] = 0;
      }
    }
    while (!pq.empty())
      pq.pop();

    // 입력
    cin >> N >> M >> K;

    for (int j = 300; j < 300 + N; j++) {
      for (int i = 300; i < 300 + M; i++) {
        cin >> MAP[j][i];
        // 최초의 세포 상태
        if (MAP[j][i]) {
          pq.push({MAP[j][i], MAP[j][i], 2, j, i});
          visited[j][i] = 1;
        }
      }
    }

    // K 시간 만큼 시간을 진행
    for (int i = 0; i < K; i++) {
      bfs();
    }

    cout << "#" << tc << " " << pq.size() << "\n";
  }

  return 0;
}