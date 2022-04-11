#include <iostream>

void stars(int i, int j, int num) {
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        std::cout << ' ';
    }
    else {
        if (num / 3 == 0)
            std::cout << '*';
        else
            stars(i, j, num / 3);
    }
}

int main() {
    int num;
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            stars(i, j, num);
        }
        std::cout << '\n';
    }
}