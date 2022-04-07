#include <iostream>

using namespace std;

void quickSort(int *data, int start, int end)
{
    if (start >= end)
        return;
    int pivot = start;
    int i = start + 1;
    int j = end;
    int temp;
    while (i <= j)
    {
        while (data[i] <= data[pivot])
            i++;
        while (data[j] >= data[pivot] && j > start)
            j--;

        if (i > j)
        {
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }
        else
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        quickSort(data, start, j - 1);
        quickSort(data, j + 1, end);
    }
}

int main()
{
    int N;
    cin >> N;

    int *arr = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';

    return 0;
}