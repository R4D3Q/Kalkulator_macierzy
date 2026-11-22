#ifndef MATRIX_IO
#define MATRIX_IO

#include "common.h"

int zapisz_macierz(const char *nazwa, double M[][MAX], int w, int k);
int wczytaj_macierz(const char *nazwa, double M[][MAX], int *w, int *k);

#endif