#include <iostream>

int* factorial(int* data) {
    if (data[1] == 1) {
        return data;
    }
    else {
        data[0] *= data[1];
        data[1] -= 1;

        factorial(data);
    }
}


int main() {
    int N;
    std::cin >> N;

    int* data = new int[2];
    data[1] = N;
    data[0] = 1;

    data = factorial(data);

    std::cout << data[0] << std::endl;
}