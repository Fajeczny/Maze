#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "funkcje.h"
#include "interfejs.h"
#include "struktury.h"
using namespace std;

Labirynt **X;
Wspolrzedne pp;
Wspolrzedne pk;
Wspolrzedne pk2;
int w;
int k;

int czyint(string t)
{
    return atoi(t.c_str());
}

void menu()
{
    while (true)
    {
        system("cls");
        cout << "Program wyszukujacy najkrotsza droge w labiryncie, wyswietlajacy i zapisujacy labirynt\n";
        cout << endl;
        cout << "1. Wyszukiwanie drogi\n";
        cout << "2. Wczytanie labiryntu\n";
        cout << "3. Wyswietlenie labiryntu\n";
        cout << "4. Zapisanie labiryntu\n";
        cout << "5. Wyjscie z programu\n";
        cout << endl;
        cout << "Wybierz opcje: ";

        string tmp;
        cin >> tmp;
        int opcja = czyint(tmp);
        cout << endl;
        cout << endl;

        switch(opcja)
        {
            case 1:
                dlugosclabiryntu(X,w,k);
                wyswietlenie(X,w,k);
                if (X!=NULL)
                {
                    punktkoncowy(X,pk,w,k);
                    szukanie(pp,pk,pk2,X,w,k);
                }
                getch();
                break;
            case 2:
                X = wczytanie(w,k);
                getch();
                break;
            case 3:
                dlugosclabiryntu(X,w,k);
                wyswietlenie(X,w,k);
                getch();
                break;
            case 4:
                zapisanie(X,w,k);
                getch();
                break;
            case 5:
                return;
            default:
                cout << "Nieprawidlowa wartosc." ;
                getch();
                break;
        }
    }
    usuwanie(X,w);
}
