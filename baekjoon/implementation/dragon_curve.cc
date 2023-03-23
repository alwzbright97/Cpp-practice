#include <iostream>
#include <vector>

constexpr int MAX = 101;

bool map[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void curve(std::pair<int, int> start_pt, int direction, int generation) {
  std::pair<int, int> end_pt = {start_pt.first + dx[direction],
                                start_pt.second + dy[direction]};
  std::vector<int> vec_direction;
  vec_direction.push_back(direction);

  map[start_pt.second][start_pt.first] = 1;
  map[end_pt.second][end_pt.first] = 1;

  for (int i = 0; i < generation; i++) {
    int size = vec_direction.size();

    for (int j = size - 1; j >= 0; j--) {
      int prev_direction = (vec_direction[j] + 1) % 4;
      vec_direction.push_back(prev_direction);
      end_pt = {end_pt.first + dx[prev_direction],
                end_pt.second + dy[prev_direction]};

      if (end_pt.first >= 0 && end_pt.first < MAX && end_pt.second >= 0 &&
          end_pt.second < MAX) {
        map[end_pt.second][end_pt.first] = 1;
      }
    }
  }
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N;

  std::cin >> N;

  while (N--) {
    int x, y, direction, generation;
    std::cin >> x >> y >> direction >> generation;

    curve({x, y}, direction, generation);
  }

  int answer = 0;

  for (int j = 0; j < MAX - 1; j++) {
    for (int i = 0; i < MAX - 1; i++) {
      if (map[j][i] && map[j + 1][i] && map[j][i + 1] && map[j + 1][i + 1]) {
        answer++;
      }
    }
  }

  std::cout << answer << "\n";

  return 0;
}