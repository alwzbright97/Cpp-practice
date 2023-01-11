#include <iostream>
#include <deque>
#include <queue>
#include <string>

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int T;
    std::string p_input, x_input;

    std::cin >> T;

    while (T--)
    {
        std::queue<char> Q_char;
        std::deque<int>  Q_num;
        int N;
        int D_count = 0;
        int size;
        std::cin >> p_input >> N >> x_input;


        // p_input : string to queue
        for (int i = 0; i < p_input.size(); i++)
        {
            Q_char.push(p_input.at(i));
            if (p_input.at(i) == 'D')
            {
                D_count++;
            }
        }

        // Exception : Error or size == 0
        if (D_count > N)
        {
            std::cout << "error\n";
            continue;
        }
        else if (D_count == N || (D_count == 0 && N == 0))
        {
            std::cout << "[]\n";
            continue;
        }

        // x_input : array_string to queue
        x_input = x_input.substr(1, x_input.size() - 2);

        int pos;
        int cur = 0;
        while ((pos = x_input.find(',', cur)) != std::string::npos)
        {
            int len = pos - cur;

            Q_num.push_back(std::stoi(x_input.substr(cur, len)));
            cur = pos + 1;
        }
        Q_num.push_back(std::stoi(x_input.substr(cur)));

        size = Q_char.size();
        // Process
        int dir = 0;
        for (int i = 0; i < size; i++)
        {
            // std::cout << "i : " << i << "char :" << Q_char.front() << "\n";
            // Reverse
            if (Q_char.front() == 'R')
            {
                Q_char.pop();
                dir++;
            }
            // Draw
            else
            {
                if (dir & 1)
                {
                    // std::cout << "pop : " << Q_num.back() << "\n";
                    Q_char.pop();
                    Q_num.pop_back();
                }
                else
                {
                    // std::cout << "pop : " << Q_num.front() << "\n";
                    Q_char.pop();
                    Q_num.pop_front();
                }
            }
        }

        
        size = Q_num.size();
        // Print
        std::cout << "[";
        if (dir & 1)
        {
            for (int i = 1; i < size; i++)
            {
                std::cout << Q_num.back() << ",";
                Q_num.pop_back();
            }
            std::cout << Q_num.back();
        }
        else
        {
            for (int i = 1; i < size; i++)
            {
                std::cout << Q_num.front() << ",";
                Q_num.pop_front();
            }
            std::cout << Q_num.front();
        }
        std::cout << "]\n";
    }

    return 0;
}