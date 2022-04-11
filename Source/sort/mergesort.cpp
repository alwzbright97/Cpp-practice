#include <iostream>

using namespace std;

void merge(int *arr, int *sortedArr, int begin, int middle, int end)
{
    int sortedIndex = begin;
    int i = begin;
    int j = middle + 1;

    while (i <= middle && j <= end)
    {
        if (arr[i] < arr[j])
            sortedArr[sortedIndex] = arr[i++];
        else
            sortedArr[sortedIndex] = arr[j++];

        sortedIndex++;
    }
    // 왼쪽이 오른쪽보다 모두 작은 경우
    if (i > middle)
        while (j <= end)
            sortedArr[sortedIndex++] = arr[j++];
    // 오른쪽이 왼쪽보다 모두 작은 경우
    if (j > end)
        while (i <= middle)
            sortedArr[sortedIndex++] = arr[i++];

    for (int k = begin; k <= end; k++)
        arr[k] = sortedArr[k];
}
void mergeSort(int *arr, int *sortedArr, int begin, int end)
{
    int middle;
    if (begin < end)
    {
        middle = (begin + end) / 2;
        cout << begin << middle << end << '\n';
        mergeSort(arr, sortedArr, begin, middle);
        mergeSort(arr, sortedArr, middle + 1, end);
        merge(arr, sortedArr, begin, middle, end);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int *sortedArr = new int[N];
    mergeSort(arr, sortedArr, 0, N - 1);

    for (int i = 0; i < N; i++)
        cout << arr[i] << '\n';

    return 0;
}