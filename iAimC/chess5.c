#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 15  // 棋盘大小

// 棋盘状态
typedef enum {
    EMPTY, BLACK, WHITE
} State;

// 棋盘数据结构
typedef struct {
    State board[BOARD_SIZE][BOARD_SIZE];  // 棋盘数组
    int last_move_row;  // 最后一步的行坐标
    int last_move_col;  // 最后一步的列坐标
    State next_player;  // 下一个玩家
} Board;

// 初始化棋盘
void init_board(Board *board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board->board[row][col] = EMPTY;
        }
    }
    board->last_move_row = -1;
    board->last_move_col = -1;
    board->next_player = BLACK;
}

// 在棋盘上打印出当前状态
void print_board(Board *board) {
    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%c ", col + 'a');
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%2d ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board->board[row][col]) {
                case EMPTY:
                    printf(". ");
                    break;
                case BLACK:
                    printf("X ");
                    break;
                case WHITE:
                    printf("O ");
                    break;
            }
        }
        printf("\n");
    }
}

// 判断某一方是否胜利
bool is_win(Board *board, State player) {
    // 检查水平方向
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col <= BOARD_SIZE - 5; col++) {
            bool win = true;
            for (int i = 0; i < 5; i++) {
                if (board->board[row][col + i] != player) {
                    win = false;
                    break;
                }
            }
            if (win) {
                return true;
            }
        }
    }

    // 检查垂直方向
    for (int row = 0; row <= BOARD_SIZE - 5; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            bool win = true;
            for (int i = 0; i < 5; i++) {
                if (board->board[row + i][col] != player) {
                    win = false;
                    break;
                }
            }
            if (win) {
                return true;
            }
        }
    }

    // 检查正斜方向
    for (int row = 0; row <= BOARD_SIZE - 5; row++) {
        for (int col = 0; col <= BOARD_SIZE - 5; col++) {
            bool win = true;
            for (int i = 0; i < 5; i++) {
                if (board->board[row + i][col + i] != player)
                    {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }
}

// 检查反斜方向
for (int row = 0; row <= BOARD_SIZE - 5; row++) {
    for (int col = 4; col < BOARD_SIZE; col++) {
        bool win = true;
        for (int i = 0; i < 5; i++) {
            if (board->board[row + i][col - i] != player) {
                win = false;
                break;
            }
        }
        if (win) {
            return true;
        }
    }
}

return false;
}
// 检查是否可以在指定的位置落子
bool is_valid_move(Board *board, int row, int col) {
if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
return false;
}
if (board->board[row][col] != EMPTY) {
return false;
}
return true;
}

// 在指定位置落子
void make_move(Board *board, int row, int col) {
board->board[row][col] = board->next_player;
board->last_move_row = row;
board->last_move_col = col;
if (board->next_player == BLACK) {
board->next_player = WHITE;
} else {
board->next_player = BLACK;
}
}

// 撤销上一步落子
void undo_move(Board *board) {
board->board[board->last_move_row][board->last_move_col] = EMPTY;
if (board->next_player == BLACK) {
board->next_player = WHITE;
} else {
board->next_player = BLACK;
}
}

int main() {
Board board;
init_board(&board);while (true) {
    // 打印棋盘
    print_board(&board);

    // 提示下一个玩家落子
    if (board.next_player == BLACK) {
        printf("黑方落子（行列坐标，例如 3d）：");
    } else {
        printf("白方落子（行列坐标，例如 3d）：");
    }

    // 读取输入
    char input[256];
    if (fgets(input, 256, stdin) == NULL) {
        break;
    }
    if (input[0] == 'q') {
        break;
    }
    int row = input[0] - '1';
    int col = input[1] - 'a';
    if (!is_valid_move(&board, row, col)) {
        printf("无效的落子位置\n");
        continue;
    }

    // 落子并判断游戏结束状态
    make_move(&board, row, col);
    if (is_win(&board, BLACK)) {
        printf("黑方胜利！\n");
        break;
    }
    if (is_win(&board, WHITE)) {
        printf("白方胜利！\n");
        break;
}
}  
system("pause");
return 0;
}