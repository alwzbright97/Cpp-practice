#include <iostream>

constexpr int LIMIT = 1000001;

int tile[LIMIT] = {0, 1, 2};
int N;
void func()
{
    for (int i = 3; i <= N; i++)
    {
        tile[i] = (tile[i - 1] + tile[i - 2]) % 15746;
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    func();
    std::cout << tile[N];
}