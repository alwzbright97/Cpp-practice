#include <iostream>

constexpr int MAX = 101;

char str[MAX];

bool check()
{
    int stk[MAX] = {0};
    int ptr = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            if (str[i] == '(')
            {
                stk[ptr++] = 1;
            }
            else if (str[i] == '[')
            {
                stk[ptr++] = 2;
            }
        }

        if (str[i] == ')' || str[i] == ']')
        {
            if (str[i] == ')')
            {
                if (stk[ptr - 1] == 1)
                {
                    stk[--ptr] = 0;
                }
                else
                    return false;
            }
            else if (str[i] == ']')
            {
                if (stk[ptr - 1] == 2)
                {
                    stk[--ptr] = 0;
                }
                else
                    return false;
            }
        }
    }

    if (ptr == 0)
    {
        return true;
    }

    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    while (true)
    {
        std::cin.getline(str, MAX, '\n');

        if (str[0] == '.')
        {
            break;
        }

        if (check())
        {
            std::cout << "yes\n";
        }
        else
        {
            std::cout << "no\n";
        }
    }

    return 0;
}