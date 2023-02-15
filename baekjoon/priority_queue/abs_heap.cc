#include <cmath>
#include <iostream>
constexpr int MAX = 100000;

int size = 0, arr[MAX];

/* void print_status() {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";

  return;
} */

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void insert(int x) {
  int child = size;
  int parent = (child - 1) >> 1;
  arr[size++] = x;

  while ((parent >= 0)) {
    if (std::abs(arr[child]) < std::abs(arr[parent])) {
      swap(&arr[child], &arr[parent]);
    } else if ((std::abs(arr[child]) == std::abs(arr[parent])) &&
               (arr[child] < arr[parent])) {
      swap(&arr[child], &arr[parent]);
    }
    child = parent;
    parent = (child - 1) >> 1;
  }

  // print_status();
}

int pop(void) {
  if (!size)
    return 0;

  int out = arr[0];
  arr[0] = 0;
  swap(&arr[0], &arr[--size]);

  int ptr = 0;

  while (ptr < size) {
    int left = (ptr << 1) + 1;
    int right = (ptr << 1) + 2;

    if (left < size || right < size) {
      int tmp = ptr;
      if ((left < size)) {
        if (std::abs(arr[left]) < std::abs(arr[tmp])) {
          tmp = left;
        } else if ((std::abs(arr[left]) == std::abs(arr[tmp])) &&
                   (arr[left] < arr[tmp])) {
          tmp = left;
        }
      }
      if ((right < size)) {
        if (std::abs(arr[right]) < std::abs(arr[tmp])) {
          tmp = right;
        } else if ((std::abs(arr[right]) == std::abs(arr[tmp])) &&
                   (arr[right] < arr[tmp])) {
          tmp = right;
        }
      }

      if (tmp == ptr)
        break;
      swap(&arr[tmp], &arr[ptr]);
      ptr = tmp;
    } else {
      break;
    }

    // std::cout << "\tsize: " << size << "\n"
    //           << "\tptr: " << size << "\n"
    //           << "\tleft: " << left << "\n"
    //           << "\tright: " << right << "\n";
  }

  // print_status();
  return out;
}

int main() {
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::ios::sync_with_stdio(false);

  int N, x;
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> x;

    if (x) {
      insert(x);
    } else {
      std::cout << pop() << "\n";
    }
  }

  return 0;
}