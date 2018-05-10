#include "myBigChars.h"

#include <stdio.h>
int main() {
    int big[] = {0xFFC3C3FF, 0x0E3160C0};
    /*int test[2], i, j;
    for (i = 0; i < 8; ++i)
        for (j = 0; j < 8; ++j)
            bc_setbigcharpos(test, i, j, (big[(i >> 2) & 1] >> ((i & 3) * 8 + j)) & 1);*/
    mt_clrscr();
    bc_box(5, 1, 10, 10);
    bc_printbigchar(big, 6, 2, RED, BLUE);
    printf("\n");
    mt_gotoXY(0,0);
    getchar();
    mt_reset();
    return 0;
}
