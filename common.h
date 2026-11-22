#ifndef COMMON_H
#define COMMON_H
#define MAX 20
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

const char* opis_bledu(int kod);

#endif