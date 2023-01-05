#include <iostream>
int main() {
    bool flag = true;

    int length[3] = {0};

    while (flag) {
        std::cin >> length[0] >> length[1] >> length[2];

        if (length[0] == 0) { flag = false; break; }

        for (int i = 0; i < 2; i++) {
            if (length[i] > length[i + 1]) {
                int temp = length[i];
                length[i] = length[i + 1];
                length[i + 1] = temp;
            }
        }

        if (length[0] * length[0] + length[1] * length[1] == length[2] * length[2])
            std::cout << "right" << "\n";
        else
            std::cout << "wrong" << "\n";

    }
}