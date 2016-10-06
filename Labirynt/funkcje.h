#ifndef LABIRYNT
#define LABIRYNT

#include "struktury.h"

Labirynt **wczytanie(int &w, int &k);

bool punktkoncowy(Labirynt **L, Wspolrzedne &pkonc, int w, int k);

void wyswietlenie(Labirynt **L, int w, int k);

void dlugosclabiryntu(Labirynt **L, int w, int k);

void zapisanie(Labirynt **L, int w, int k);

bool punktpoczatkowy(Wspolrzedne &ppocz, Labirynt **L, int w, int k);

bool zaznaczenie(int w, int k, char **mapa);

void wyczyszczenie(int w, int k, char **mapa, Wspolrzedne ppocz, Wspolrzedne &pkonc);

void rysowaniedrogi(int w, int k, char **mapa, Wspolrzedne ppocz, Wspolrzedne pkonc2);

void szukanie(Wspolrzedne ppocz, Wspolrzedne pkonc, Wspolrzedne pkonc2, Labirynt **L, int w, int k);

void usuwanie(Labirynt **L, int w);

#endif // LABIRYNT
