#include <iostream>

int main() {
    int N;

    std::cin >> N;
    int* rank = new int[N];
    int* height = new int[N];
    int* weight = new int[N];

    for(int i = 0; i < N; i++) {
        rank[i] = 1;
        std::cin >> weight[i] >> height[i];
    }

    for (int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if (height[i] > height[j] && weight[i] > weight[j]) rank[j] += 1;
            
            if (height[i] < height[j] && weight[i] < weight[j]) rank[i] += 1;
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << rank[i] << ' ';
    }

    delete[] rank, height, weight;

    return 0;
}