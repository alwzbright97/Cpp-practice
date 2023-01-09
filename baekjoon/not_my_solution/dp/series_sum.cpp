#include <iostream>

constexpr int MAX = 100001;

int dp[MAX] = {0};
int series[MAX];

int main()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> series[i];
        dp[i] = series[i];
    }

    int max = series[0];

    for (int i = 0; i < N; i++)
    {
        dp[i] = std::max(dp[i], dp[i - 1] + series[i]);
        if (dp[i] > max)
        {
            max = dp[i];
        }
    }

    std::cout << max;

    return 0;
}