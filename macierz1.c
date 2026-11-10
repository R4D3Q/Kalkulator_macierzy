#define MAX 20
#include <stdio.h>

int main(void) {
    int i, j;
    int wA = 2, kA = 2, wB = 2, kB = 2;
    double A[MAX][MAX] = {{1.0, 2.0}, {3.0, 4.0}};
    double B[MAX][MAX] = {{5.0, 6.0}, {7.0, 8.0}};
    double C[MAX][MAX];

    if(wA != wB || kA != kB) {
        printf("Błąd wymiarów");
        return 1;
    }

//dodawanie
printf("Suma A + B:\n");
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kA; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%8.2f", C[i][j]);
        }
        printf("\n");
    }
printf("\n");

//roznica
printf("Roznica A - B:\n");
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kA; j++) {
            C[i][j] = A[i][j] - B[i][j];
            printf("%8.2f", C[i][j]);
        }
        printf("\n");
    }

printf("Roznica B - A:\n");
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kA; j++) {
            C[i][j] = B[i][j] - A[i][j];
            printf("%8.2f", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}