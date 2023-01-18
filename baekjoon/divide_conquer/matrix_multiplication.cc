#include <iostream>
#include <vector>

int N, M, K;

int matrix_a[100][100];
int matrix_b[100][100];
int matrix_return[100][100];

void mat_mul()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int sum = 0;
            for (int k = 0; k < M; k++)
            {
                sum += matrix_a[i][k] * matrix_b[k][j];
            }

            matrix_return[i][j] = sum;
        }
    }

    return;
}

int main()
{
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> matrix_a[i][j];
        }
    }

    std::cin >> M >> K;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            std::cin >> matrix_b[i][j];
        }
    }


    mat_mul();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            std::cout << matrix_return[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}