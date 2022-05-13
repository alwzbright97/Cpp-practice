#include <iostream>

int arr[22][22][22] = {0};

int func(int a, int b, int c)
{

    if (a < 0)
        a = 0;
    else if (a > 20)
        a = 21;
    if (b < 0)
        b = 0;
    else if (b > 20)
        b = 21;
    if (c < 0)
        c = 0;
    else if (c > 20)
        c = 21;

    if (arr[a][b][c] != 0)
        return arr[a][b][c];

    if (a <= 0 || b <= 0 || c <= 0)
    {
        return arr[a][b][c] = 1;
    }
    else if (a > 20 || b > 20 || c > 20)
    {
        return arr[a][b][c] = func(20, 20, 20);
    }
    else if (a < b && b < c)
    {
        return arr[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
    }
    else
    {
        return arr[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
    }
}
int main()
{
    int a, b, c;
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    while (true)
    {
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            return 0;
        else
        {
            std::cout << "w(" << a << ", " << b << ", " << c << ") = " << func(a, b, c) << '\n';
        }
    }
}