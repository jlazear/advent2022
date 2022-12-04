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

int find_badge(char lines[3][MAX_LEN], int len_lines[3]) {
    char s1[NUM_CHARS] = {0};
    char s2[NUM_CHARS] = {0};
    char s3[NUM_CHARS] = {0};
    int s = 0;
    for (int i=0; i<len_lines[0]; i++) {
        s = score(lines[0][i]) - 1;
        s1[s]++;
    }
    for (int i=0; i<len_lines[1]; i++) {
        s = score(lines[1][i]) - 1;
        s2[s]++;
    }
    for (int i=0; i<len_lines[2]; i++) {
        s = score(lines[2][i]) - 1;
        s3[s]++;
    }

    for (int i=0; i<NUM_CHARS; i++) {
        if (s1[i] && s2[i] && s3[i]) {
            return i + 1;
        }
    }
    return -1;
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    char lines[3][MAX_LEN] = {0};
    int len_lines[3] = {0};
    int total = 0;
    int to_add = 0;

    while (fscanf(fp, "%s\n%s\n%s\n", lines[0], lines[1], lines[2]) == 3) {
        for (int i=0; i<3; i++) {
            len_lines[i] = strlen(lines[i]);
        }

        total += find_badge(lines, len_lines);
    }

    printf("total = %d\n", total);
}