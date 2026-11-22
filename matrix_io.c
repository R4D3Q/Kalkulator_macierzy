#include <stdio.h>
#include "matrix_io.h"
#include "matrix.h"


int wczytaj_macierz(const char *nazwa, double M[][MAX], int *w, int *k) {
    FILE *plik = fopen(nazwa, "r");
    if (plik == NULL) {
        return BLAD_OTWARCIA;
//wczytanie i sprawdzenie wymiarow
    }
    int wymiary = fscanf(plik, "%d %d", w, k);
    if (wymiary == EOF) {
        fclose(plik);
        return BLAD_ZA_MALO;
    }
    if (wymiary !=2) {
        fclose(plik);
        return BLAD_ELEMENT;
    }
     //sprawdzanie wymiarow
    if (!wymiary_zgodne_MAX(*w, *k)) {
        fclose(plik);
        return BLAD_ZAKRES;
    }
//wczytanie i sprawdzenie elementow
    for (int i = 0; i < *w; i++) {
        for (int j = 0; j < *k; j++) {
            int elementy = fscanf(plik, "%lf", &M[i][j]);
            if (elementy == EOF) {
             fclose(plik);
                return BLAD_ZA_MALO;
            }
            if (elementy !=1) {
                fclose(plik);
                return BLAD_ELEMENT;
            }
        }
    }
    fclose(plik);
    return OK;
}

int zapisz_macierz(const char *nazwa, double M[][MAX], int w, int k) {
    FILE *plik = fopen(nazwa, "w");
    if (plik == NULL) {
        return BLAD_ZAPISU;
    }

    fprintf(plik, "%d %d\n", w, k);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            fprintf(plik, "%.2f", M[i][j]);
            if (j < k - 1) fprintf(plik, " ");
        }
        fprintf(plik, "\n");
    }

    fclose(plik);
    return OK;
}