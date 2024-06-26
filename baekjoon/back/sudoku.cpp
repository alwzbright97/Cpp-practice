#include <iostream>
#include <utility>
#include <vector>

int board[9][9];
std::vector<std::pair<int, int>> points;
int count = 0;
bool found = false;

bool check(std::pair<int, int> p)
{
    int square_x = p.first / 3;
    int square_y = p.second / 3;
    for (int i = 0; i < 9; i++)
    {
        if (board[p.first][i] == board[p.first][p.second] && i != p.second)
            return false;
        if (board[i][p.second] == board[p.first][p.second] && i != p.first)
            return false;
    }
    for (int i = 3 * square_x; i < 3 * square_x + 3; i++)
    {
        for (int j = 3 * square_y; j < 3 * square_y + 3; j++)
        {
            if (board[i][j] == board[p.first][p.second])
            {
                if (i != p.first && j != p.second)
                    return false;
            }
        }
    }
    return true;
}

void sudoku(int N)
{
    if (N == count)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                std::cout << board[i][j] << ' ';
            }
            std::cout << '\n';
        }
        found = true;
        return;
    }
    for (int j = 0; j <= 9; j++)
    {
        board[points[N].first][points[N].second] = j;
        if (check(points[N]))
            sudoku(N + 1);
        if (found)
            return;
    }

    board[points[N].first][points[N].second] = 0;
    return;
}
int main()
{
    std::pair<int, int> point;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cin >> board[i][j];
            if (board[i][j] == 0)
            {
                count++;
                point.first = i;
                point.second = j;
                points.push_back(point);
            }
        }
    }
    sudoku(0);
}