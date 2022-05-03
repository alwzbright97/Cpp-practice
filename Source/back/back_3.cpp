#include <iostream>

constexpr int MAX = 8;
int arr[MAX] = {0};
int N, M;

void dfs(int count)
{
    if (M == count)
    {
        for (int i = 0; i < M; i++)
            std::cout << arr[i] << ' ';
        std::cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        arr[count] = i;
        dfs(count + 1);
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    std::cin >> N >> M;
    dfs(0);
}