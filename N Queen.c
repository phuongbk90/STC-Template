#include <stdio.h>

#define N 8

int A[N][N];

int dx[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[N] = {1, 2, 2, 1, -1, -2, -2, -1};

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = -1;
        }
    }
}

int is_safe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && A[x][y] == -1);
}

void solve(int x, int y, int cnt) {
    A[x][y] = cnt;

    if (cnt == N * N) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%2d  ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        A[x][y] = -1;
        return;
    }

    for (int k = 0; k < N; k++) {
        int next_x = x + dx[k];
        int next_y = y + dy[k];

        if (is_safe(next_x, next_y)) {
            solve(next_x, next_y, cnt + 1);
        }
    }
    A[x][y] = -1;
}

int main() {
    init();
    solve(0, 0, 1);
    return 0;
}
