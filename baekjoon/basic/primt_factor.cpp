#include <iostream>

int main() {
    int n;
    
    std::cin >> n;

    for (int i = 2; (i < n); i++) {
        if (n % i == 0) {
            n = n / i;
            std::cout << i << std::endl;
            i = 1;
        }

        if (n == 1) break;
    }

    if (n != 1) std::cout << n << std::endl;

    return 0;
}