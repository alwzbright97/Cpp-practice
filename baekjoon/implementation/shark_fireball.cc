#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map_mass[50][50];
int map_speed[50][50];
int map_dir[50][50];
int map_count[50][50];
bool is_same_dir[50][50];

int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int N, M, K;
vector<vector<int>> fireball;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M >> K;

  for (int m = 0; m < M; m++) {
    int row, col, mass, speed, dir;
    cin >> row >> col >> mass >> speed >> dir;

    fireball.push_back({row, col, mass, speed, dir});
  }

  for (int k = 0; k < K; k++) {

    for (int i = 0; i < fireball.size(); i++) {
      int row, col, mass, speed, dir;
      row = fireball[i][0];
      col = fireball[i][1];
      mass = fireball[i][2];
      speed = fireball[i][3];
      dir = fireball[i][4];

      int nrow, ncol;

      nrow = (row + speed * drow[dir]) % N;
      ncol = (col + speed * dcol[dir]) % N;

      nrow = (nrow + N) % N;
      ncol = (ncol + N) % N;

      map_count[nrow][ncol]++;
      map_mass[nrow][ncol] += mass;
      map_speed[nrow][ncol] += speed;

      if (map_count[nrow][ncol] == 1) {
        map_dir[nrow][ncol] = dir;
        is_same_dir[nrow][ncol] = true;
      } else if (is_same_dir[nrow][ncol] &&
                 (dir % 2) != (map_dir[nrow][ncol] % 2)) {
        is_same_dir[nrow][ncol] = false;
      }
    }

    fireball.clear();

    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++) {
        int nmass, nspeed, ndir;

        if (map_count[row][col] > 1) {
          if (map_mass[row][col] >= 5) {

            nmass = map_mass[row][col] / 5;
            nspeed = map_speed[row][col] / map_count[row][col];
            ndir = is_same_dir[row][col] ? 0 : 1;

            for (; ndir < 8; ndir += 2) {
              fireball.push_back({row, col, nmass, nspeed, ndir});
            }
          }
        } else if (map_count[row][col] == 1) {
          nmass = map_mass[row][col];
          nspeed = map_speed[row][col];
          ndir = map_dir[row][col];
          fireball.push_back({row, col, nmass, nspeed, ndir});
        }

        map_count[row][col] = 0;
        map_mass[row][col] = 0;
        map_speed[row][col] = 0;
        map_dir[row][col] = 0;
        is_same_dir[row][col] = false;
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < fireball.size(); i++) {
    answer += fireball[i][2];
  }

  cout << answer << endl;

  return 0;
}