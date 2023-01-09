#include <iostream>
#include <vector>

constexpr int MAX = 51;

std::vector<int> nums, ops;
std::string str;

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> str;
    std::cout << str << '\n'
              << str.length() << '\n';
}
