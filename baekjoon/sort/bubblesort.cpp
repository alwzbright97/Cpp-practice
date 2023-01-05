#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;

    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << '\n';
    }

    delete[] arr;

    return 0;
}