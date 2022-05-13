#include <iostream>

int N, stat[20][20] = {0};
bool player[20] = {0};

int min = 10000;
void dfs(int count, int index)
{
    if (count == N / 2)
    {
        int score_s = 0, score_l = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (player[i] && player[j])
                    score_s += stat[i][j];
                if (!player[i] && !player[j])
                    score_l += stat[i][j];
            }
        }
        int value = std::abs(score_s - score_l);
        if (value < min)
        {
            min = value;
            /*
            std::cout << "Min: " << min << '\n';
            for (int i = 0; i < N; i++)
            {
                if (player[i])
                    std::cout << "1" << ' ';
                else
                    std::cout << "2" << ' ';
            }
            std::cout << '\n';
            */
        }

        return;
    }
    for (int i = index; i < N; i++)
    {
        player[i] = true;
        dfs(count + 1, i + 1);
        player[i] = false;
    }
}
int main()
{
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> stat[i][j];
        }
    }

    /*
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << stat[i][j] << ' ';
        }
        std::cout << '\n';
    }
    */
    dfs(0, 0);
    // std::cout << "Value\n";
    std::cout << min << '\n';

    return 0;
}