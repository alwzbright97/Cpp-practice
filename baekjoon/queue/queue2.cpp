#include <iostream>
#include <string>

constexpr int MAX = 2000000;
int ptr_s = 0, ptr_e = 0;
int arr[MAX] = {0};
int N, num;

void func(std::string command)
{
    if (command == "push")
    {
        std::cin >> num;
        arr[ptr_e++] = num;
    }
    else if (command == "pop")
    {
        if (ptr_e - ptr_s == 0)
        {
            std::cout << -1 << '\n';
            return;
        }
        std::cout << arr[ptr_s++] << '\n';
        return;
    }
    else if (command == "size")
    {
        std::cout << ptr_e - ptr_s << '\n';
    }
    else if (command == "empty")
    {
        if (ptr_e - ptr_s == 0)
            std::cout << 1 << '\n';
        else
            std::cout << 0 << '\n';
        return;
    }
    else if (command == "front")
    {
        if (ptr_e - ptr_s == 0)
            std::cout << -1 << '\n';
        else
            std::cout << arr[ptr_s] << '\n';
        return;
    }
    else if (command == "back")
    {
        if (ptr_e - ptr_s == 0)
            std::cout << -1 << '\n';
        else
            std::cout << arr[ptr_e - 1] << '\n';
        return;
    }
}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);
    std::string command;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> command;
        func(command);
    }

    return 0;
}