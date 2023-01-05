#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, tmp;
    std::vector<int> vector;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp;
        vector.push_back(tmp);
    }
    std::sort(vector.begin(), vector.end());

    int sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        sum += vector[i];
        count += sum;
    }

    std::cout << count;
}