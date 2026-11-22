#include "common.h"

const char* opis_bledu(int kod) {
    switch (kod) {
        case BLAD_OTWARCIA: return "Nie mozna otworzyc pliku z macierza.";
        case BLAD_ZAKRES: return "Rozmiar macierzy poza MAX.";
        case BLAD_ZA_MALO: return "Brakujace elementy macierzy.";
        case BLAD_ELEMENT: return "Nieprawidlowy element w macierzy.";
        case BLAD_WYMIARY: return "Niezgodne wymiary macierzy.";
        case BLAD_OPERACJA: return "Nieprawidlowy numer operacji.";
        case BLAD_ZAPISU: return "Nie mozna zapisac do pliku.";
        default: return "Nieznany blad.";
    }
}
