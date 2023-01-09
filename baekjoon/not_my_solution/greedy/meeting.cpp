#include <iostream>
#include <vector>
#include <algorithm>
constexpr int MAX = 100001;

int main()
{
    int N, time_s, time_e;

    std::vector<std::pair<int, int>> schedule;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> time_s >> time_e;
        schedule.push_back(std::make_pair(time_e, time_s));
    }
    std::sort(schedule.begin(), schedule.end());

    int time = schedule[0].first;
    int count = 1;

    for (int i = 1; i < N; i++)
    {
        if (time <= schedule[i].second)
        {
            time = schedule[i].first;
            count++;
        }
    }

    std::cout << count;
}