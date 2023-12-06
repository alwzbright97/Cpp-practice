// !머리를 돌리는 과정을 수정해야 함!

/*
문제 이해

전차는 하나뿐

맵의 구성
. : 평지
* : 벽돌 벽
# : 강철 벽
- : 물
^ : 위를 바라보는 전차
v : 아래를 바라보는 전차
< : 왼쪽을 바라보는 전차
> : 오른쪽을 바라보는 전차

문자 동작
U : 방향 위로 바꾸고 위가 평지라면 이동
D : 방향 아래로 바꾸고 아래가 평지라면 이동
L : 방향 왼쪽으로 바꾸고, 왼쪽이 평지라면 이동
R : 방향 오른쪽으로 바꾸고, 오른쪽이 평지라면 이동


입력
Case 별 입력
3 7
***....
*-..#**
#<.****

*/

#include <iostream>

using namespace std;

int H, W;
char MAP[21][21];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char dirs[4] = {'^', 'v', '<', '>'};
int srt_y, srt_x, dir;

int N;

// string도 당연히 가능하다
// 문제에서 최대 길이를 주었기 때문에, 간단하게 char 배열로 작성
char user_input[101];

void shoot() {
  // 전차 좌표에서 전차가 바라보는 방향으로 직선을 확인하면서
  // 벽돌벽이면 평지로 변환
  int ny = srt_y;
  int nx = srt_x;

  while (true) {
    ny += dy[dir];
    nx += dx[dir];

    // 맵 밖으로 나갈 경우
    if (ny < 0 || nx < 0 || ny >= H || nx >= W)
      return;

    // 강철 벽을 만날 경우
    if (MAP[ny][nx] == '#')
      return;

    // 물을 만날 경우
    if (MAP[ny][nx] == '-')
      continue;

    // 벽돌 벽을 만날 경우
    if (MAP[ny][nx] == '*') {
      // 평지로
      MAP[ny][nx] = '.';
      return;
    }
  }
}

// 이동
void move(char user_input) {
  // 1. 방향
  if (user_input == 'U')
    dir = 0;
  else if (user_input == 'D')
    dir = 1;
  else if (user_input == 'L')
    dir = 2;
  else if (user_input == 'R')
    dir = 3;

  // 2. 전차가 갈 수 있는가 체크
  int ny = srt_y + dy[dir];
  int nx = srt_x + dx[dir];

  // 맵 밖으로 넘어가면
  if (ny < 0 || nx < 0 || ny >= H || nx >= W)
    return;

  // 갈 수 있을 때만 해당 방향으로 한 칸 이동
  if (MAP[ny][nx] == '.') {
    // 기존에 있던 곳을 평지로 변경
    MAP[srt_y][srt_x] = '.';
    // 이동
    MAP[ny][nx] = dirs[dir];

    // 전차 좌표를 변경
    srt_y = ny;
    srt_x = nx;
    return;
  }

  return;
}

int main() {
  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    // 초기화

    // 입력
    cin >> H >> W;

    for (int j = 0; j < H; j++) {
      for (int i = 0; i < W; i++) {
        cin >> MAP[j][i];

        if (MAP[j][i] == '^')
          srt_y = j, srt_x = i, dir = 0;
        else if (MAP[j][i] == 'v')
          srt_y = j, srt_x = i, dir = 1;
        else if (MAP[j][i] == '<')
          srt_y = j, srt_x = i, dir = 2;
        else if (MAP[j][i] == '>')
          srt_y = j, srt_x = i, dir = 3;
      }
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> user_input[i];
    }

    for (int i = 0; i < N; i++) {
      //
      if (user_input[i] == 'S')
        shoot();
      // 나머지 이동일 때
      else {
        move(user_input[i]);
      }
    }

    cout << "#" << tc << " ";
    for (int j = 0; j < H; j++) {
      for (int i = 0; i < W; i++) {
        cout << MAP[j][i];
      }
      cout << "\n";
    }
  }

  return 0;
}
