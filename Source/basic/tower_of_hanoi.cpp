#include <iostream>

void move(int N, int start, int to) {
    std::cout << N << " ring from " << start << " to " << to << '\n';
}
void hanoi(int N, int start, int via, int to) {
    if (N == 1) {
        move(1, start, to);
    }
    else {
        hanoi(N - 1, start , via, to);
        move(N, start, to);
        hanoi(N - 1, via, to, start);
    }
}

int main() {
    int N;
    std::cin >> N;

    hanoi(N, 1, 2, 3);

}