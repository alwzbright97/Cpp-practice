#include <iostream>

constexpr int MAX = 100001;

int arr[MAX] = {0};
char sign[MAX] = {0};
int N;

void func()
{
    int ptr = 0;
    int num = 0;
    int stk[MAX] = {0};
    int stk_count = 0;
    int count = 0;
    while (count != N)
    {
        if (num < arr[count])
        {
            stk[ptr++] = ++num;
            sign[stk_count++] = '+';
        }
        else if (stk[ptr - 1] == arr[count])
        {
            stk[--ptr] = 0;
            sign[stk_count++] = '-';
            count++;
        }
        else
        {
            std::cout << "NO\n";
            break;
        }
    }

    if (count == N)
    {
        for (int i = 0; i < stk_count; i++)
        {
            std::cout << sign[i] << '\n';
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    func();

    return 0;
}