#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

std::vector<std::vector<int>> arr;
std::vector<std::pair<int, int>> blank;
std::vector<int> picked_num;
int max = 0;

void countAfterBFS(std::vector<std::vector<int>> i_arr,
                   std::vector<int> &pnum) {
  // switch
  for (int i = 0; i < 3; i++) {
    int x = blank[picked_num[i]].first;
    int y = blank[picked_num[i]].second;

    i_arr[x][y] = 1;
  }
  // bfs
  std::queue<std::pair<int, int>> q;
  for (int j = 0; j < N; j++)
    for (int i = 0; i < M; i++)
      if (i_arr[i][j] == 2)
        q.push({i, j});

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
        if (!i_arr[nx][ny]) {
          i_arr[nx][ny] = 2;
          q.push({nx, ny});
        }
      }
    }
  }

  int count = 0;
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      if (!i_arr[i][j])
        count++;
    }
  }
  // update max
  max = std::max(max, count);
  return;
}

void recursiveComb(int index) {
  int num_picked = picked_num.size();

  if (num_picked == 3) {
    countAfterBFS(arr, picked_num);
    return;
  } else if (index < blank.size()) {
    picked_num.push_back(index);
    recursiveComb(index + 1);
    picked_num.pop_back();
    recursiveComb(index + 1);
  }

  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  arr = std::vector<std::vector<int>>(M, std::vector<int>(N));

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      std::cin >> arr[i][j];

      if (!arr[i][j]) {
        blank.push_back({i, j});
      }
    }
  }

  recursiveComb(0);

  std::cout << max;

  return 0;
}