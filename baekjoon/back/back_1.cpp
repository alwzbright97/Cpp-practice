#include <iostream>

constexpr int MAX = 9;
int arr[MAX] = {0};
bool visited[MAX] = {0};
int M, N; // M : Depth, M : Number

void dfs(int count)
{
    if (count == M)
    {
        for (int i = 0; i < M; i++)
            std::cout << arr[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[count] = i;
            dfs(count + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> M;
    dfs(0);
}