#include <iostream>

#define endl '\n'
#define MAX 51

using namespace std;

string board[MAX];

int N, answer = 0;

void countRowMax(int j) {
  if (j >= N)
    return;

  int count_1 = 1;
  for (int n = 0; n < N; n++) {
    if (board[j][n] == board[j][n + 1]) {
      count_1++;

      if (count_1 > answer)
        answer = count_1;
    } else {
      count_1 = 1;
    }
  }
  return;
}

void countColMax(int i) {
  if (i >= N)
    return;

  int count_1 = 1;
  for (int n = 0; n < N; n++) {
    if (board[n][i] == board[n + 1][i]) {
      count_1++;

      if (count_1 > answer)
        answer = count_1;
    } else {
      count_1 = 1;
    }
  }

  return;
}

void swapCandy(char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;

  return;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N;

  for (int j = 0; j < N; j++) {
    std::cin >> board[j];
  }

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N - 1; i++) {
      swapCandy(board[i][j], board[i + 1][j]);
      countRowMax(i);
      countRowMax(i + 1);
      countColMax(j);
      swapCandy(board[i][j], board[i + 1][j]);

      swapCandy(board[j][i], board[j][i + 1]);
      countColMax(i);
      countColMax(i + 1);
      countRowMax(j);
      swapCandy(board[j][i], board[j][i + 1]);
    }
  }

  cout << answer << endl;

  return 0;
}
