#include <stdio.h>
#include <stdlib.h>

int check_line(int x1, int x2, int y1, int y2) {
    return (x1 <= y1 && y2 <= x2) || (y1 <= x1 && x2 <= y2);
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    int x1, x2, y1, y2;
    int n = 0;

    while (fscanf(fp, "%d-%d,%d-%d\n", &x1, &x2, &y1, &y2) == 4) {
        if (check_line(x1, x2, y1, y2)) n++;
    }

    printf("n = %d\n", n);
}