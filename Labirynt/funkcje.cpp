#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <conio.h>
#include "funkcje.h"
using namespace std;


Labirynt **wczytanie(int &w, int &k)
{
    Labirynt **L=NULL;
    w=0;
    k=0;
    string nazwa;
    string napis;
    cout << "Podaj nazwe labiryntu, ktory chcesz wczytac: ";
    cin >> nazwa;
    cout << endl;
    ifstream odczyt;
    odczyt.open(nazwa.c_str());
    if (odczyt.is_open())
    {
        cout << "Otwarcie pliku zakonczone sukcesem.\n";
        while (!odczyt.eof())
        {
            getline (odczyt,napis);
            w++;
        }
        k=napis.length();
    }
    odczyt.close();
    odczyt.clear();
    odczyt.open(nazwa.c_str());
    if (odczyt.is_open())
    {
        L=new Labirynt *[w];
        while (!odczyt.eof())
        {
            for (int i=0; i<w; i++)
            {
                L[i]=new Labirynt[k];
                for (int j=0; j<k; j++)
                {
                    odczyt >> L[i][j].znak;
                }
            }
            break;
        }
    }
    else
    {
        cout << "Nie ma takiego pliku lub nie mozna go otworzyc.\n";
    }
    cout << endl;
    odczyt.close();
    return L;
}

bool punktkoncowy(Labirynt **L, Wspolrzedne &pkonc, int w, int k)
{
    bool zmiana = false;
    for (int i=0; i<w; i++)
    {
        for (int j=0; j<k; j++)
        {
            if (L[i][j].znak=='3')
            {
                pkonc.y=i;
                pkonc.x=j;
                zmiana = true;
            }
        }
    }
    return zmiana;
}

void wyswietlenie(Labirynt **L, int w, int k)
{
    int *a;
    a=new int[w];
    int *b;
    b=new int[w];
    int q=0;
    int p=1;
    for (int i=0; i<w; i++)
    {
        b[i]=q;
        a[i]=p;
        if (q==9)
            cout << b[i]-8;
        if (q==19)
            cout << b[i]-17;
        if (q==29)
            cout << b[i]-26;
        if (q==39)
            cout << b[i]-35;
        if (q==49)
            cout << b[i]-44;
        else if ((q>=0 && q!=9) && (q!=19 && q!=29) && (q!=39 && q!=49))
            cout << " ";

        if (p>=10 && p<20)
            cout << a[i]-10;
        if (p>=20 && p<30)
            cout << a[i]-20;
        if (p>=30 && p<40)
            cout << a[i]-30;
        if (p>=40 && p<50)
            cout << a[i]-40;
        if (p>=50 && p<60)
            cout << a[i]-50;
        if (p>=60 && p<70)
            cout << a[i]-60;
        if (p>=70 && p<80)
            cout << a[i]-70;
        if (p<10)
            cout << a[i];

        for (int j=0; j<k; j++)
        {
            if (L[i][j].znak=='1')
                cout << (char)178;
            else if (L[i][j].znak=='2')
                cout << " ";
            else if (L[i][j].znak=='3')
                cout << "X";            
        }
        q++;
        p++;
        cout << endl;
    }
    cout << endl;
}

void dlugosclabiryntu(Labirynt **L, int w, int k)
{
    if(!L)
    {
        cout << "Nie wczytano labiryntu.";
        return;
    }

    cout << "Liczba wierszy: " << w << endl;
    cout << "Liczba  kolumn: " << k << endl;
    cout << endl;

    int *a;
    a=new int[k];
    int *b;
    b=new int[k];
    int p=0;
    int j=1;
    cout << "  ";

    for (int i=0; i<k; i++)
    {
        b[i]=p;
        if (p==9)
            cout << b[i]-8;
        if (p==18)
            cout << b[i]-16;
        if (p==27)
            cout << b[i]-24;
        if (p==36)
            cout << b[i]-32;
        if (p==45)
            cout << b[i]-40;
        if (p==54)
            cout << b[i]-48;
        if (p==63)
            cout << b[i]-56;
        else if (p>=0)
            cout << " ";
        p++;
    }
    cout << endl;
    cout << " 0";
    for (int i=0; i<k; i++)
    {
        a[i]=j;
            if (j>=10 && j<20)
                cout << a[i]-10;
            if (j>=20 && j<30)
                cout << a[i]-20;
            if (j>=30 && j<40)
                cout << a[i]-30;            
            if (j>=40 && j<50)
                cout << a[i]-40;
            if (j>=50 && j<60)
                cout << a[i]-50;
            if (j>=60 && j<70)
                cout << a[i]-60;
            if (j>=70 && j<80)
                cout << a[i]-70;
            if (j<10)
                cout << a[i];
        j++;
    }
    cout << endl;
}

