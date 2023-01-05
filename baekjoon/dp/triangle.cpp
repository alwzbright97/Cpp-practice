#include <iostream>

constexpr int MAX = 501;

int tri[MAX][MAX] = {0};

int max = 0;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int N;
    int tmp;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cin >> tmp;
            if (i == 0)
            {
                tri[i][j] = tmp;
            }
            else if (j == 0)
            {
                tri[i][j] = tri[i - 1][j] + tmp;
            }
            else if (j == i)
            {
                tri[i][j] = tri[i - 1][j - 1] + tmp;
            }
            else
            {
                tri[i][j] = std::max(tri[i - 1][j - 1] + tmp, tri[i - 1][j] + tmp);
            }

            if (i == N - 1)
            {
                if (tri[i][j] > max)
                    max = tri[i][j];
            }
        }
    }

    std::cout << max;

    return 0;
}