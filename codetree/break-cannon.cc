/*
N x M 격자가 있고, 모든 위치에 포탑이 존재

포탑
    공격력
        줄거나 늘어날 수 있음
        0이하가 되면 파괴, 공격하지 않음
    최근 공격 턴

하나의 턴은 4가지 액션을 순서대로 수행, K번 반복

1. 공격자 선정
    부서지지 않은 포탑 중 *가장 약한 포탑*이 공격자로 선정
    N + M 만큼 공격력이 증가
    *가장 약한 포탑*
    1. 공격력이 가장 낮은 포탑
    2. 1의 포탑이 2개 이상, 가장 최근에 공격한 포탑
    3. 2의 포탑이 2개 이상, 행과 열의 합이 가장 큰 포탑
    4. 3의 포탑이 2개 이상, 열 값이 가장 큰 포탑

2. 공격자의 공격
    자신을 제외한 *가장 강한 포탑*을 공격
    *가장 강한 포탑*
    1. 공격력이 가장 높은 포탑
    2. 공격한지 가장 오래된 포탑
    3. 행과 열의 합이 가장 작은 포탑
    4. 열 값이 가장 작은 포탑

2-1. 레이저 공격
    레이저
    1. 레이저 상하좌우 4방향으로 이동
    2. 부서진 포탑이 있는 위치 X
    3. 가장자리면 반대편 위치로
    공격 대상 포탑까지 최단 경로로 공격
        최단 경로가 2개 이상이면 우, 하, 좌, 상 우선 순위대로 먼저 이동

    공격자의 공격력 만큼 피해

    공격 대상을 제외한 레이저 경로에 있는 포탑도 피격
    공격자의 공격력 절반만큼 피격

2-2. 포탄 공격
    공격 대상에게 포탄
    공격 대상은 공격자의 공격력 만큼 피해
    주위 8개의 방향에 있는 포탑도 피해, 공격력 절반

3. 포탑 부서짐

4. 포탑 정비
    부서지지 않은 포탑 중 공격과 무관했던 포탑 공격력 1씩 상승

K번 턴이 종료된 후 남아있는 포탑 중 가장 강한 포탑의 공격력

4 <= N, M <= 10
1 <= K <= 1,000
0 <= 공격력 <= 5000
*/
#define MAX 10

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

/*
포탑
    공격력
        줄거나 늘어날 수 있음
        0이하가 되면 파괴, 공격하지 않음
    최근 공격 턴
*/
struct Coord {
  int y, x;
};

struct Cannon {
  int y, x;
  int power;
  int recent;
};

using namespace std;

int MAP[MAX][MAX];
int visited[MAX][MAX];
int recent[MAX][MAX];

int N, M, K;
int answer;
int turn_idx;
int cannon_cnt;
Cannon attacker, attackee;

