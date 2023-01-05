#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 8001;

int c_mean(vector<int> input)
{
    double mean;
    double sum = 0;
    int ans;
    int size = input.size();

    for (int i = 0; i < size; i++)
    {
        sum += input[i];
    }
    mean = sum / size;

    return round(mean);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, tmp, count = 0;
    vector<int> arr;
    int count_arr[MAX] = {0};
    int max, mode;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        count_arr[tmp + 4000]++;
    }

    max = *max_element(count_arr, count_arr + MAX);
    // cout << "Max : " << max << '\n';
    for (int i = 0; i < MAX; i++)
    {
        if (count_arr[i] == max)
        {
            mode = i - 4000;
            count++;
        }

        if (count > 1)
        {
            break;
        }
    }

    // Sorting
    sort(arr.begin(), arr.end());

    // cout << "Mean : " << c_mean(arr) << '\n';
    // cout << "Median : " << arr[N / 2] << '\n';
    // cout << "Mode : " << mode << '\n';
    // cout << "Range : " << arr[N - 1] - arr[0] << '\n';
    cout << "Answer : \n";
    cout << c_mean(arr) << '\n';
    cout << arr[N / 2] << '\n';
    cout << mode << '\n';
    cout << arr[N - 1] - arr[0] << '\n';

    return 0;
}
