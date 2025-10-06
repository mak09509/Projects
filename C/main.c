#include <stdio.h>
#include <stdlib.h>
#define N 100000000

int main(void) {

    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < N; i++) {
        if (rand()%2) {
            int a, b, c;
            a = 1;
            b = rand() % 100;
            c = rand() % 100;
            fprintf(fp, "%d %d %d\n", a, b, c);
        }
        else {
            int a, b;
            a = 0;
            b = rand() % 100;
            fprintf(fp, "%d %d\n", a, b);
        }
    }

    fprintf(fp, "3");
    fclose(fp);
    printf("Print file sucessfully!\n");
    return 0;
}
