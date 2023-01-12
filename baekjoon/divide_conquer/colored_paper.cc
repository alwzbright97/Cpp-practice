#include <iostream>
#include <vector>

constexpr int MAX = 128;
bool arr[MAX][MAX];
int white = 0, blue = 0;

bool is_equal(const std::vector<int>& vector)
{
    const auto& first = vector[0];
    int size = vector.size();
    for (int i = 1; i < size; i++)
    {
        if (first != vector[i])
        {
            return 0;
        }
    }
    return 1;
    
}

int func(int row, int col, int size)
{
    // std::cout << "row : " << row << " col: " << col << " size: " << size << "\n";

    if (size == 1)
    {
        if (arr[row][col] == 0)
        {
            return 0;
        }
        else // arr[row][col] == 1
        {
            return 1;
        }
    }

    size = size / 2;
    
    std::vector<int> vector(4);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            vector[i * 2 + j] = func(row + (size * i), col + (size * j), size);
        }
    }

    if (is_equal(vector))
    {
        return vector[0];
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (vector[i] == 0)
            {
                white++;
            }
            else if (vector[i] == 1)
            {
                blue++;
            }
        }
        return 2;
    }
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    int retval = func(0, 0, N);
    
    if (retval == 0)
    {
        white++;
    }
    else if (retval == 1)
    {
        blue++;
    }

    std::cout << white << "\n" << blue << "\n";
    
    return 0;
}