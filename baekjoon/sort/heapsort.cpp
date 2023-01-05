#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1000000;
int n, heap[MAX];

void swap(int a, int b)
{
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
    return;
}
void max_heap(int cur, int size)
{
    while (cur < size)
    {
        int left = cur * 2 + 1;
        int right = cur * 2 + 2;
        if (left < size || right < size)
        {
            int tmp = cur;
            if (left < size)
            {
                if (heap[left] > heap[tmp])
                    tmp = left;
            }
            if (right < size)
            {
                if (heap[right] > heap[tmp])
                    tmp = right;
            }
            if (tmp == cur)
                break;
            swap(cur, tmp);
            cur = tmp;
        }
        else
            break;
    }
    return;
}
void heapify()
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        max_heap(i, n);
    }
    return;
}
int main()
{
    memset(heap, 0, sizeof(heap));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &heap[i]);
    }
    heapify();
    for (int i = n - 1; i > 0; i--)
    {
        swap(0, i);
        max_heap(0, i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", heap[i]);
    }
    return 0;
}