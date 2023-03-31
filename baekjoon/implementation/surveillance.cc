#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 9
#define endl '\n'

int N, M;
int map[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int blind_count;
vector<vector<int>> cam_info;

void countBlindArea() {
  int current_count = 0;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (map[j][i] == 0)
        current_count++;
    }
  }

  if (current_count < blind_count)
    blind_count = current_count;

  return;
}

void processCamera(int x, int y, int direction) {
  int nx = x, ny = y;

  while (true) {
    nx += dx[direction];
    ny += dy[direction];

    if (nx < 0 || nx >= M || ny < 0 || ny >= N)
      return;

    if (map[ny][nx] == 6) {
      return;

    } else if (map[ny][nx] == 0) {
      map[ny][nx] = -1;
    }
  }

  return;
}

void getCameraDirection(int depth) {

  if (depth == cam_info.size()) {
    countBlindArea();

    return;
  }

  int backup[MAX][MAX];

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      backup[j][i] = map[j][i];
    }
  }

  int x = cam_info[depth][0];
  int y = cam_info[depth][1];
  int type = cam_info[depth][2];

  int dir_count;

  switch (type) {
  case 2:
    dir_count = 2;
    break;

  case 5:
    dir_count = 1;
    break;

  default:
    dir_count = 4;
  }

  for (int dir = 0; dir < dir_count; dir++) {
    switch (type) {
    case 1:
      processCamera(x, y, dir);
      break;
    case 2:
      processCamera(x, y, dir);
      processCamera(x, y, (dir + 2) % 4);
      break;
    case 3:
      processCamera(x, y, dir);
      processCamera(x, y, (dir + 1) % 4);
      break;
    case 4:
      processCamera(x, y, dir);
      processCamera(x, y, (dir + 1) % 4);
      processCamera(x, y, (dir + 2) % 4);
      break;
    case 5:
      processCamera(x, y, dir);
      processCamera(x, y, (dir + 1) % 4);
      processCamera(x, y, (dir + 2) % 4);
      processCamera(x, y, (dir + 3) % 4);
      break;
    }

    getCameraDirection(depth + 1);

    for (int j = 0; j < N; j++) {
      for (int i = 0; i < M; i++) {
        map[j][i] = backup[j][i];
      }
    }
  }

  return;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  blind_count = N * M;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {

      cin >> map[j][i];

      if (map[j][i] > 0 && map[j][i] < 6) {
        cam_info.push_back({i, j, map[j][i]});
      }
    }
  }

  getCameraDirection(0);

  cout << blind_count << endl;

  return 0;
}
