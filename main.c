#include <stdio.h>

#include "common.h"
#include "matrix.h"
#include "matrix_io.h"

int main(int argc, char *argv[]) {
    int op = 0;
    const char *plikA;
    const char *plikB;
    const char *plikWynik;

//aregumenty wiersza polecen
    if (argc == 5) {
        if(argv[1][1] == '\0') {
            op = argv[1][0] - '0';
        }
        if (op < 1 || op > 3) {
            fprintf(stderr, "Blad; %s\n", opis_bledu(BLAD_OPERACJA));
            return 1;
        }
        plikA = argv[2];
        plikB = argv[3];
        plikWynik = argv[4];
    }
//bez arg bierzemy ustalone A, B i wynik txt
    else if (argc == 1) {
        plikA = "A.txt";
        plikB = "B.txt";
        plikWynik = "wynik.txt";

        printf("Operacja: 1 - dodaj, 2 - odejmij, 3 - pomnoz\n");
        if (scanf("%d", &op) != 1 || op < 1 || op > 3) {
            fprintf(stderr, "Blad: %s\n", opis_bledu(BLAD_OPERACJA));
            return 1;
        }
    }

    else {
        fprintf(stderr, "============================================");
        fprintf(stderr, "\nPodano nieprawidlowe argumenty, wpisz poprawne argumenty lub uruchom program bez argumentow.\n");
        fprintf(stderr, "\nWpisz: %s <numer operacji 1-3> <plikA> <plikB> <plikWynik>\n", argv[0]);
        fprintf(stderr, "\nOperacje: 1 - dodaj, 2 - odejmij, 3 - pomnoz\n");
        fprintf(stderr, "============================================\n");
        return 1;
    }
    
    int wA, kA, wB, kB, wC, kC;
    double A[MAX][MAX];
    double B[MAX][MAX];
    double C[MAX][MAX];
    int kod;

//A.txt
    kod = wczytaj_macierz(plikA, A, &wA, &kA);
    if (kod != OK) {
        fprintf(stderr, "Blad (%s): %s\n", plikA, opis_bledu(kod));
        return 1;
    }
//B.txt
    kod = wczytaj_macierz(plikB, B, &wB, &kB);
    if (kod != OK) {
        fprintf(stderr, "Blad (%s): %s\n", plikB, opis_bledu(kod));
        return 1;
    }

    //wykonanie wybranej operacji
    kod = wykonaj(op, A, wA, kA, B, wB, kB, C, &wC, &kC);
    if (kod != OK) {
        fprintf(stderr, "Blad: %s\n", opis_bledu(kod));
        return 1;
    }

    //zapis wyniku do pliku
    kod = zapisz_macierz(plikWynik, C, wC, kC);
    if (kod != OK) {
        fprintf(stderr, "Blad (%s): %s\n", plikWynik, opis_bledu(kod));
        return 1;
    }
    printf("\nWynik operacji:\n");
    wypisz(C, wC, kC);
    printf("\nWynik zapisany do pliku %s\n", plikWynik);
    return 0;
}