#include <iostream>
#include <string>

constexpr int MAX = 64;
int arr[MAX][MAX];

void input(int N)
{

    return;
}

void solve(int col, int row, int size)
{
    int check = arr[row][col];
    for (int i = row; i < row + size; i++)
    {
        for (int j = col; j < col + size; j++)
        {
            if (check ^ arr[i][j])
            {
                std::cout << "(";
                solve(col, row, size / 2);
                solve(col + size / 2, row, size / 2);
                solve(col, row + size / 2, size / 2);
                solve(col + size / 2, row + size / 2, size / 2);
                std::cout << ")";
                return ;
            }
        }
    }

    std::cout << check;
}


int main() 
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;

    std::cin >> N;

    // input
    std::string s;
    for (int row = 0; row < N; row++)
    {
        std::cin >> s;
        for (int col = 0; col < N; col++)
        {
            arr[row][col] = (s[col]) - '0';
        }
    }

    // solve
    solve(0, 0, N);

    return 0;
}