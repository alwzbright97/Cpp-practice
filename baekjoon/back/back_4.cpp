#include <iostream>

constexpr int MAX = 9;
int arr[MAX] = {0};
int M, N;

void dfs(int num, int count)
{
    if (count == M)
    {
        for (int i = 0; i < M; i++)
            std::cout << arr[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int i = num; i <= N; i++)
    {
        arr[count] = i;
        dfs(i, count + 1);
    }
}

int main()
{
    std::cin >> N >> M;
    dfs(1, 0);
}