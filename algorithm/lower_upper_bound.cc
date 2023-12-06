/*
lower_bound : num 이상인 숫자가 어디서부터 시작되는가

upper_bound : num 초과인 숫자가 어디서부터 시작되는가

*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, Q;

vector<long long> v;

int lowerBound(int num) {
  int low = 0, high = N;
  while (low < high) {
    int mid = (low + high) / 2;
    if (v[mid] < num) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

int upperBound(int num) {
  int low = 0, high = N - 1;
  while (low < high) {
    int mid = (low + high) / 2;
    if (v[mid] <= num) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}

int main(int argc, char** argv) {
  cin >> N >> Q;

  v = vector<long long>(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";

  for (int i = 0; i < Q; i++) {
    int small, large;
    cin >> small >> large;

    int index_s = lowerBound(small);
    int index_l = lowerBound(large + 1);

    cout << index_s << " : " << index_l << "\n";
  }

  return 0;
}