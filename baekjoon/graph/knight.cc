#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int T;
  std::cin >> T;
  std::vector<int> answer;

  while (T--) {
    int N;
    std::cin >> N;

    int p_x, p_y, t_x, t_y;
    std::cin >> p_x >> p_y;
    std::cin >> t_x >> t_y;

    std::vector<std::vector<bool>> board(N, std::vector<bool>(N, false));
    std::queue<std::tuple<int, int, int>> q;

    board[p_x][p_y] = true;
    q.push(std::make_tuple(p_x, p_y, 0));

    while (!q.empty()) {
      int x, y, t;
      x = std::get<0>(q.front());
      y = std::get<1>(q.front());
      t = std::get<2>(q.front());

      q.pop();

      if ((x == t_x) && (y == t_y)) {
        answer.push_back(t);
        break;
      }

      for (int i = 0; i < 8; i++) {
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if ((n_x >= 0) && (n_x < N) && (n_y >= 0) && (n_y < N)) {
          if (!board[n_x][n_y]) {
            q.push(std::make_tuple(n_x, n_y, t + 1));
            board[n_x][n_y] = true;
          }
        }
      }
    }
  }

  for (std::vector<int>::iterator iter = answer.begin(); iter != answer.end();
       iter++) {
    std::cout << (*iter) << "\n";
  }

  return 0;
}