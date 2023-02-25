#include <stdio.h>
#include <string.h>

#define MAX_STRLEN 10000
#define SEQ_LEN 4

int check(char line[], int left, int seq_len) {
    int letters[26] = {0};
    char c = 0;
    for (int i=0; i<seq_len; i++) {
        c = line[left + i];
        if (letters[c - 'a']++) {
            return 0;
        }
    }
    return 1;
}

int find_sequence(char line[], int seq_len) {
    int left = 0;
    while (!check(line, left, seq_len)) {
        left++;
    }
    return left + seq_len;
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    char line[MAX_STRLEN] = {0};
    
    fscanf(fp, "%s", line);

    printf("%d", find_sequence(line, SEQ_LEN));

}