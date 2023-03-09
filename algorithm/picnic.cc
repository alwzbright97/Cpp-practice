#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<bool>> friends;
std::vector<bool> paired;

// 짝(i, j)와 짝(j, i)을 다르게 구분할 경우의 수
int countPairsRepeated() {
  bool finished = true;

  for (int i = 0; i < N; i++) {
    if (!paired[i]) {
      finished = false;
    }
  }

  if (finished) {
    return 1;
  }

  int ret_val = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!paired[i] && !paired[j] && friends[i][j]) {
        paired[i] = true;
        paired[j] = true;
        ret_val += countPairsRepeated();
        paired[i] = false;
        paired[j] = false;
      }
    }
  }
  return ret_val;
}

int countPairs() {
  // 남은 후보 중 가장 번호가 빠른 후보를 선택한다.
  int first = -1;
  for (int i = 0; i < N; i++) {
    if (!paired[i]) {
      first = i;
      break;
    }
  }
  // 기저 사례: 모든 후보가 짝지어졌으면 한 가지 방법을 찾았으니 종료한다.
  if (first == -1)
    return 1;
  int ret_val = 0;
  // 선택한 후보와 짝지을 후보를 결정한다.
  for (int i = first + 1; i < N; i++) {
    if (!paired[i] && friends[i][first]) {
      paired[i] = paired[first] = true;
      ret_val += countPairs();
      paired[i] = paired[first] = false;
    }
  }

  return ret_val;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int T;

  std::cin >> T;

  while (T--) {
    std::cin >> N >> M;

    friends = std::vector<std::vector<bool>>(N, std::vector<bool>(N, false));
    paired = std::vector<bool>(N, false);

    for (int i = 0; i < M; i++) {
      int x, y;
      std::cin >> x >> y;
      friends[x][y] = true;
      friends[y][x] = true;
    }

    int wrong_answer = countPairsRepeated();
    int answer = countPairs();

    std::cout << wrong_answer << " " << answer << "\n";
  }

  return 0;
}