/*
SWEA 5644 : 무선충전

모든 경우를 vector에 집어넣는다

시간에 따라 각 BC를 뽑고
  BC가 같다면 해당 BC를 나눈 값을 더하고
  BC가 다르다면 두 BC의 합을 더한다
*/
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct BatteryCharger {
  int y, x;
  int coverage;
  int perf;
};

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, -1, 0, 1, 0};

int T;
int M, A;  // M : num_cmd, A : num_BC
int MAP[11][11];
vector<int> cmd[2];
vector<BatteryCharger> bc_vector;
vector<vector<int>> bc_available[2];
int answer;

void input() {
  cin >> M >> A;

  for (int i = 0; i < 2; i++) {
    cmd[i] = vector<int>(M + 1, 0);
    bc_available[i] = vector<vector<int>>(M + 1);

    for (int j = 1; j <= M; j++) {
      cin >> cmd[i][j];
    }
  }

  bc_vector = vector<BatteryCharger>(A + 1);
  bc_vector[0] = {0, 0, 500, 0};  // 모든 곳에서 사용하는 BC 추가
  for (int i = 1; i <= A; i++) {
    int y, x, coverage, perf;
    cin >> x >> y >> coverage >> perf;

    bc_vector[i] = {y - 1, x - 1, coverage, perf};
  }

  return;
}

void getAvailableBC(int who, int time, int y, int x) {
  if (time > M) {
    return;
  }

  // Move
  int ny = y + dy[cmd[who][time]];
  int nx = x + dx[cmd[who][time]];

  // BC Check
  for (int i = 0; i <= A; i++) {
    BatteryCharger BC = bc_vector[i];
    int dist = abs(nx - BC.x) + abs(ny - BC.y);
    if (dist <= BC.coverage) {
      bc_available[who][time].push_back(i);
    }
  }

  getAvailableBC(who, time + 1, ny, nx);

  return;
}

int getMaximumValue(int time) {
  int max_value = 0;

  // A에 대한 결과를 하나 추출
  for (int i = 0; i < bc_available[0][time].size(); i++) {
    // B에 대한 결과를 하나 추출
    for (int j = 0; j < bc_available[1][time].size(); j++) {
      int bc_index_a = bc_available[0][time][i];
      int bc_index_b = bc_available[1][time][j];

      if (bc_index_a == bc_index_b) {
        max_value = max(max_value, bc_vector[bc_index_a].perf);
      } else {
        max_value = max(
            max_value, bc_vector[bc_index_a].perf + bc_vector[bc_index_b].perf);
      }
    }
  }

  return max_value;
}

void solution() {
  getAvailableBC(0, 0, 0, 0);
  getAvailableBC(1, 0, 9, 9);
  answer = 0;
  for (int i = 0; i <= M; i++) {
    int max_value = getMaximumValue(i);
    // cout << "time: " << i << " max_value: " << max_value << "\n";
    answer += max_value;
  }

  return;
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    input();
    solution();
    cout << "#" << test_case << " " << answer << "\n";
  }

  return 0;
}