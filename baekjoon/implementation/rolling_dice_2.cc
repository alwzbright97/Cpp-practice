#include <iostream>
#include <queue>
using namespace std;

#define MAX 21
#define endl '\n'

int map[MAX][MAX];
bool visited[MAX][MAX];
int score[MAX][MAX];
int dice[6] = {1, 2, 3, 4, 5, 6};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M, K;

queue<pair<int, int>> q;

void printDice() {
  cout << "=== Dice ===" << endl;
  cout << "  " << dice[1] << endl;
  cout << dice[3] << " " << dice[0] << " " << dice[2] << endl;
  cout << "  " << dice[4] << endl;
  cout << "  " << dice[5] << endl << endl;
}

void printScore() {
  cout << "===== score =====" << endl;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      cout << score[j][i] << ' ';
    }
    cout << endl;
  }
}

void rollDice(int direction) {
  int temp = dice[5];

  if (direction == 0) {
    // right
    dice[5] = dice[2];
    dice[2] = dice[0];
    dice[0] = dice[3];
    dice[3] = temp;
  } else if (direction == 1) {
    // up
    dice[5] = dice[1];
    dice[1] = dice[0];
    dice[0] = dice[4];
    dice[4] = temp;
  } else if (direction == 2) {
    // left
    dice[5] = dice[3];
    dice[3] = dice[0];
    dice[0] = dice[2];
    dice[2] = temp;
  } else {
    // down
    dice[5] = dice[4];
    dice[4] = dice[0];
    dice[0] = dice[1];
    dice[1] = temp;
  }

  return;
}

void getScore() {
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {

      if (visited[j][i])
        continue;

      int num = map[j][i];
      vector<pair<int, int>> history;

      q.push({i, j});
      visited[j][i] = true;

      while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        history.push_back({x, y});
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];

          if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[ny][nx])
            continue;

          if (map[ny][nx] != num)
            continue;

          visited[ny][nx] = true;
          q.push({nx, ny});
        }
      }

      int current_size = history.size();
      int current_score = current_size * num;

      for (int v = 0; v < current_size; v++) {
        int x = history[v].first;
        int y = history[v].second;

        score[y][x] = current_score;
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N >> M >> K;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      cin >> map[j][i];
    }
  }

  // printDice();

  getScore();
  // printScore();

  int dice_direction = 0;
  int y = 0, x = 0;
  int answer = 0;

  for (int k = 0; k < K; k++) {

    int ny = y + dy[dice_direction];
    int nx = x + dx[dice_direction];

    if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
      dice_direction = (dice_direction + 2) % 4;
    }

    rollDice(dice_direction);

    y += dy[dice_direction];
    x += dx[dice_direction];

    if (dice[5] > map[y][x])
      dice_direction = (dice_direction + 3) % 4;
    else if (dice[5] < map[y][x])
      dice_direction = (dice_direction + 1) % 4;

    answer += score[y][x];
  }
  // cout << "(" << y + 1 << ", " << x + 1 << ")"
  //      << " answer: " << answer << " direction: " << dice_direction << endl;
  // printDice();

  cout << answer << endl;

  return 0;
}