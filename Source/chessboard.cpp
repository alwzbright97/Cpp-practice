#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    int min = 64;
    int diff, black_diff, white_diff;
    char white[8][8], black[8][8];

    // white
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 1) {
                white[i][j] = 'B';
                black[i][j] = 'W';
            }
            else {
                white[i][j] = 'W';
                black[i][j] = 'B';
            }
        }
    }

    char** board = new char*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new char[M];
        for (int j = 0; j < M; j++) {
            std::cin >> board[i][j];
        }
    }

    for (int n = 0; n < N - 7; n++) {
        for (int m = 0; m < M - 7; m++) {
            black_diff = 0;
            white_diff = 0;
            for(int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (white[i][j] != board[n + i][m + j]) white_diff++;
                    if (black[i][j] != board[n + i][m + j]) black_diff++;
                }
            }
            if (white_diff > black_diff) diff = black_diff;
            else diff = white_diff;

            if (min > diff) min = diff;
        }
    }
    std::cout << min;
}