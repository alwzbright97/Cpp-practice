#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

constexpr int MAX = 25;
bool arr[MAX][MAX];
std::vector<int> answer;
int N;
void bfs(int x, int y) {
  // std::cout << "start at i:" << x << " j:" << y << "\n";
  int count = 0;
  std::queue<std::pair<int, int>> q;

  arr[x][y] = false;
  q.push(std::make_pair(x, y));

  while (!q.empty()) {
    std::pair<int, int> here = q.front();
    q.pop();
    int i = here.first;
    int j = here.second;
    count++;

    // up
    if ((j - 1 >= 0) && arr[i][j - 1]) {
      q.push(std::make_pair(i, j - 1));
      arr[i][j - 1] = false;
    }
    // down
    if ((j + 1 < N) && arr[i][j + 1]) {
      q.push(std::make_pair(i, j + 1));
      arr[i][j + 1] = false;
    }
    // left
    if ((i - 1 >= 0) && arr[i - 1][j]) {
      q.push(std::make_pair(i - 1, j));
      arr[i - 1][j] = false;
    }
    // right
    if ((i + 1 < N) && arr[i + 1][j]) {
      q.push(std::make_pair(i + 1, j));
      arr[i + 1][j] = false;
    }
  }

  answer.push_back(count);
  return;
}

int main() {
  // std::cin.tie(NULL);
  // std::cout.tie(NULL);
  // std::ios::sync_with_stdio(false);

  std::cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int tmp;
      scanf("%1d", &tmp);
      arr[i][j] = tmp;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (arr[i][j]) {
        bfs(i, j);
      }
    }
  }

  std::sort(answer.begin(), answer.end());

  // std::cout << "Answer\n";
  std::cout << answer.size() << "\n";
  for (std::vector<int>::iterator iter = answer.begin(); iter != answer.end();
       iter++) {
    std::cout << *iter << "\n";
  }

  // std::cout << "Result\n";
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     std::cout << arr[i][j];
  //   }
  //   std::cout << "\n";
  // }

  return 0;
}