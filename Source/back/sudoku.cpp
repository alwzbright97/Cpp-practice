#include <iostream>

bool nums[10] = {0};
int board[9][9];
void init()
{
    for (int i = 1; i <= 9; i++)
    {
        nums[i] = false;
    }
}
void check(int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        nums[board[x][i]] = true;
        nums[board[i][y]] = true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            nums[board[(x / 3) * 3 + i][(y / 3) * 3 + j]] = true;
        }
    }
}

bool complete()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;
}
void dfs()
{
    if (complete())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                std::cout << board[i][j] << ' ';
            }
            std::cout << '\n';
        }

        return;
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == 0)
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        check(i, j);
                        if (!nums[k])
                        {
                            board[i][j] = k;
                            init();
                            dfs();
                        }
                        init();
                    }
                }
            }
        }
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cin >> board[i][j];
        }
    }
    init();
    dfs();
}
