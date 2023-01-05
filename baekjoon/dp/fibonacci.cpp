#include <iostream>

constexpr int LIMIT = 41;

int T, N;
unsigned int arr[LIMIT] = {
    0,
    1,
};

unsigned int fibonacci(int n)
{
    if (n < 2)
    {
        return arr[n];
    }

    if (arr[n] != 0)
    {
        return arr[n];
    }
    else
    {
        return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        std::cin >> N;
        if (N == 0)
        {
            std::cout << "1 0\n";
        }
        else if (N == 1)
        {
            std::cout << "0 1\n";
        }
        else
        {
            fibonacci(N);
            std::cout << arr[N - 1] << ' ' << arr[N] << '\n';
        }
    }
}
