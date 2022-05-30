#include <iostream>
#include <string>
constexpr int MAX = 100000;

int stack[MAX] = {0};
int N, num, ptr = 0;
std::string command;

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> command;

        if (command == "push")
        {
            std::cin >> num;
            stack[ptr++] = num;
        }
        else if (command == "pop")
        {
            if (ptr == 0)
                std::cout << "-1\n";
            else
                std::cout << stack[--ptr] << '\n';
        }
        else if (command == "size")
            std::cout << ptr << '\n';
        else if (command == "empty")
        {
            if (ptr == 0)
                std::cout << "1\n";
            else
                std::cout << "0\n";
        }
        else if (command == "top")
        {
            if (ptr == 0)
                std::cout << "-1\n";
            else
                std::cout << stack[ptr - 1] << '\n';
        }
    }

    return 0;
}
