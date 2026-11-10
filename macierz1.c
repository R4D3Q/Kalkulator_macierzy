#define MAX 20
#include <stdio.h>

//prototypy funkcji
void wypisz(double M[MAX][MAX], int w, int k);                                                   //wypisz
void dodaj(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);                     //dodaj
void odejmij(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);                   //odejmij
void pomnoz(double A[MAX][MAX], double B[MAX][MAX], double C[MAX][MAX], int wA, int kA, int kB); //mnozenie A i B
int zgodne_do_sumy(int wA, int kA, int wB, int kB);    //zgodne do sumy
int wymiary_zgodne(int w, int k);                      //zgodne z MAX

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

//definicja dodaj
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
int wymiary_zgodne(int w, int k) {
    if (w >= 1 && w <= MAX && k >= 1 && k <= MAX) {
        return 1; //wymiary są poprawne
    }
    return 0;     //wymiary są niepoprawne
}


int main(void) {
    int wA = 2, kA = 2, wB = 2, kB = 2;
    double A[MAX][MAX] = {{1.0, 2.0}, {3.0, 4.0}};
    double B[MAX][MAX] = {{5.0, 6.0}, {7.0, 8.0}};
    double C[MAX][MAX];
    int wP = 2, kP = 3, wQ = 3, kQ = 2;
    double P[MAX][MAX] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    double Q[MAX][MAX] = {{7.0, 8.0},{9.0, 10.0},{11.0, 12.0}};
    double R[MAX][MAX];

// sprawdzanie poprawności wymiarów
if (!zgodne_do_sumy(wA, kA, wB, kB)) {
    printf("Wymiary niezgodne");
    return 1;
}

// sprawdzanie zakresu [1, MAX]
    if (!wymiary_zgodne(wA, kA) || !wymiary_zgodne(wB, kB)) {
        printf("Wymiary inne niż MAX");
        return 1;
    }

//suma - funkcja dodaj
printf("Suma A + B:\n");
dodaj(A, B, C, wA, kA);
wypisz(C, wA, kA);
printf("\n");

//roznica - funkcja odejmij
printf("Roznica A i B:\n");
odejmij(A, B, C, wA, kA);
wypisz(C, wA, kA);
printf("\n");

//iloczyn - funkcja pomnoz
if (kA == wB) {
    printf("Iloczyn A * B:\n");
    pomnoz(A, B, C, wA, kA, kB);
    wypisz(C, wA, kB);
    printf("\n");
}
else {
    printf("Wymiary do mnozenia A*B sa niepoprawne!\n");
}

//iloczyn P*Q
if (kP == wQ) {
    printf("Iloczyn P * Q:\n");
    pomnoz(P, Q, R, wP, kP, kQ);
    wypisz(R, wP, kQ);
    printf("\n");
}
else {
    printf("Wymiary do mnozenia P*Q sa niepoprawne!\n");
}

//iloczyn Q*P
if (kQ == wP) {
    printf("Iloczyn Q * P:\n");
    pomnoz(Q, P, R, wQ, kQ, kP);
    wypisz(R, wQ, kP);
    printf("\n");
}
else {
    printf("Wymiary do mnozenia Q*P sa niepoprawne!\n");
}

return 0;
}