#include <deque>
#include <iostream>
#include <string>
#include <vector>

constexpr int N_GEAR = 4;
constexpr int N_TOOTH = 8;

int is_rotate[N_GEAR];
bool visited[N_GEAR];
std::deque<bool> gear[N_GEAR];

void rotate() {
  for (int i = 0; i < N_GEAR; i++) {
    if (is_rotate[i] == 1) {
      gear[i].push_front(gear[i].back());
      gear[i].pop_back();
    } else if (is_rotate[i] == -1) {
      gear[i].push_back(gear[i].front());
      gear[i].pop_front();
    }
    visited[i] = false;
  }
}

void isRotate(int here, int direction) {
  is_rotate[here] = direction;
  visited[here] = true;

  int left = here - 1, right = here + 1;
  // left
  if (left >= 0 && !visited[left]) {
    if (gear[here][6] != gear[left][2]) {
      isRotate(left, -direction);
    } else {
      isRotate(left, 0);
    }
  }
  // right
  if (right < N_GEAR && !visited[right]) {
    if (gear[here][2] != gear[right][6]) {
      isRotate(right, -direction);
    } else {
      isRotate(right, 0);
    }
  }
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  for (int i = 0; i < N_GEAR; i++) {
    std::string str;
    std::cin >> str;
    for (int j = 0; j < N_TOOTH; j++) {
      gear[i].push_back(str[j] - '0');
    }
  }

  int K;
  std::cin >> K;
  for (int i = 0; i < K; i++) {
    int n_gear, direction;
    std::cin >> n_gear >> direction;
    isRotate(n_gear - 1, direction);
    rotate();
  }

  int score = 0, ptr = 1;
  for (int i = 0; i < N_GEAR; i++) {
    if (gear[i].front()) {
      score += ptr;
    }
    ptr = ptr << 1;
  }

  std::cout << score << "\n";

  return 0;
}