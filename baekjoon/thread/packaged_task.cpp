#include <future>
#include <iostream>
#include <thread>
using namespace std;

int some_task(int x) { return 10 + x; }

int main()
{
    packaged_task<int(int)> task(some_task);

    future<int> start = task.get_future();

    thread t(move(task), 5);

    cout << "Result : " << start.get() << endl;

    t.join();
}