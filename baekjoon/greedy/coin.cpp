#include <iostream>

constexpr int MAX = 11;

int coin[MAX];

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int count = 0;
    int N, K;
    std::cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        std::cin >> coin[i];
    }

    for (int i = N; i > 0; i--)
    {
        count += (K / coin[i]);
        K = K % coin[i];
    }

    std::cout << count;
}