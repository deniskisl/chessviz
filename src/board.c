#include "board.h"
#include <stdio.h>
#include <string.h>

extern char desk[8][8];
int i1, c1, i2, c2;

void start(int flag)
{
    char input[7] = "NULL";
    for (;;) {
        fgets(input, 7, stdin);
        c1 = (int)input[0] - 'A';
        i1 = (int)input[1] - '1';
        c2 = (int)input[3] - 'A';
        i2 = (int)input[4] - '1';
        if (flag == 1) {
            if (white() == 1) {
                break;
            } else {
                printf("Невозможный ход. Введите ещё раз: ");
            }
        }
        if (flag == 2) {
            if (black() == 1) {
                break;
            } else {
                printf("Невозможный ход. Введите ещё раз: ");
            }
        }
    }
}
int white()
{
    switch (desk[i1][c1]) {
    case 'P':
        if ((desk[i2][c2] == ' ') && (i1 == 1) && (c2 == c1) && ((i2 - i1) > 0)
            && ((i2 - i1) <= 2)) {
            return 1;
        }
        if ((desk[i2][c2] == ' ') && ((i2 - i1) > 0) && ((i2 - i1) <= 1)) {
            return 1;
        }
        if ((desk[i2][c2] > 'a') && (desk[i2][c2] < 's')) {
            return 1;
        }
    }
    return 0;
}

int black()
{
    switch (desk[i1][c1]) {
    case 'p':
        if ((desk[i2][c2] == ' ') && (i1 == 6) && (c2 == c1) && ((i1 - i2) > 0)
            && ((i1 - i2) <= 2)) {
            return 1;
        }
        if ((desk[i2][c2] == ' ') && ((i1 - i2) > 0) && ((i1 - i2) <= 1)) {
            return 1;
        }
        if ((desk[i2][c2] > 'A') && (desk[i2][c2] < 'S')) {
            return 1;
        }
    }
    return 0;
}

void move()
{
    desk[i2][c2] = desk[i1][c1];
    desk[i1][c1] = ' ';
}