void zapisanie(Labirynt **L, int w, int k)
{
    ofstream zapis;
    string nazwa;
    if(!L)
    {
        cout << "Nie wczytano labiryntu.";
        return;
    }
    else
    {
    cout << "Podaj nazwe pliku, do ktorego chcesz zapisac labirynt: ";
    cin >> nazwa;
    zapis.open(nazwa.c_str());
    for (int i=0; i<w; i++)
    {
        for (int j=0; j<k; j++)
        {
            zapis << L[i][j].znak;
        }
        if(i>=0 && i<w-1)
            zapis << endl;
    }
    zapis.close();
    }
    cout << endl;
    cout << "Poprawnie zapisano labirynt.";
}

bool punktpoczatkowy(Wspolrzedne &ppocz, Labirynt **L, int w, int k)
{
    bool zmiana2=false;
    if(!L)
    {
        cout << "Nie wczytano labiryntu.";
        zmiana2=false;
    }
    ppocz.x=0;
    ppocz.y=0;
    int x,y;
    cout << "Podaj wspolrzedna X: ";
    cin >> x;
    cout << "Podaj wspolrzedna Y: ";
    cin >> y;    
    cout << endl;

    if ((x-1>k-1 || x-1<0) || (y-1>w-1 || y-1<0))
    {
        cout << "Podano nieprawidlowe wspolrzedne.\n";
        zmiana2=false;
    }

    else{
        if(L[y-1][x-1].znak=='2')
        {
            ppocz.x = x-1;
            ppocz.y = y-1;
            zmiana2=true;
        }
        if(L[y-1][x-1].znak=='3')
        {
            cout << "Wybrany punkt poczatkowy jest w miejscu punktu koncowego.\n";
            zmiana2=false;
        }
        else if (L[y-1][x-1].znak!='2' && L[y-1][x-1].znak!='3')
        {
            cout << "Wybrany punkt znajduje sie w scianie.\n";
            zmiana2=false;
        }
    }
    return zmiana2;
}

bool zaznaczenie(int w, int k, char **mapa)
{
    bool zmiana2=false;
    int o;
    for(int i=1; i<(w-1); i++)
    {
        for(int j=1; j<(k-1); j++)
        {
            if(mapa[i][j]<0)
                continue; //jeśli ściana, sprawdź następny

            o=mapa[i][j]; //przed oznaczeniem

            if(mapa[i+1][j]>0) //prawo jeśli nie ma ściany, ale został odwiedzony
                if(mapa[i+1][j]+1<mapa[i][j] || mapa[i][j]==0) //i jeśli z tamtej drogi jest krócej do aktualnej,
                                                    //lub aktualna jest nieodwiedzona
                    mapa[i][j]=mapa[i+1][j]+1; //oznacza tutaj odległość poprzedniej+1

            if(mapa[i-1][j]>0) //lewo
                if(mapa[i-1][j]+1<mapa[i][j] || mapa[i][j]==0)
                    mapa[i][j]=mapa[i-1][j]+1;

            if(mapa[i][j+1]>0) //dół
                if(mapa[i][j+1]+1<mapa[i][j] || mapa[i][j]==0)
                    mapa[i][j]=mapa[i][j+1]+1;

            if(mapa[i][j-1]>0) //góra
                if(mapa[i][j-1]+1<mapa[i][j] || mapa[i][j]==0)
                    mapa[i][j]=mapa[i][j-1]+1;

            if(o!=mapa[i][j])
                zmiana2=true; //jeśli zaszła zmiana, ustawia na true, że była jakaś zmiana i kolejne wykonanie
                                    //może coś jeszcze zmienić
        }
    }
    return zmiana2;
}

