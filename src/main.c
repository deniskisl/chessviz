#include <stdio.h>
#include "board_print_plain.h"
#include "board.h"

char desk[8][8] = {"RHBQKBHR",
                   "PPPPPPPP",
                   "        ",
                   "        ",
                   "        ",
                   "        ",
                   "pppppppp",
                   "rhbqkbhr"};

int main()
{
    showdesk();
    for (;;) {
        printf("Введите действие белых: ");
        start(1);
        move();
        showdesk();
        printf("Введите действие чёрных: ");
        start(2);
        move();
        showdesk();
    }
    return 0;
}