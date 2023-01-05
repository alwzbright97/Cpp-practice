#include <iostream>

using namespace std;

int main()
{
    int N, count = 0;

    cin >> N;

    for (int i = 666;; i++)
    {

        if (to_string(i).find("666") != string::npos)
            count++;

        if (count == N)
        {
            cout << i;
            break;
        }
    }
    return 0;
}