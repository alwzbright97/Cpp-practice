/*
싸움땅

N x N 격자

격자
  무기
  플레이어
    초기 무기들이 없는 빈 격자에 위치
    능력치는 모두 다름

라운드

1=1.
  플레이어 순차적으로 본인이 향하고 있는 방향대로 한 칸 이동
  격자 밖으로 이동하는 경우, 정반대 방향으로 이동

2-1.
  플레이어가 없으면 해당 칸에 총 확인
  총이 있는 경우, 해당 플레이어는 총을 획득
  이미 총을 가지고 있는 경우, 공격력이 높은 총을 획득하고
  소지한 총을 격자에 놓는다.

2-2-1.
  이동방향에 플레이어 있는 경우 싸움
  초기 능력치와 가지고 있는 공격력의 합 비교 > 높은 플레이어 승리
  같다면 초기 능력치 비교  > 높은 플레이어 승리
  위 합의 차이만큼 포인트 획득

2-2-2.
  진 플레이어는 본인 가진 총을 내려놓고
  진행 방향으로 한 칸이동
    다른 플레이어 or 격자 범위 밖인 경우 오른쪽으로 90 회전 후
    빈칸으로 순간이동

2-2-3.
  이긴 플레이어는
  승리한 칸에 떨어져 있는 총, 들고 있던 총 중 공격력 높은 총을 획득
  나머지 총을 해당 격자에 놓는다

입력

N M K
  N : 격자 크기             2 이상 20 이하
  M : 플레이어 수            1 이상 N^2, 30 이하
  K : 라운드 수             1 이상 500 이하

N x N 격자 정보
  0 : 빈칸
  0 > input : 총 공격력     1 이상 100,000 이하

M개 줄
  x y d s
  x, y : 플레이어의 위치       1 이상 N 이하
  d : 방향, 상-우-하-좌       0 ~ 3
  s : 초기 능력치            1 이상 100 이하

초기 플레이어 위치 겹침 X, 총 X

*/

#define MAX_N 21
#define MAX_P 31
#include <iostream>
#include <queue>

using namespace std;

struct Block {
  priority_queue<int> weapons;
  int current_player;
};

struct Player {
  int y, x;
  int dir;
  int stat;
  int weapon_stat;

  bool operator<(Player right) const {
    if (stat + weapon_stat < right.stat + right.weapon_stat) return true;
    if (stat + weapon_stat > right.stat + right.weapon_stat) return false;

    if (stat < right.stat) return true;
    if (stat > right.stat) return false;

    return false;
  }
};

int N, M, K;
Block board[MAX_N][MAX_N];
Player player[MAX_P];
int points[MAX_P];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void input() {
  cin >> N >> M >> K;

  for (int j = 1; j <= N; j++) {
    for (int i = 1; i <= N; i++) {
      int weapon_stat;

      cin >> weapon_stat;

      if (weapon_stat) board[j][i].weapons.push(weapon_stat);
    }
  }

  for (int i = 1; i <= M; i++) {
    int y, x, d, s;
    cin >> y >> x >> d >> s;

    player[i] = {y, x, d, s};

    board[y][x].current_player = i;
  }

  return;
}

void getWeapon(int index) {
  int de = 1;

  int y = player[index].y;
  int x = player[index].x;
  int weapon_stat = player[index].weapon_stat;

  de = 0;

  if (board[y][x].weapons.empty()) return;

  if (board[y][x].weapons.top() <= weapon_stat) return;

  player[index].weapon_stat = board[y][x].weapons.top();
  board[y][x].weapons.pop();

  if (weapon_stat) board[y][x].weapons.push(weapon_stat);

  de = 1;

  return;
}

void fightPlayer(int index1, int index2) {
  int winner_index;
  int loser_index;

  if (player[index1] < player[index2]) {
    winner_index = index2;
    loser_index = index1;
  } else {
    winner_index = index1;
    loser_index = index2;
  }

  // Add Point
  int point = (player[winner_index].weapon_stat + player[winner_index].stat) -
              (player[loser_index].weapon_stat + player[loser_index].stat);

  points[winner_index] += point;

  // Loser : Drop weapon
  Player loser = player[loser_index];
  Player winner = player[winner_index];

  int y = loser.y;
  int x = loser.x;

  if (loser.weapon_stat) {
    board[loser.y][loser.x].weapons.push(loser.weapon_stat);
    loser.weapon_stat = 0;
  }

  // Loser : Find and Move to next position
  int loser_ny;
  int loser_nx;
  int loser_ndir;

  for (int i = 0; i < 4; i++) {
    loser_ndir = (loser.dir + i) % 4;
    loser_ny = y + dy[loser_ndir];
    loser_nx = x + dx[loser_ndir];

    if (loser_ny <= 0 || loser_nx <= 0 || loser_ny > N || loser_nx > N)
      continue;

    if (board[loser_ny][loser_nx].current_player) continue;

    break;
  }

  loser.y = loser_ny;
  loser.x = loser_nx;
  loser.dir = loser_ndir;

  // Loser : Update position at Player
  player[loser_index] = loser;

  // Update position at board
  board[loser_ny][loser_nx].current_player = loser_index;
  board[y][x].current_player = winner_index;

  // Loser : Get weapon in new-position
  getWeapon(loser_index);

  // Winner : Get weapon in position
  getWeapon(winner_index);

  return;
}

void movePlayer(int index) {
  int y = player[index].y;
  int x = player[index].x;
  int stat = player[index].stat;
  int dir = player[index].dir;
  int weapon_stat = player[index].weapon_stat;

  int ny = y + dy[dir];
  int nx = x + dx[dir];
  int ndir = dir;

  if (ny <= 0 || nx <= 0 || ny > N || nx > N) {
    ndir = (dir + 2) % 4;

    ny = y + dy[ndir];
    nx = x + dx[ndir];
  }

  player[index].y = ny;
  player[index].x = nx;
  player[index].dir = ndir;

  if (board[ny][nx].current_player == 0) {
    board[y][x].current_player = 0;
    board[ny][nx].current_player = index;

    getWeapon(index);
  } else {
    board[y][x].current_player = 0;
    fightPlayer(index, board[ny][nx].current_player);
  }

  return;
}

void printPoints() {
  for (int i = 1; i <= M; i++) {
    cout << points[i] << " ";
  }
  cout << "\n";
}

void solution() {
  for (int k = 1; k <= K; k++) {
    for (int i = 1; i <= M; i++) {
      movePlayer(i);
    }
  }

  printPoints();

  return;
}

int main(int argc, char** argv) {
  input();
  solution();

  return 0;
}