#include <iostream>
#include <vector>

std::vector<int> identity_matrix(int size)
{
    std::vector<int> v;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
        }
    }

    return v;
}

std::vector<int> mat_mul_with_mod(std::vector<int> v1, std::vector<int> v2, int size, int mod)
{
    std::vector<int> return_v;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int value = 0;
            for (int k = 0; k < size; k++)
            {
                // value += arr_1[i][k] * arr_2[k][j];
                value += v1[size * i + k] * v2[size * k + j];
            }

            value = value % mod;
            
            return_v.push_back(value);
        }
    }
    

    return return_v;
}

std::vector<int> recursive(std::vector<int> v, long exponent, int size, int mod)
{
    if (!exponent)
    {
        return identity_matrix(size);
    }
    else if (exponent == 1)
    {
        return mat_mul_with_mod(identity_matrix(size), v, size, mod);
    }
    

    std::vector<int> return_v = recursive(v, exponent / 2, size, mod);

    if (exponent & 1)
    {
        return mat_mul_with_mod(mat_mul_with_mod(v, return_v, size, mod), return_v, size, mod);
    }
    else
    {
        return mat_mul_with_mod(return_v, return_v, size, mod);
    }

    return v;
}

int main()
{
    int N;
    long B;

    std::cin >> N >> B;

    int a;
    std::vector<int> v;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {    
            std::cin >> a;
            v.push_back(a);
        }
    }

    v = recursive(v, B, N, 1000);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << v[N * i + j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}