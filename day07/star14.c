#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N_DIRS 500
#define MAX_LEN 100


void parse_lines(FILE *fp, int sizes[MAX_N_DIRS], int *n_sizes, int stack[MAX_N_DIRS], int *n_stack) {
    char line[MAX_LEN] = {0};
    char c = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (!strcmp(line, "$ cd ..\n")) {
            (*n_stack)--;
        } else if (!strncmp(line, "$ cd", strlen("$ cd"))) {
            stack[(*n_stack)++] = (*n_sizes)++;
        } else if (line[0] >= '0' && line[0] <= '9') {
            int size = 0;
            sscanf(line, "%d", &size);
            for (int i=0; i<*n_stack; i++) {
                sizes[stack[i]] += size;
            }
        }
    }
}

int find_infimum(int sizes[MAX_N_DIRS], int n_sizes, int threshold) {
    int smallest = 700000000;
    for (int i=0; i<n_sizes; i++) {
        if (sizes[i] >= threshold && sizes[i] < smallest) {
            smallest = sizes[i];
        }
    }
    return smallest;
}

int main(void) {
    FILE *fp = fopen("input.txt", "r");
    int sizes[MAX_N_DIRS] = {0};
    int n_sizes = 0;

    int stack[MAX_N_DIRS] = {0};
    int n_stack = 0;

    parse_lines(fp, sizes, &n_sizes, stack, &n_stack);
    printf("n_sizes = %d\n", n_sizes);
    printf("n_stack = %d\n", n_stack);

    int total_disk_size = 70000000;
    int size_needed_for_update = 30000000;
    int max_allowed = total_disk_size - size_needed_for_update;

    int min_to_delete = 0;
    for (int i=0; i<n_sizes; i++) {
        if (sizes[i] > min_to_delete) {
            min_to_delete = sizes[i];
        }
    }
    min_to_delete -= max_allowed;

    printf("%d\n", find_infimum(sizes, n_sizes, min_to_delete));
}