#include <iostream>

using namespace std;

#define MAX 101
#define endl '\n'

int N, K, L;
bool snake[MAX][MAX];
bool apple[MAX][MAX];

char direction[MAX];
int length[MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void printSnake() {
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      cout << (int)snake[j][i] << ' ';
    }
    cout << endl;
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> K;

  for (int k = 0; k < K; k++) {
    int row, col;
    cin >> row >> col;

    apple[row - 1][col - 1] = true;
  }

  cin >> L;

  for (int k = 0; k < L; k++) {
    cin >> length[k] >> direction[k];
  }

  int second = 0;
  pair<int, int> head = {0, 0}, tail = {0, 0};

  snake[0][0] = true;

  int head_direction = 0, tail_direction = 0;
  int head_count = 0, head_ptr = 0;
  int tail_count = 0, tail_ptr = 0;

  while (true) {

    second++;

    // head lengthened
    head_count++;
    head.first += dx[head_direction];
    head.second += dy[head_direction];

    if (head.first < 0 || head.first >= N || head.second < 0 ||
        head.second >= N || snake[head.second][head.first])
      break;

    snake[head.second][head.first] = true;

    // is there apple at head?
    if (apple[head.second][head.first]) {
      apple[head.second][head.first] = false;
    } else {
      tail_count++;

      snake[tail.second][tail.first] = false;

      tail.first += dx[tail_direction];
      tail.second += dy[tail_direction];
    }

    // head direction
    if (head_count == length[head_ptr]) {

      if (direction[head_ptr] == 'D') {
        head_direction = (head_direction + 1) % 4;
      } else {
        head_direction = (head_direction + 3) % 4;
      }

      head_ptr++;
    }

    // tail_direction
    if (tail_count == length[tail_ptr]) {

      if (direction[tail_ptr] == 'D') {
        tail_direction = (tail_direction + 1) % 4;
      } else {
        tail_direction = (tail_direction + 3) % 4;
      }

      tail_ptr++;
    }

    // cout << "\nsecond: " << second << " =====" << endl;
    // printSnake();
  }

  cout << second << endl;

  return 0;
}