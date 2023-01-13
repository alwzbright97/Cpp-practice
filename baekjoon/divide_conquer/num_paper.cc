#include <iostream>

constexpr int MAX = 2197;
short arr[MAX][MAX];

int zero = 0, positive = 0, negative = 0;

void solve(int row, int col, int size)
{   
    int first = arr[row][col];
    for (int i = row; i < row + size; i++)
    {
        for (int j = col; j < col + size; j++)
        {
            if (first != arr[i][j])
            {
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        solve(row + ((size / 3) * x), col + ((size / 3) * y), size / 3);
                    }
                }
                return;
            }
        }
    }

    if (first == 0)
    {
        zero++;
        // std::cout << "row: " << row << " col: " << col << " size: " << size << " 0\n";
    }
    else if (first == 1)
    {
        positive++;
        // std::cout << "row: " << row << " col: " << col << " size: " << size << " +\n";
    }
    else // (first == -1)
    {
        negative++;
        // std::cout << "row: " << row << " col: " << col << " size: " << size << " -\n";
    }

    return;
}

int main()
{
    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    solve(0, 0, N);

    std::cout << negative << "\n"
              << zero << "\n"
              << positive;

    return 0;
}