#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 52
#define MAX_LEN 100

int score(char c) {
    if ('a' <= c && c <= 'z') {
        return 1 + (c - 'a');
    } else if ('A' <= c && c <= 'Z') {
        return 27 + (c - 'A');
    } else {
        return -1;
    }
}

int find_error(char line[MAX_LEN], int len_line) {
    char s1[NUM_CHARS] = {0};
    char s2[NUM_CHARS] = {0};
    int s = 0;
    for (int i=0; i<len_line/2; i++) {
        s = score(line[i]) - 1;
        s1[s]++;
    }
    for (int i=len_line/2; i<len_line; i++) {
        s = score(line[i]) - 1;
        s2[s]++;
    }

    for (int i=0; i<NUM_CHARS; i++) {
        if (s1[i] && s2[i]) {
            return i + 1;
        }
    }
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    char line[MAX_LEN] = {0};
    int total = 0;

    while (fscanf(fp, "%s\n", line) == 1) {
        total += find_error(line, strlen(line));
    }

    printf("total = %d\n", total);
}