void wyczyszczenie(int w, int k, char **mapa, Wspolrzedne ppocz, Wspolrzedne &pkonc)
{
    bool droga[w][k]; //przechowuje najkrótszą ścieżkę
    memset(droga, 0, w*k); //czyszczenie tablicy   
    while(ppocz.x!=pkonc.x || ppocz.y!=pkonc.y)
    { //dopóki nie dojdzie od końca do punktu początkowego
        droga[pkonc.x][pkonc.y]=true;
        //szukanie po sąsiadach najkrótszych odległości, tzn. mniejszych od aktualnej
        //wcześniejsza funkcja daje pewność, że różnice między odległościami zawsze wynoszą 1
        if(mapa[pkonc.x+1][pkonc.y]<mapa[pkonc.x][pkonc.y] && mapa[pkonc.x+1][pkonc.y]>0)
        {
            pkonc.x++;
            continue;
        }

        if(mapa[pkonc.x-1][pkonc.y]<mapa[pkonc.x][pkonc.y] && mapa[pkonc.x-1][pkonc.y]>0)
        {
            pkonc.x--;
            continue;
        }

        if(mapa[pkonc.x][pkonc.y+1]<mapa[pkonc.x][pkonc.y] && mapa[pkonc.x][pkonc.y+1]>0)
        {
            pkonc.y++;
            continue;
        }

        if(mapa[pkonc.x][pkonc.y-1]<mapa[pkonc.x][pkonc.y] && mapa[pkonc.x][pkonc.y-1]>0)
        {
            pkonc.y--;
            continue;
        }
        return; //jeśli jakimś sposobem nie ma najkrótszej drogi, przerywa
    }
    for(int i=1; i<w-1; i++)
    {
        for(int j=1; j<k-1; j++)
        {
            if(!droga[i][j])
                if(mapa[i][j]>0)
                    mapa[i][j]=0; //czyszczenie dłuższych dróg
        }
    }
    mapa[ppocz.x][ppocz.y]=1; //punkt startowy
}

void rysowaniedrogi(int w, int k, char **mapa, Wspolrzedne ppocz, Wspolrzedne pkonc2)
{
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(mapa[j][i]<0)
                cout << (char)178;
            if(mapa[j][i]==0)
                cout << " ";
            if (mapa[j][i]==1)
                cout << (char)15;
            if(j==pkonc2.x && i==pkonc2.y)
                cout << "X";
            else if(mapa[j][i]>0 && (j!=pkonc2.x || i!=pkonc2.y) && (j!=ppocz.x || i!=ppocz.y))
                cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

void szukanie(Wspolrzedne ppocz, Wspolrzedne pkonc, Wspolrzedne pkonc2, Labirynt **L, int w, int k)
{
    pkonc2=pkonc;
    char **mapa;
    mapa = new char *[w];
    for (int i=0; i<w; i++)
        mapa[i]=new char [k];

    bool zmiana;
    zmiana = punktkoncowy(L,pkonc,w,k);
    if (zmiana==false){
        cout << "Wczytany labirynt nie ma punktu koncowego.";
        return;
    }

    bool zmiana2;
    zmiana2 = punktpoczatkowy(ppocz,L,w,k);
    if (zmiana2==false)
        return;

    for(int i=0; i<(w*k); i++)
    { //przepisanie mapy, w tym przypadku trzeba ją obrócić
        if(L[i%w][i/k].znak=='1') //jeśli ściana
            mapa[i/k][i%w]=-1; //przypisz wartość ujemną
        else
            mapa[i/k][i%w]=0; //puste
    }
    mapa[ppocz.x][ppocz.y]=1;//punkt startowy

    while(zaznaczenie(w,k,mapa));//zaznaczanie na mapie kolejno odwiedzanych pól, dopóki są jakiś zmiany    
    wyczyszczenie(w,k, mapa, ppocz, pkonc); //pozostawia tylko najkrótszą ścieżkę
    cout << "Najkrotsza droga: \n";
    rysowaniedrogi(w,k,mapa,ppocz,pkonc2); //rysuje mapę po oczyszczeniu

    for (int i=0; i<w; i++)
        delete []mapa[i];
    delete []mapa;
}

void usuwanie (Labirynt **L, int w)
{
    for (int i=0; i<w; i++)
        delete []L[i];
    delete []L;
}
