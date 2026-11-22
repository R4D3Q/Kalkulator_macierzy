#ifndef MATRIX_H
#define MATRIX_H

#include "common.h"

void wypisz(double M[MAX][MAX], int w, int k);
void dodaj(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);
void odejmij(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);
void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA, int kB);
int zgodne_do_sumy(int wA, int kA, int wB, int kB);
int wymiary_zgodne_MAX(int w, int k);            
int wykonaj(int op, double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC);

#endif