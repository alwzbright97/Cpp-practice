#include <iostream>

constexpr int MAX = 100001;

int arr[MAX] = {0};
int ptr = 0;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    int tmp;
    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp;

        if (tmp == 0)
            arr[--ptr] = 0;
        else
            arr[ptr++] = tmp;
    }

    int sum = 0;

    for (int i = 0; i < ptr; i++)
    {
        sum += arr[i];
    }

    std::cout << sum;

    return 0;
}