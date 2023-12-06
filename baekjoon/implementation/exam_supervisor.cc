#include <iostream>

using namespace std;

#define MAX 1000001
#define endl '\n'

int N, B, C;
int n_people[MAX];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> n_people[i];
  }

  cin >> B >> C;

  long long answer = 0;

  for (int i = 0; i < N; i++) {
    n_people[i] -= B;
    answer += 1;

    if (n_people[i] > 0) {
      answer += (n_people[i] / C);
      n_people[i] -= C * (n_people[i] / C);
    }

    if (n_people[i] > 0) {
      answer += 1;
    }
  }

  cout << answer << endl;

  return 0;
}
