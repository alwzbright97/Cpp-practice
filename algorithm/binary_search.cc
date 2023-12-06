/*

binary search

Input:
N
N개의 Number
K
K개의 Number

10
20 22 23 24 4 4 5 7 8 10
10
1 2 3 4 5 6 7 8 9 10

Output
해당 숫자가 배열에 존재하는 경우 O
아닐 경우 X 출력

*/

#define MAX 100001

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> vec;

bool binary_search(int num) {
  int left = 0;
  int right = N - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (vec[mid] < num) {
      left = mid + 1;
    } else if (vec[mid] > num) {
      right = mid - 1;
    } else {
      return true;
    }
  }

  return false;
}

int main(int argc, char** argv) {
  cin >> N;

  vec = vector<int>(N);

  for (int i = 0; i < N; i++) {
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end());

  cin >> K;

  for (int i = 0; i < K; i++) {
    int num;
    cin >> num;
    if (binary_search(num))
      cout << 'O';
    else
      cout << 'X';
  }

  return 0;
}
