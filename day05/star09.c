#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 100
#define MAX_LEN 100
#define N_STACKS 9
#define MAX_COMMANDS 1000

void read_stacks(FILE *fp, char stacks[N_STACKS][MAX_HEIGHT], int len_stacks[N_STACKS]) {
    char line[MAX_LEN] = {0};
    char c;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strlen(line) < 3) break;
        for (int i=0; i<N_STACKS; i++) {
            if ((c=line[1 + 4*i]) != ' ') {
                stacks[i][len_stacks[i]++] = c;
            }
        }
    }
}

int read_commands(FILE *fp, int commands[MAX_COMMANDS][3]) {
    char line[MAX_LEN] = {0};
    int n_commands = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "move %d from %d to %d\n", &commands[n_commands][0],
                                                &commands[n_commands][1],
                                                &commands[n_commands][2]);
        n_commands++;
    }
    return n_commands;
}

void string_reverse(char s[MAX_LEN]) {
    char s2[MAX_LEN] = {0};
    int s_len = strlen(s);
    memcpy(s2, s, sizeof(char) * MAX_LEN);

    for (int i=0; i<s_len; i++) {
        s[i] = s2[s_len - i - 1];
    }
}

void print_stacks(char stacks[N_STACKS][MAX_HEIGHT], int len_stacks[N_STACKS]) {
    for (int i=0; i<N_STACKS; i++) {
        printf("%d (%d) - ", i+1, len_stacks[i]);
        for (int j=0; j<len_stacks[i]; j++) {
            printf("%c", stacks[i][j]);
        }
        printf("\n");
    }
}

void print_stack(char stacks[N_STACKS][MAX_HEIGHT], int len_stacks[N_STACKS], int i) {
    printf("%d (%d) - ", i+1, len_stacks[i]);
    for (int j=0; j<len_stacks[i]; j++) {
        printf("%c", stacks[i][j]);
    }
    printf("\n");
}

void execute_command(char stacks[N_STACKS][MAX_HEIGHT], int len_stacks[N_STACKS], int cmd[3]) {
    int n = cmd[0];
    int source = cmd[1] - 1;
    int dest = cmd[2] - 1;
    int len_source = 0;
    int len_dest = 0;

    for (int i=0; i<n; i++) {
        len_source = len_stacks[source];
        len_dest = len_stacks[dest];

        stacks[dest][len_dest] = stacks[source][len_source-1];
        
        len_stacks[source]--;
        len_stacks[dest]++;
    }
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    char stacks[N_STACKS][MAX_HEIGHT] = {0};
    int len_stacks[N_STACKS] = {0};
    int commands[MAX_COMMANDS][3] = {0};
    int n_commands = 0;

    read_stacks(fp, stacks, len_stacks);
    n_commands = read_commands(fp, commands);
    for (int i=0; i<N_STACKS; i++) {
        string_reverse(stacks[i]);
    }

    for (int i=0; i<n_commands; i++) {
        execute_command(stacks, len_stacks, commands[i]);
    }

    for (int i=0; i<N_STACKS; i++) {
        printf("%c", stacks[i][len_stacks[i]-1]);
    }
    printf("\n");
}