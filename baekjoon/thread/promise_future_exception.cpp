#include <iostream>
#include <future>
#include <mutex>
#include <string>
#include <thread>

using std::string;

void worker(std::promise<string> *p)
{
    try
    {
        throw std::runtime_error("Some Error!");
    }
    catch (...)
    {
        p->set_exception(std::current_exception());
    }
}
int main()
{
    std::promise<string> p;
    std::future<string> data = p.get_future();

    std::thread t(worker, &p);

    data.wait();

    try
    {
        data.get();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }
    t.join();
}