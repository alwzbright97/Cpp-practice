#include <iostream>

#include "shape.hpp"

int main() {
    Rectangle rectangle(5, 6);
    std::cout << "Get size : " << rectangle.GetSize() << std::endl;
    return 0;
}