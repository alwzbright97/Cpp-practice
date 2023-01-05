#include <iostream>

constexpr int MAX = 1001;

int house[MAX][3];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    int cost[3];
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> cost[0] >> cost[1] >> cost[2];
        house[i][0] = std::min(house[i - 1][1], house[i - 1][2]) + cost[0];
        house[i][1] = std::min(house[i - 1][0], house[i - 1][2]) + cost[1];
        house[i][2] = std::min(house[i - 1][1], house[i - 1][0]) + cost[2];
    }

    std::cout << std::min(house[N][2], std::min(house[N][0], house[N][1]));

    return 0;
}