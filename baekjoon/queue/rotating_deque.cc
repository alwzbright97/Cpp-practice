#include <iostream>
#include <deque>
#include <string>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N, M;
    int answer = 0;

    std::deque<int> deq;

    std::cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        deq.push_back(i);
    }

    while (M--)
    {
        int target;
        std::cin >> target;

        int i = 0;

        while (deq.front() != target)
        {
            deq.push_back(deq.front());
            deq.pop_front();
            i++;
        }
        
        if (i >= (deq.size() - i))
        {
            answer += (deq.size() - i);
        }
        else
        {
            answer += i;
        }

        deq.pop_front();
    }

    std::cout << answer;

    return 0;
}