#include <iostream>

constexpr int MAX = 1001;

long long count[MAX] = {0};
long long sum, ans;
int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, M, tmp;
    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp;
        sum += tmp;
        count[sum % M]++;
    }

    for (int i = 0; i < MAX; i++)
    {
        ans += count[i] * (count[i] - 1) / 2;
    }
    
    std::cout << count[0] + ans;
}