#include <iostream>

constexpr int LIMIT = 101;

long long int len[101] = {0, 1, 1, 1};
int N;
long long int func(int n)
{
    if (len[n] != 0)
    {
        return len[n];
    }
    else
    {
        return len[n] = func(n - 2) + func(n - 3);
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        std::cin >> N;
        std::cout << func(N) << '\n';
    }

    return 0;
}