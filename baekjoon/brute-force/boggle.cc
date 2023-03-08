#include <algorithm>
#include <iostream>
#include <vector>

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int num_words, num_array;

std::vector<std::string> arr;
std::vector<std::string> words;
std::vector<std::vector<bool>> visited;
std::vector<bool> findable_words;

bool dfs(int x, int y, const std::string word) {
  if (word[0] != arr[x][y])
    return false;

  if (word.size() == 1)
    return true;

  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < num_array && ny >= 0 && ny < num_array &&
        !visited[nx][ny]) {
      visited[nx][ny] = true;
      if (dfs(nx, ny, word.substr(1))) {
        visited[nx][ny] = false;
        return true;
      }
      visited[nx][ny] = false;
    }
  }

  return false;
}

bool isFindable(const std::string word) {
  std::string actual_word;
  char prev_c = '\0';
  for (char c : word) {
    if (prev_c != 'q')
      actual_word.push_back(c);
    else if (c != 'u')
      return false;
    prev_c = c;
  }
  if (prev_c == 'q')
    return false;

  for (int i = 0; i < num_array; i++) {
    for (int j = 0; j < num_array; j++) {
      visited[i][j] = true;
      if (dfs(i, j, actual_word)) {
        visited[i][j] = false;
        return true;
      }
      visited[i][j] = false;
    }
  }

  return false;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::cin >> num_words;
  words.resize(num_words);
  for (int i = 0; i < num_words; i++) {
    std::cin >> words[i];
  }

  std::sort(words.begin(), words.end());

  while (true) {
    std::cin >> num_array;

    if (!num_array)
      break;

    arr.resize(num_array);
    visited.resize(num_array);
    findable_words = std::vector<bool>(num_words, false);
    for (int i = 0; i < num_array; i++) {
      std::cin >> arr[i];
      visited[i] = std::vector<bool>(num_array, false);
    }

    for (int i = 0; i < num_words; i++) {
      if (isFindable(words[i]))
        // std::cout << words[i] << "\t: YES\n";
        std::cout << words[i] << "\n";
      // else
      // std::cout << words[i] << "\t: NO \n";
    }
    std::cout << "-\n";
  }

  return 0;
}