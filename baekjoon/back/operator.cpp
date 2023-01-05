#include <iostream>

int N, A[100], n_oper[4];
int value[100] = {0};
int max = -1000000000, min = 1000000000;
int count;

void oper(int count)
{
    if (count == N - 1)
    {
        if (value[count] >= max)
            max = value[count];
        if (value[count] <= min)
            min = value[count];
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (n_oper[i])
        {
            n_oper[i]--;
            if (i == 0)
            {
                value[count + 1] = value[count] + A[count + 1];
                oper(count + 1);
            }
            else if (i == 1)
            {
                value[count + 1] = value[count] - A[count + 1];
                oper(count + 1);
            }
            else if (i == 2)
            {
                value[count + 1] = value[count] * A[count + 1];
                oper(count + 1);
            }
            else if (i == 3)
            {
                value[count + 1] = value[count] / A[count + 1];
                oper(count + 1);
            }

            n_oper[i]++;
        }
    }
    return;
}

int main()
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }
    for (int i = 0; i < 4; i++)
    {
        std::cin >> n_oper[i];
    }
    value[0] = A[0];
    oper(0);

    std::cout << max << '\n'
              << min << '\n';
    /*
    std::cout << "Answer" << '\n'
              << max << '\n'
              << min << '\n';

    std::cout << "Value\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << value[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "A\n";
    for (int i = 0; i < N; i++)
    {
        std::cout << A[i] << ' ';
    }
    std::cout << '\n';
    */
}