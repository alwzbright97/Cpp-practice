#include <iostream>

constexpr int MAX = 51;

char str[MAX];

bool check()
{
    int ptr = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
        {
            ptr++;
        }
        else
        {
            if (ptr == 0)
            {
                return false;
            }
            ptr--;
        }
    }

    if (ptr == 0)
        return true;
    else
        return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> str;

        if (check())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}