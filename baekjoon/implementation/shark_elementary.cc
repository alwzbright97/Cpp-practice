#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

#define endl '\n'
#define MAX 21
#define MAX2 441

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int board[MAX][MAX];
int N;

int order[MAX2];
bool isLike[MAX2][MAX2];
int satisfaction[5] = {0, 1, 10, 100, 1000};

int getSatisfaction() {
  int value = 0, count;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      count = 0;

      for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
          continue;
        }

        if (isLike[board[y][x]][board[ny][nx]])
          count++;
      }

      value += satisfaction[count];
    }
  }

  return value;
}

void setPosition(int n) {
  vector<tuple<int, int, int, int>> v;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (board[y][x])
        continue;

      int blank = 0, like = 0;

      for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
          continue;
        }

        if (!board[ny][nx]) {
          blank--;
        } else if (isLike[n][board[ny][nx]]) {
          like--;
        }
      }

      v.push_back({like, blank, y, x});
    }
  }

  sort(v.begin(), v.end());
  int row = get<2>(v[0]), col = get<3>(v[0]);
  board[row][col] = n;

  return;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N * N; i++) {
    cin >> order[i];
    for (int j = 0; j < 4; j++) {
      int like_who;
      cin >> like_who;
      isLike[order[i]][like_who] = true;
    }
  }

  for (int i = 0; i < N * N; i++) {
    setPosition(order[i]);
  }

  int answer = getSatisfaction();
  cout << answer << endl;

  return 0;
}