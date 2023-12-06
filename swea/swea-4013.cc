#include <cmath>
#include <deque>
#include <iostream>
using namespace std;

deque<int> dq[5];

int turn_flag[5];
int K;
// index 자석을 기점으로 다른 자석들을 모두 돌려야하는 지 확인
void turn_check(int index, int direction) {
  // 초기화
  for (int i = 1; i <= 4; i++) {
    turn_flag[i] = 0;
  }

  turn_flag[index] = direction;

  // 왼쪽 체크
  for (int i = index; i >= 2; i--) {
    // 다른 자성끼리 붙어 있다면
    if (dq[i - 1][2] != dq[i][6]) {
      turn_flag[i - 1] = turn_flag[i] * -1;
    }
  }
  // 오른쪽 체크
  for (int i = index; i < 4; i++) {
    if (dq[i][2] != dq[i + 1][6]) {
      turn_flag[i + 1] = turn_flag[i] * -1;
    }
  }

  return;
}

void right_turn(int index) {
  dq[index].push_front(dq[index].back());
  dq[index].pop_back();
}

void left_turn(int index) {
  dq[index].push_back(dq[index].front());
  dq[index].pop_front();
}

int main() {
  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    // 초기화
    for (int i = 1; i <= 4; i++) {
      dq[i].clear();
    }

    // 입력
    cin >> K;
    for (int i = 1; i <= 4; i++) {
      for (int j = 0; j < 8; j++) {
        int num;
        cin >> num;
        dq[i].push_back(num);
      }
    }

    for (int i = 0; i < K; i++) {
      int index, direction;
      cin >> index >> direction;

      // 1. index 자석 회전
      // 2. 왼쪽(0 ~ index - 1) 자석 회전
      // 3. 오른쪽(index + 1, 4) 자석 회전

      // 함수들을 빼보자
      // 필요한 함수
      // 0. 현재 자석을 기점으로 다른 자석까지 모두 돌려야하는 지 여부를 저장

      turn_check(index, direction);
      // 1. index 자석을 시계방향으로 돌리는 함수

      // 2. index 자석을 반시계방향으로 돌리는 함수

      for (int j = 1; j <= 4; j++) {
        if (turn_flag[j] == 1) {
          right_turn(j);
        } else if (turn_flag[j] == -1) {
          left_turn(j);
        }
      }

      // 결과 출력
      int result = 0;
      for (int j = 1; j <= 4; j++) {
        if (dq[i][0])
          result += pow(2, i - 1);
      }

      cout << "#" << test_case << " " << result << "\n";
    }
  }

  return 0;
}