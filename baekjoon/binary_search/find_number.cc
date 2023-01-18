#include <iostream>
#include <algorithm>
constexpr int MAX = 100000;
int arr[MAX];

int N, M;
int input;

int binary_search(int n)
{
    int begin = 0;
    int end = N - 1;

    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        
        if (arr[mid] == n)
        {
            return 1;
        }
        
        if (arr[mid] > n)
        {
            end = mid - 1;
        }
        else 
        {
            begin = mid + 1;
        }
    }
    return 0;

}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + N);

    std::cin >> M;

    for (int i = 0; i < M; i++)
    {
        std::cin >> input;
        std::cout << binary_search(input) << "\n";
    }
    
    
}