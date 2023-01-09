#include <iostream>
#include <queue>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::queue<int> card;
    int N;

    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        card.push(i);
    }

    while(card.size() != 1) {
        card.pop();
        card.push(card.front());
        card.pop();   
    }

    std::cout << card.front() << "\n";

    return 0;
}