// modular exponentiation
#include <iostream>

long long modular_exponent(long long base, long long exponent, int mod)
{
    long long res = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
        {
            res = (res * base) % mod;
        }
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return res;
}

int main()
{
    int A, B, C;

    std::cin >> A >> B >> C;

    std::cout << modular_exponent(A, B, C);

    return 0;
}