#include <iostream>
#include <queue>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, K;
    
    std::queue<int> que;
    // input
    std::cin >> N >> K;

    // init
    for (int i = 1; i <= N; i++)
    {
        que.push(i);
    }
    
    std::cout << "<";
    // loop
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < K; j++)
        {
            que.push(que.front());
            que.pop();
        }
        std::cout << que.front();
        que.pop();
        if (i == N - 1)
            break;
        std::cout << ", ";
    }
    
    std::cout << ">";

    return 0;
}