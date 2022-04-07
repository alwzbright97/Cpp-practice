#define PI 3.1415926535897932
#include <iostream>

int main() {
    double r;
    std::cin >> r;
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << r * r * PI << '\n' << 2 * r * r;
}