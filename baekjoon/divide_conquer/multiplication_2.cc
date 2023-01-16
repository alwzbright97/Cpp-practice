// divide and conquer method
#include <iostream>

long long exponetiation(int base, int exponent, int mod)
{
    if (!exponent)
    {
        return 1;
    }
    
    long long res = exponetiation(base, exponent / 2, mod);

    if (exponent & 1)
    {
        return ((base % mod) * ((res * res) % mod)) % mod;
    }
    else
    {
        return (res * res) % mod;
    }
}

int main()
{
    int A, B, C;
    
    std::cin >> A >> B >> C;

    std::cout << exponetiation(A, B, C);

    return 0;
}