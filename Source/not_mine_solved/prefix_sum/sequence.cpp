#include <iostream>

constexpr int MAX = 100001;
int arr[MAX] = {0};

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    int N, K;
    std::cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    int start = 0;
    int sum = 0;
    int maxSum = -1e9;

    for (int i = 0; i < N; i++)
    {
        sum += arr[i];

        if (i > K - 2)
        {
            maxSum = Max(maxSum, sum);
            sum -= arr[start++];
        }
    }

    std::cout << maxSum;
}