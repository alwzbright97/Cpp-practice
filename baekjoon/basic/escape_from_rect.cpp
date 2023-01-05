#include <iostream>

int main() {
    int x, y, w, h;

    int x_length, y_length;

    int min;

    std::cin >> x >> y >> w >> h;
    
    // x length
    if (x > w - x) x_length = w - x;
    else x_length = x;

    if (y > h - y) y_length = h - y;
    else y_length = y;

    if (x_length > y_length) min = y_length;
    else min = x_length;

    std::cout << min;

    return 0;
}