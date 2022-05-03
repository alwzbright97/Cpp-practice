#include <iostream>
#include <thread>

int main()
{
    unsigned int nthreads = std::thread::hardware_concurrency();

    std::cout << "Num Threads : " << nthreads << '\n';

    return 0;
}