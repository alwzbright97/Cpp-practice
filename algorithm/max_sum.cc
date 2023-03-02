#include <climits>
#include <iostream>
#include <vector>

// 최대 연속 부분 구간 합 문제를 푸는 알고리즘

const int MIN = std::numeric_limits<int>::min();
// 1. A[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도: O(N^3)
int inefficientMaxSum(const std::vector<int> &A) {
  int N = A.size(), ret = MIN;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++)
        sum += A[k];

      ret = std::max(ret, sum);
    }
  }

  return ret;
}
// 2. A[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도: O(N^2)
int betterMaxSum(const std::vector<int> &A) {
  int N = A.size(), ret = MIN;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = i; j < N; j++) {
      sum += A[j];
      ret = std::max(sum, ret);
    }
  }

  return ret;
}
// 3. A[]의 연속된 부분 구간의 최대 합을 구한다. (분할 정복) 시간 복잡도: O(N
// log_2 N)
int fastMaxSum(const std::vector<int> &A, int low, int high) {
  // 기저 사례: 구간의 길이가 1일 경우
  if (low == high)
    return A[low];
  // 배열을 A[low,mid], A[mid+1, high]의 두 조각으로 나눈다.
  int mid = (low + high) / 2;
  // 두 부분에 모두 걸쳐 있는 최대 합 구간을 찾는다. 이 구간은 A[i, mid]와
  // A[mid+1, j]의 형태를 갖는 구간의 합으로 이루어 진다.

  int left = MIN, right = MIN;
  int sum;
  // A[i, mid] 형태를 갖는 최대 구간을 찾는다.
  sum = 0;
  for (int i = mid; i >= low; i--) {
    sum += A[i];
    left = std::max(left, sum);
  }
  // A[mid+1, j] 형태를 갖는 최대 구간을 찾는다.
  sum = 0;
  for (int j = mid + 1; j <= high; j++) {
    sum += A[j];
    right = std::max(right, sum);
  }
  // 최대 구간이 두 조각 중 하나에만 속해 있는 경우의 답을 재귀 호출로 찾는다.
  int single = std::max(fastMaxSum(A, low, mid), fastMaxSum(A, mid + 1, high));
  // 두 경우 중 최대치를 반환한다.
  return std::max(left + right, single);
}
// 4. A[]의 연속된 부분 구간의 최대 합을 구한다. (동적계획법) 시간 복잡도: O(N)
int fastestMaxSum(const std::vector<int> &A) {
  int N = A.size(), ret = MIN, psum = 0;
  for (int i = 0; i < N; i++) {
    psum = std::max(psum, 0) + A[i];
    ret = std::max(psum, ret);
  }

  return ret;
}