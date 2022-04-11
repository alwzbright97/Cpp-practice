#include <iostream>

using namespace std;

const int MAX = 10000;
int count[MAX] = {0};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, tmp;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        count[tmp - 1]++;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (count[i] != 0)
            for (int j = 0; j < count[i]; j++)
            {
                cout << i + 1 << '\n';
            }
    }

    return 0;
}