#include <stdio.h>
#include "matrix.h"

//definicja funkcji wypisz
void wypisz(double M[MAX][MAX], int w, int k) {
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            printf("%8.2f", M[i][j]);
        }
        printf("\n");
    }
}

//definicja dodaj
void dodaj(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k) {
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

//definicja odejmij
void odejmij(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k) {
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

//definicja pomnoz
void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA, int kB) {
    int i, j, n;
    double suma;
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kB; j++) {
            suma = 0.0;
            for (n = 0; n < kA; n++) {
                suma = suma + A[i][n] * B[n][j];
            }
            C[i][j] = suma;
        }
    }
}


//definicja wymiary zgodne do sumowania
int zgodne_do_sumy(int wA, int kA, int wB, int kB) {
    if (wA == wB && kA == kB) {
        return 1; //wymiary są poprawne
    }
    return 0;     //wymiary są niepoprawne
}

//definicja wymiary zgodne z MAX
int wymiary_zgodne_MAX(int w, int k) {
    if (w >= 1 && w <= MAX && k >= 1 && k <= MAX) {
        return 1; //wymiary są poprawne
    }
    return 0;     //wymiary są niepoprawne
}

//wykonanie wybranej operacji
int wykonaj(int op, double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC) {
    if (op == 1) {
        if (!zgodne_do_sumy(wA, kA, wB, kB)) return BLAD_WYMIARY;
        *wC = wA;
        *kC = kA;
        dodaj(A, B, C, wA, kA);
        return OK;
    } 
    else if (op == 2) {
        if (!zgodne_do_sumy(wA, kA, wB, kB)) return BLAD_WYMIARY;
        *wC = wA;
        *kC = kA;
        odejmij(A, B, C, wA, kA);
        return OK;
    } 
    else if (op == 3) {
        if (kA != wB) return BLAD_WYMIARY;
        *wC = wA;
        *kC = kB;
        pomnoz(A, B, C, wA, kA, kB);
        return OK;
    }
    
    return BLAD_OPERACJA;
}