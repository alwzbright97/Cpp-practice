#include <iostream>

constexpr int MAX = 200001;

char string[MAX];
int alphabet[26][MAX] = {0};

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int q;

    std::cin >> string >> q;

    for (int i = 1; string[i - 1]; i++)
    {
        int character = string[i - 1] - 'a';
        for (int j = 0; j < 26; j++)
        {
            if (j == character)
            {
                alphabet[j][i] = alphabet[j][i - 1] + 1;
            }
            else
            {
                alphabet[j][i] = alphabet[j][i - 1];
            }
        }
    }

    /* for (int j = 97; j < 123; j++)
    {
        std::cout << (char)j << ' ';
    }
    std::cout << '\n';

    for (int i = 1; string[i - 1]; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            std::cout << alphabet[j][i] << ' ';
        }
        std::cout << '\n';
    } */

    char tmp_char;
    int tmp_int, l, r;
    for (int i = 0; i < q; i++)
    {
        std::cin >> tmp_char >> l >> r;
        tmp_int = tmp_char - 'a';

        std::cout << alphabet[tmp_int][r + 1] - alphabet[tmp_int][l] << '\n';
    }
}