/*
1. 공격자 선정
    부서지지 않은 포탑 중 *가장 약한 포탑*이 공격자로 선정
    N + M 만큼 공격력이 증가
    *가장 약한 포탑*
    1. 공격력이 가장 낮은 포탑
    2. 1의 포탑이 2개 이상, 가장 최근에 공격한 포탑
    3. 2의 포탑이 2개 이상, 행과 열의 합이 가장 큰 포탑
    4. 3의 포탑이 2개 이상, 열 값이 가장 큰 포탑
*/
void selectAttacker() {
  attacker = {0, 0, 5001, 1001};

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      int current_power = MAP[j][i];
      int current_recent = recent[j][i];

      if (!current_power) continue;

      if (current_power > attacker.power) {
        continue;
      } else if (current_power < attacker.power) {
        attacker = {j, i, current_power, current_recent};
        continue;
      }

      if (current_recent < attacker.recent) {
        continue;
      } else if (current_recent > attacker.recent) {
        attacker = {j, i, current_power, current_recent};
      }

      if (j + i < attacker.y + attacker.x) {
        continue;
      } else if (j + i > attacker.y + attacker.x) {
        attacker = {j, i, current_power, current_recent};
        continue;
      }

      if (i < attacker.x) {
        continue;
      } else if (i > attacker.x) {
        attacker = {j, i, current_power, current_recent};
        continue;
      }
    }
  }

  attacker.power += N + M;
  MAP[attacker.y][attacker.x] += N + M;
  recent[attacker.y][attacker.x] = turn_idx;

  return;
}
/*
2. 공격자의 공격
    자신을 제외한 *가장 강한 포탑*을 공격
    *가장 강한 포탑*
    1. 공격력이 가장 높은 포탑
    2. 공격한지 가장 오래된 포탑
    3. 행과 열의 합이 가장 작은 포탑
    4. 열 값이 가장 작은 포탑
*/
void selectAttackee() {
  attackee = {N, M, 0, 0};

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      int current_power = MAP[j][i];
      int current_recent = recent[j][i];

      if (!current_power) continue;

      if (j == attacker.y && i == attacker.x) continue;

      if (current_power < attackee.power) {
        continue;
      } else if (current_power > attackee.power) {
        attackee = {j, i, current_power, current_recent};
        continue;
      }

      if (current_recent > attackee.recent) {
        continue;
      } else if (current_recent < attackee.recent) {
        attackee = {j, i, current_power, current_recent};
      }

      if (j + i > attackee.y + attackee.x) {
        continue;
      } else if (j + i < attackee.y + attackee.x) {
        attackee = {j, i, current_power, current_recent};
        continue;
      }

      if (i > attackee.x) {
        continue;
      } else if (i < attackee.x) {
        attackee = {j, i, current_power, current_recent};
        continue;
      }
    }
  }

  return;
}
/*
2-1. 레이저 공격
    레이저
    1. 레이저 상하좌우 4방향으로 이동
    2. 부서진 포탑이 있는 위치 X
    3. 가장자리면 반대편 위치로
    공격 대상 포탑까지 최단 경로로 공격
        최단 경로가 2개 이상이면 우, 하, 좌, 상 우선 순위대로 먼저 이동

    공격자의 공격력 만큼 피해

    공격 대상을 제외한 레이저 경로에 있는 포탑도 피격
    공격자의 공격력 절반만큼 피격

2-2. 포탄 공격
    공격 대상에게 포탄
    공격 대상은 공격자의 공격력 만큼 피해
    주위 8개의 방향에 있는 포탑도 피해, 공격력 절반
*/
void attackCannon() {
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      visited[j][i] = INT_MAX;
    }
  }

  queue<pair<Coord, vector<Coord>>> q;

  q.push({{attacker.y, attacker.x}, vector<Coord>()});
  visited[attacker.y][attacker.x] = 0;

  bool laser_available = false;
  vector<Coord> path;

  while (!q.empty()) {
    int cur_y = q.front().first.y;
    int cur_x = q.front().first.x;

    vector<Coord> cur_path = q.front().second;
    int next_dist = cur_path.size() + 1;

    q.pop();

    if (cur_y == attackee.y && cur_x == attackee.x) {
      path = cur_path;
      laser_available = true;
      break;
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
      int next_y = (cur_y + dy[i] + N) % N;
      int next_x = (cur_x + dx[i] + M) % M;

      if (MAP[next_y][next_x] == 0) continue;

      if (visited[next_y][next_x] <= next_dist) continue;

      visited[next_y][next_x] = next_dist;
      cur_path.push_back({cur_y, cur_x});
      q.push({{next_y, next_x}, cur_path});
      cur_path.pop_back();
    }
  }

  int half_power = attacker.power / 2;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      visited[j][i] = 0;
    }
  }

  visited[attackee.y][attackee.x] = 1;
  visited[attacker.y][attacker.x] = 1;

  if (laser_available) {
    for (int i = 1; i < path.size(); i++) {
      int path_y = path[i].y;
      int path_x = path[i].x;

      if (MAP[path_y][path_x] > half_power)
        MAP[path_y][path_x] -= half_power;
      else
        MAP[path_y][path_x] = 0;

      visited[path_y][path_x] = 1;
    }

  } else {
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

    for (int i = 0; i < 8; i++) {
      int around_y = (attackee.y + dy[i] + N) % N;
      int around_x = (attackee.x + dx[i] + M) % M;

      if (around_y == attacker.y && around_x == attacker.x) continue;
      if (!MAP[around_y][around_x]) continue;

      visited[around_y][around_x] = 1;

      if (MAP[around_y][around_x] > half_power)
        MAP[around_y][around_x] -= half_power;
      else
        MAP[around_y][around_x] = 0;
    }
  }

  if (attackee.power > attacker.power)
    MAP[attackee.y][attackee.x] -= attacker.power;
  else
    MAP[attackee.y][attackee.x] = 0;

  return;
}

/*
3. 포탑 부서짐
4. 포탑 정비
    부서지지 않은 포탑 중 공격과 무관했던 포탑 공격력 1씩 상승
*/
void repairCannon() {
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (!MAP[j][i] || visited[j][i]) continue;

      MAP[j][i] += 1;
    }
  }
}

void countCannon() {
  cannon_cnt = 0;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (MAP[j][i]) cannon_cnt++;
    }
  }
  return;
}

void input() {
  cin >> N >> M >> K;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      cin >> MAP[j][i];
    }
  }

  return;
}

void printMAP() {
  cout << "=====" << turn_idx << "=====\n";
  cout << "attacker(" << attacker.y << ", " << attacker.x << ")\n";
  cout << "attackee(" << attackee.y << ", " << attackee.x << ")\n";

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      cout << MAP[j][i] << " ";
    }
    cout << "\n";
  }

  return;
}
void solution() {
  for (turn_idx = 1; turn_idx <= K; turn_idx++) {
    selectAttacker();
    selectAttackee();
    attackCannon();
    repairCannon();
    countCannon();
    // printMAP();
    if (cannon_cnt <= 1) break;
  }

  answer = 0;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (MAP[j][i] > answer) answer = MAP[j][i];
    }
  }

  return;
}

int main(int argc, char **argv) {
  input();
  solution();

  cout << answer << "\n";

  return 0;
}