#include <iostream>

int main() {
    int x0, x1, x2, y0, y1, y2;

    int x, y;

    std::cin >> x0 >> y0;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;

    if (x0 == x1) x = x2;
    else if (x1 == x2) x = x0;
    else x = x1;
    
    if (y0 == y1) y = y2;
    else if (y1 == y2) y = y0;
    else y = y1;

    std::cout << x << ' ' << y; 
}