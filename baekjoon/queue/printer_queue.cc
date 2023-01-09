#include <iostream>
#include <queue>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int T;
    int N, M;

    int priority;
    int count;

    // std::pair<int(priority), int(order)>
    std::queue< std::pair<int, int> > q;


    // test case
    std::cin >> T;

    for (int j = 0; j < T; j++)
    {
        std::cin >> N >> M;

        // init
        q = std::queue< std::pair<int, int> >();
        count = 1;

        // input
        for (int k = 0; k < N; k++)
        {
            std::cin >> priority;
            q.push(std::pair<int, int>(priority, k));
        }

        // loop
        for (int k = 9; k > 0; k--)
        {
            for (int i = 0; i < q.size(); i++)
            {
                if (q.front().first == k)
                {
                    if (q.front().second == M)
                    {
                        k = 0;
                        break;
                    }
                    q.pop();
                    count++;
                    i = -1;
                    continue;
                }
                q.push(q.front());
                q.pop();
            }
        }

        std::cout << count << "\n";
    }

    return 0;
}