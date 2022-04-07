#include <iostream>
#include <cmath>
int main() {
    int N;
    int place;
    int sum;
    bool flag = true;

    std::cin >> N;
    for (place = 7; place > 0; place--) {
        if ((N / std::pow(10, place - 1)) > 1) {
            break;
        }
    }
    // std::cout << place << '\n';

    for (int i = N - (9 * place); i < N; i++) {
        int temp = i;
        int digit = i;
        for (int j = place; j >= 0; j--) {
            digit += temp / std::pow(10, j);
            temp = temp % (int)std::pow(10, j);
        }

        if (digit == N) {
            flag = false;
            std::cout << i;
            break;
        }
    }
    if (flag) std::cout << 0;

    return 0;
}