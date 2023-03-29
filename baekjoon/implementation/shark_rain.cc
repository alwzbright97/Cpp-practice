#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
#define MAX 51
#define MAX2 101

int N, M;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

bool disappear[MAX][MAX];
int map[MAX][MAX];
int d[MAX2], s[MAX2];

vector<pair<int, int>> cloud;

/*
void printMap() {

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      cout << map[j][i] << ' ';
    }
    cout << endl;
  }
}
*/

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      cin >> map[j][i];
    }
  }

  cloud.push_back({0, N - 1});
  cloud.push_back({1, N - 1});
  cloud.push_back({0, N - 2});
  cloud.push_back({1, N - 2});

  for (int m = 0; m < M; m++) {
    // get input
    cin >> d[m] >> s[m];
  }

  for (int m = 0; m < M; m++) {
    // cout << "m : " << m << "===========" << endl;
    // rainMovedCloud
    for (int i = 0; i < cloud.size(); i++) {
      int x = cloud[i].first, y = cloud[i].second;
      int nx = ((x + s[m] * dx[d[m] - 1]) % N);
      int ny = ((y + s[m] * dy[d[m] - 1]) % N);

      nx = (nx + N) % N, ny = (ny + N) % N;

      map[ny][nx]++;
      cloud[i].first = nx;
      cloud[i].second = ny;
    }

    // cout << "\tAfter rainMovedCloud" << endl;
    // printMap();

    // copyWater
    for (int i = 0; i < cloud.size(); i++) {
      int x = cloud[i].first, y = cloud[i].second;

      int count = 0;
      for (int dir = 1; dir < 8; dir += 2) {
        int nx = x + dx[dir], ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
          continue;

        if (map[ny][nx] != 0) {
          count++;
        }
      }

      map[y][x] += count;
      disappear[y][x] = true;
    }
    // cout << "\tAfter copyWater" << endl;
    // printMap();

    cloud.clear();

    // getNewCloud
    for (int j = 0; j < N; j++) {
      for (int i = 0; i < N; i++) {
        if (map[j][i] > 1 && !disappear[j][i]) {
          map[j][i] -= 2;
          cloud.push_back({i, j});
        }
        disappear[j][i] = false;
      }
    }

    // cout << "\tAfter getNewCloud" << endl;
    // printMap();
  }

  int answer = 0;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      answer += map[j][i];
    }
  }

  cout << answer << endl;

  return 0;
}