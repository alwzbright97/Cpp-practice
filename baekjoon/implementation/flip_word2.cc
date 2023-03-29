#include <iostream>
#include <stack>
#include <string>

#define endl '\n'

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  string str;
  stack<char> s;

  bool isFlip = true;
  int ptr = 0;

  getline(cin, str);

  for (int i = 0; i < str.length(); i++) {

    if (str[i] == '<') {
      isFlip = false;

      while (!s.empty()) {
        str[ptr] = s.top();
        ptr++;
        s.pop();
      }
      ptr++;
    }

    else if (str[i] == '>') {
      isFlip = true;
      ptr++;
    }

    else if (str[i] == ' ' && isFlip) {
      while (!s.empty()) {
        str[ptr] = s.top();
        ptr++;
        s.pop();
      }
      ptr++;
    }

    else if (isFlip) {
      s.push(str[i]);
    }

    else {
      ptr++;
    }
  }

  while (!s.empty()) {
    str[ptr] = s.top();
    ptr++;
    s.pop();
  }

  cout << str << endl;

  return 0;
}