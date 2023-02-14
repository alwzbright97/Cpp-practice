#include <iostream>
#include <algorithm>
#include <vector>

constexpr int MAX = 500000;
int arr[MAX];

int N, M;
int key;

int lower_bound()
{
    int low = 0, high = N;
    while (low < high)
    {
        int mid = (low + high) / 2;
        
        if (arr[mid] >= key)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int upper_bound()
{
    int low = 0, high = N;
    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > key)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
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
    std::vector<int> v;
    for (int i = 0; i < M; i++)
    {
        std::cin >> key;
        v.push_back(key);
    }

    // for (int i = 0; i < N; i++)
    // {
    //     std::cout << arr[i] << " ";
    // }
    // std::cout << "\n";

    for (int i = 0; i < M; i++)
    {
        key = v[i];
        std::cout << upper_bound() - lower_bound() << '\n';
                //   << "\treturn: " << upper_bound() - lower_bound() << '\n'
                //   << "key: " << key << '\n'
                //   << "lower_bound: " << lower_bound() << '\n'
                //   << "upper_bound: " << upper_bound() << '\n';
    }
    
    

    return 0;    
}