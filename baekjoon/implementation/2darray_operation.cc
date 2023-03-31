#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 101
#define endl '\n'

int board[MAX][MAX];
int num_count[MAX];

int R = 3, C = 3;
int r, c, k;
vector<pair<int, int>> v;
int answer;

void printBoard() {
  cout << "\ncount: " << answer << " R: " << R << " C: " << C << endl;

  for (int j = 0; j < R; j++) {
    for (int i = 0; i < C; i++) {
      cout << board[j][i] << ' ';
    }
    cout << '\n';
  }

  return;
}

void initCount() {
  memset(num_count, 0, sizeof(num_count));
  return;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> r >> c >> k;

  for (int j = 0; j < R; j++) {
    for (int i = 0; i < C; i++) {
      cin >> board[j][i];
    }
  }

  answer = 0;

  while (answer <= 100) {

    int max_number, v_size, update_size = 0;

    if (board[r - 1][c - 1] == k) {
      cout << answer << endl;
      return 0;
    }

    if (R >= C) {

      for (int row = 0; row < R; row++) {
        max_number = 0;
        for (int col = 0; col < C; col++) {
          num_count[board[row][col]]++;

          if (board[row][col] > max_number)
            max_number = board[row][col];

          board[row][col] = 0;
        }

        for (int i = 1; i <= max_number; i++) {
          if (num_count[i] != 0) {
            v.push_back({num_count[i], i});
          }
        }

        sort(v.begin(), v.end());

        v_size = v.size();
        v_size = min(v_size, 50);

        for (int i = 0; i < v_size; i++) {
          board[row][i * 2] = v[i].second;
          board[row][i * 2 + 1] = v[i].first;
        }

        v.clear();
        initCount();

        update_size = max(v_size * 2, update_size);
      }

      C = update_size;

    } else {

      for (int col = 0; col < C; col++) {
        max_number = 0;
        for (int row = 0; row < R; row++) {
          num_count[board[row][col]]++;

          if (board[row][col] > max_number)
            max_number = board[row][col];

          board[row][col] = 0;
        }

        for (int i = 1; i <= max_number; i++) {
          if (num_count[i] != 0) {
            v.push_back({num_count[i], i});
          }
        }

        sort(v.begin(), v.end());

        v_size = v.size();
        v_size = min(v_size, 50);

        for (int i = 0; i < v_size; i++) {
          board[i * 2][col] = v[i].second;
          board[i * 2 + 1][col] = v[i].first;
        }

        v.clear();
        initCount();

        update_size = max(v_size * 2, update_size);
      }

      R = update_size;
    }

    answer++;

    // printBoard();
  }

  cout << -1 << endl;

  return 0;
}