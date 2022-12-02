#include <stdio.h>
#include <stdlib.h>

#define MAX_ELVES 1000

int read_input(char *fname, int *data) {
    FILE *fp = fopen(fname, "r");
    char line[40] = {0};
    int n = 0;
    int calories = 0;
    int d = 0;

    if (!fp) {
        printf("Failed to open file %s!", fname);
        exit(-1);
    }

    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '\n' || line[0] == '\r') {
            n++;
            data[n++] = calories;
            calories = 0;
        } 
        else {
            sscanf(line, "%d", &d);
            calories += d;
        }
    }
    if (calories) {
        data[n++] = calories;
    }
    return n;
}

int cmpfunc(const void *a, const void* b) {
    int aa = *((int*)a);
    int bb = *((int*)b);

    if (aa == bb) {
        return 0;
    } else {
        return (aa > bb) ? 1 : -1;
    }
}

int main(void) {
    int elves[MAX_ELVES] = {0};
    int n_elves = 0;
    int sum = 0;

    n_elves = read_input("input.txt", elves);
    qsort(elves, n_elves, sizeof(int), cmpfunc);
    for (int i=0; i<3; i++) {
        sum += elves[n_elves-1-i];
    }
    printf("%d\n", sum);
}
