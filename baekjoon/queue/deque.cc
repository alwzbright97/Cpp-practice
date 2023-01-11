#include <iostream>
#include <queue>
#include <string>

constexpr int MAX = 20000;

int ptr_head = 10000, ptr_tail = 10000;
int arr[MAX];

void func(std::string command) {
    if (command == "push_back")
    {
        std::cin >> arr[++ptr_tail];
        return;
    }
    else if (command == "push_front")
    {
        std::cin >> arr[ptr_head--];
        return;
    }
    else if (command == "pop_front")
    {
        if (ptr_tail - ptr_head == 0)
        {
            std::cout << -1 << "\n";
            return;
        }
        std::cout << arr[++ptr_head] << "\n";
        return;
    }
    else if (command == "pop_back")
    {
        if (ptr_tail - ptr_head == 0)
        {
            std::cout << -1 << "\n";
            return;
        }
        std::cout << arr[ptr_tail--]  << "\n";
    }
    else if (command == "size")
    {
        std::cout << ptr_tail - ptr_head << "\n";
        return;
    }
    else if (command == "empty")
    {
        if (ptr_tail - ptr_head)
        {
            std::cout << 0 << "\n";
            return;
        }
        std::cout << 1 << "\n";
        return;
    }
    else if (command == "front")
    {
        if (!(ptr_tail - ptr_head))
        {
            std::cout << -1 << "\n";
            return;
        }
        std::cout << arr[ptr_head + 1] << "\n";
        return;
    }
    else if (command == "back")
    {
        if (!(ptr_tail - ptr_head))
        {
            std::cout << -1 << "\n";
            return;
        }
        std::cout << arr[ptr_tail] << "\n";
        return;
    }
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::string command;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> command;
        func(command);
    }

    return 0;
}