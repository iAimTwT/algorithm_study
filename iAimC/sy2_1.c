#include <stdio.h>
#include <stdlib.h>

int tile = 1;

void chessboard(int tr, int tc, int dr, int dc, int size, int** board) {
    if (size == 1) return;
    int t = tile++, s = size / 2;

    if (dr < tr + s && dc < tc + s) 
        chessboard(tr, tc, dr, dc, s, board);
    else {
        board[tr + s - 1][tc + s - 1] = t;
        chessboard(tr, tc, tr + s - 1, tc + s - 1, s, board);
    }

    if (dr < tr + s && dc >= tc + s) 
        chessboard(tr, tc + s, dr, dc, s, board);
    else {
        board[tr + s - 1][tc + s] = t;
        chessboard(tr, tc + s, tr + s - 1, tc + s, s, board);
    }

    if (dr >= tr + s && dc < tc + s) 
        chessboard(tr + s, tc, dr, dc, s, board);
    else {
        board[tr + s][tc + s - 1] = t;
        chessboard(tr + s, tc, tr + s, tc + s - 1, s, board);
    }

    if (dr >= tr + s && dc >= tc + s) 
        chessboard(tr + s, tc + s, dr, dc, s, board);
    else {
        board[tr + s][tc + s] = t;
        chessboard(tr + s, tc + s, tr + s, tc + s, s, board);
    }
}

int main() {
    int n, dr, dc;

    printf("请输入棋盘的大小(2^n*2^n): ");
    scanf("%d", &n);
    printf("请输入特殊格子的行号和列号(小于 %d): ", (1 << n));
    scanf("%d %d", &dr, &dc);

    if (dr < 0 || dr >= (1 << n) || dc < 0 || dc >= (1 << n)) {
        printf("行号或列号超出范围！\n");
        return 1;
    }

    int size = 1 << n;
    int** board = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        board[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }

    chessboard(0, 0, dr, dc, size, board);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) { 
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);

    system("pause");
    return 0;
}
