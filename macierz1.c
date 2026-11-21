#define MAX 20
#include <stdio.h>

//BLEDY
enum {
    OK = 0,
    BLAD_OTWARCIA, //blad otwarcia pliku z macierzą
    BLAD_ZAPISU, //blad zapisu wyniku do pliku
    BLAD_ZAKRES, //blad rozmiar macierzy poza MAX
    BLAD_WYMIARY, //wymiary niezgodne do sumy/mnozenia
    BLAD_OPERACJA, //wybrano nieprawidłowy numer operacji
    BLAD_ELEMENT, //nieprawidłowy element w macierzy
    BLAD_ZA_MALO, //brakujące elementy macierzy
};

const char* opis_bledu(int kod) {
    switch (kod) {
        case BLAD_OTWARCIA: return "Nie mozna otworzyc pliku z macierza.";
        case BLAD_ZAKRES: return "Rozmiar macierzy poza MAX.";
        case BLAD_ZA_MALO: return "Brakujace elementy macierzy.";
        case BLAD_ELEMENT: return "Nieprawidlowy element w macierzy.";
        case BLAD_WYMIARY: return "Niezgodne wymiary macierzy.";
        case BLAD_OPERACJA: return "Nieprawidlowy numer operacji.";
        case BLAD_ZAPISU: return "Nie mozna zapisac do pliku.";
    }
}


//prototypy funkcji
void wypisz(double M[MAX][MAX], int w, int k);                                                   //wypisz
void dodaj(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);                     //dodaj
void odejmij(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k);                   //odejmij
void pomnoz(double A[MAX][MAX], double B[MAX][MAX], double C[MAX][MAX], int wA, int kA, int kB); //mnozenie A i B
const char* opis_bledu(int kod);
int zgodne_do_sumy(int wA, int kA, int wB, int kB);    //zgodne do sumy
int wymiary_zgodne_MAX(int w, int k);                      //zgodne z MAX
int wczytaj_macierz(const char *nazwa, double M[][MAX], int *w, int *k);
int zapisz_macierz(const char *nazwa, double M[][MAX], int w, int k);
int wykonaj(int op, double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC);

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





//wczytaj
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


//zapis do pliku
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



/*===============================================================================================================================================*/
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