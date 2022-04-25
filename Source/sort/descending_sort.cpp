#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string N;
    vector<int> arr;
    cin >> N;

    for (int i = 0; i < N.length(); i++)
    {
        // cout << N[i] - 48 << ' ';
        arr.push_back(N[i] - 48);
    }
    sort(arr.begin(), arr.end());

    for (int i = N.length() - 1; i >= 0; i--)
    {
        cout << arr[i];
    }

    return 0;
}
