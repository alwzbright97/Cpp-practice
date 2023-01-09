#include <iostream>
#include <queue>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, input;

    std::queue<int> router;

    std::cin >> N;

    while (true) {
        std::cin >> input;
        
        if (input == -1) {
            break;
        }
        else if (input == 0) {
            router.pop();
            continue;
        }

        if (router.size() == N) {
            continue;
        }

        router.push(input);
    }
    
    if (router.empty()) {
        std::cout << "empty";
        return 0;
    }

    while (!(router.empty()))
    {
        std::cout << router.front() << " ";
        router.pop();
    }
    
    return 0;
}