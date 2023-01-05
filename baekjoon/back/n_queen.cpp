#include <iostream>
#include <vector>

constexpr int MAX = 15;

int N;
int count = 0;
int col[MAX];

bool check(int num_queen)
{
    for (int i = 0; i < num_queen; i++)
    {
        if (col[i] == col[num_queen] || std::abs(col[num_queen] - col[i]) == num_queen - i)
            return false;
    }
    return true;
}

void n_queen(int num_queen)
{
    if (num_queen == N)
    {
        count++;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[num_queen] = i;
            if (check(num_queen))
                n_queen(num_queen + 1);
        }
    }
}
int main()
{
    std::cin >> N;
    n_queen(0);
    std::cout << count;
}