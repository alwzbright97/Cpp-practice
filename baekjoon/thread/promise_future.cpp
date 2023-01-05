#include <future>
#include <iostream>
#include <string>
#include <thread>

using std::string;

void worker(std::promise<string> *p)
{
    p->set_value("some_data");
}
int main()
{
    std::promise<string> p;

    std::future<string> data = p.get_future();

    std::thread t(worker, &p);

    data.wait();

    std::cout << "Data Received : " << data.get() << std::endl;

    t.join();
}