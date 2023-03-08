#include <iostream>
#include <string>

int panel[10];

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::string N;
  int answer = 0;
  std::cin >> N;

  for (char c : N) {
    if (c - '0' == 6 || c - '0' == 9) {
      if (panel[6] > panel[9])
        panel[9]++;
      else
        panel[6]++;
    } else {
      panel[c - '0']++;
    }
  }

  for (int i = 0; i < 10; i++) {
    answer = std::max(answer, panel[i]);
  }

  std::cout << answer;

  return 0;
}