#include <stdio.h>

#define BOARD_SIZE     20

typedef int Bool;

Bool chess_rec_func(char (*pa)[BOARD_SIZE], int row);
Bool check(const char (*pa)[BOARD_SIZE], int row, int line);
void print_board(const char (*pa)[BOARD_SIZE]);

/**************************************************************/

int main()
{
    char chess_board[BOARD_SIZE][BOARD_SIZE] = {0};

    chess_rec_func(chess_board, 0);
    print_board(chess_board);
}

/**************************************************************/

void print_board(const char (*pa)[BOARD_SIZE])
{
    int i, k;

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("\n\t\t\t");
        for (k = 0; k < BOARD_SIZE; ++k) {
            if (!pa[i][k]) {
                printf("x ");
            }
            else {
                printf("%c ", pa[i][k]);
            }
        }
    }
    printf("\n");
}

/**************************************************************/

int chess_rec_func(char (*pa)[BOARD_SIZE], int row)
{
    int line = 0;

    if (row == BOARD_SIZE)
        return 1;
    
    while (line < BOARD_SIZE) {
        if (check(pa, row, line)) {
            pa[row][line] = 'V';
            if (chess_rec_func(pa, row + 1))
                return 1;
            pa[row][line] = 0;
        }
        line++;
    }
    return 0;
}

/**************************************************************/

int check(const char (*pa)[BOARD_SIZE], int row, int line)
{
    /*check just the left size of the board*/

    int nr = row;
    int nl = line;

    while (nr >= 0 && nl >= 0) {
        if(pa[nr][nl] == 'V')
            return 0;
        --nr, --nl;
    }

    nl = line;
    nr = row;

    while (nl < BOARD_SIZE && nr >= 0) {
        if (pa[nr][nl] == 'V')
            return 0;
        ++nl, --nr;
    }

    nl = line;
    nr = row;

    while ( nr >= 0) {
        if (pa[nr][nl] == 'V')
            return 0;
        --nr;
    }
    return -1;
}