#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = a;
}

int main()
{
    int arr[2] = {0, 1};
    swap(arr[0], arr[1]);

    cout << arr[0] << ' ' << arr[1];

    return 0;
}