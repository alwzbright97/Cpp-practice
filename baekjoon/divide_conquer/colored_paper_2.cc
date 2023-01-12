#include <iostream>
#include <string>

constexpr int MAX = 128;
int arr[MAX][MAX];
int white = 0, blue = 0;

void solve(int col, int row, int size)
{
    int check = arr[col][row];
    for (int i = col; i < col + size; i++)
    {
        for (int j = row; j < row + size; j++)
        {
            if (check ^ arr[i][j])
            {
                check = 2;
            }
            
            if (check == 2)
            {
                solve(col, row, size / 2);
                solve(col, row + size / 2, size / 2);
                solve(col + size / 2, row, size / 2);
                solve(col + size / 2, row + size / 2, size / 2);
                return;
            }
        }
    }

    if (check)
        blue++;
    else
        white++;
}

void input(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> arr[i][j];
        }
    }
}

int main() 
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;

    std::cin >> N;

    input(N);
    solve(0, 0, N);

    std::cout << white << "\n" << blue;

    return 0;
}