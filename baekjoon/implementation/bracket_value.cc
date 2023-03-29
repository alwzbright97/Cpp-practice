#include <iostream>
#include <stack>
#include <string>

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::string str;
  std::stack<char> stack;

  std::cin >> str;

  int answer = 0;
  int count = 1;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(') {
      count *= 2;
      stack.push('(');
    }

    else if (str[i] == '[') {
      count *= 3;
      stack.push('[');
    }

    else if (str[i] == ')') {
      if (stack.empty() || stack.top() != '(') {
        answer = 0;
        break;
      }

      if (str[i - 1] == '(') {
        answer += count;
        count /= 2;
        stack.pop();
      } else {
        count /= 2;
        stack.pop();
      }
    }

    else if (str[i] == ']') {
      if (stack.empty() || stack.top() != '[') {
        answer = 0;
        break;
      }

      if (str[i - 1] == '[') {
        answer += count;
        count /= 3;
        stack.pop();
      } else {
        count /= 3;
        stack.pop();
      }
    }
  }

  if (!stack.empty())
    answer = 0;

  std::cout << answer;

  return 0;
}