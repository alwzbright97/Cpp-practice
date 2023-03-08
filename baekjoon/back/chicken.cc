#include <climits>
#include <iostream>
#include <vector>

constexpr int MAX = 51;

int N, M;
int city[MAX][MAX];
int n_chicken, n_house, answer = INT_MAX;
std::vector<std::pair<int, int>> chicken;
std::vector<std::pair<int, int>> house;
std::vector<int> selected_chichen;

void pickChicken(int n, int ptr) {

  if (n == M) {
    int city_length = 0;
    for (int i = 0; i < n_house; i++) {
      int length = N * 2;

      int house_y = house[i].first;
      int house_x = house[i].second;
      for (int j = 0; j < M; j++) {
        int chicken_y = chicken[selected_chichen[j]].first;
        int chicken_x = chicken[selected_chichen[j]].second;

        length = std::min(length, std::abs(chicken_y - house_y) +
                                      std::abs(chicken_x - house_x));
      }
      city_length += length;
    }
    answer = std::min(city_length, answer);
    return;
  }

  if (ptr == n_chicken) {
    return;
  }

  selected_chichen.push_back(ptr);
  pickChicken(n + 1, ptr + 1);
  selected_chichen.pop_back();
  pickChicken(n, ptr + 1);

  return;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> N >> M;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < N; i++) {
      std::cin >> city[j][i];
      if (city[j][i] == 1) {
        house.push_back({j, i});
      } else if (city[j][i] == 2) {
        chicken.push_back({j, i});
      }
    }
  }

  n_chicken = chicken.size();
  n_house = house.size();

  pickChicken(0, 0);

  std::cout << answer << "\n";

  return 0;
}