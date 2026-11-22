#include <stdio.h>
#include "common.h"
#include "matrix.h"
#include "matrix_io.h"

int main(void) {
    
    int wA, kA, wB, kB, wC, kC;
    double A[MAX][MAX];
    double B[MAX][MAX];
    double C[MAX][MAX];
    int op, kod;
//A.txt
    kod = wczytaj_macierz("A.txt", A, &wA, &kA);
    if (kod != OK) {
        fprintf(stderr, "Blad (A.txt): %s\n", opis_bledu(kod));
        return 1;
    }
//B.txt
    kod = wczytaj_macierz("B.txt", B, &wB, &kB);
    if (kod != OK) {
        fprintf(stderr, "Blad (B.txt): %s\n", opis_bledu(kod));
        return 1;
    }

    //wybor operacji
    printf("Operacja: 1 - dodaj, 2 - odejmij, 3 - pomnoz\n");
    if (scanf("%d", &op) != 1) {
        op = 0;
    }

    //wykonanie wybranej operacji
    kod = wykonaj(op, A, wA, kA, B, wB, kB, C, &wC, &kC);
    if (kod != OK) {
        fprintf(stderr, "Blad: %s\n", opis_bledu(kod));
        return 1;
    }

    //zapis wyniku do pliku
    kod = zapisz_macierz("wynik.txt", C, wC, kC);
    if (kod != OK) {
        fprintf(stderr, "Blad: %s\n", opis_bledu(kod));
        return 1;
    }
    printf("\nWynik operacji:\n");
    wypisz(C, wC, kC);
    printf("\nWynik zapisany do pliku wynik.txt\n");
    return 0;
}

    