#include <iostream>

constexpr int MAX = 100001;

int arr[MAX];

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        std::cin >> num;
        arr[i + 1] = arr[i] + num;
    }
    for (int i = 0; i < M; i++)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << arr[y] - arr[x - 1] << '\n';
    }

    return 0;
}