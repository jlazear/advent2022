#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYS 10000

int read_input(char *fname, int data[][2]) {
    FILE *fp = fopen(fname, "r");
    int n = 0;

    char opp = 0;
    char yours = 0;

    while (fscanf(fp, "%c %c\n", &opp, &yours) == 2) {
        if (opp == 'A') data[n][0] = 0;
        else if (opp == 'B') data[n][0] = 1;
        else if (opp == 'C') data[n][0] = 2;

        if (yours == 'X') data[n][1] = 0;
        else if (yours == 'Y') data[n][1] = 1;
        else if (yours == 'Z') data[n][1] = 2;

        n++;
    }
    return n;
}

int game_score(int opp, int yours) {
    int scores[3][3] = {{3, 6, 0},
                        {0, 3, 6},
                        {6, 0, 3}};
    return scores[opp][yours];
}

int your_score(int yours) {
    int scores[3] = {1, 2, 3};
    return scores[yours];
}

int main(void) {
    int data[MAX_PLAYS][2] = {0};
    int n_plays = 0;

    n_plays = read_input("input.txt", data);

    printf("n_plays = %d\n", n_plays);

    int total = 0;
    for (int i=0; i<n_plays; i++) {
        total += game_score(data[i][0], data[i][1]) + your_score(data[i][1]);
    }
    printf("total = %d\n", total);
}