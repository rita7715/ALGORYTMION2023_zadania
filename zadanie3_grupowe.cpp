#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cmath>


using namespace std;


vector <char> wczytane_znaki;
char tablica[100][100];
int ilosc_elementow_zbioru = 0;
char element_neutralny;



bool lacznosc_dzialania()
{
    char ab, ab_c, bc, a_bc;
    int iab, ibc;

    for(int ia=0; ia<ilosc_elementow_zbioru; ia++) {

        for(int ib=0; ib<ilosc_elementow_zbioru; ib++) {
            ab = tablica[ia][ib];
            iab = int(ab) - 97;
            for(int ic=0; ic<ilosc_elementow_zbioru; ic++) {
                ab_c = tablica[iab][ic];
                bc = tablica[ib][ic];
                ibc = int(bc) - 97;
                a_bc = tablica[ia][ibc];

                if (a_bc != ab_c)
                {
                    cout << "Niespelniony jest warunek lacznosci\n";
                    exit(0);
                }
            }
        }

    }
    return true;
}

bool istnieje_element_neutralny()
{
    char ab, ba;
    int iab, iba;
    for(int ia=0; ia<ilosc_elementow_zbioru; ia++) {

        for(int ib=0; ib<ilosc_elementow_zbioru; ib++) {
            //if( ia == ib ) break;
            ab = tablica[ia][ib];
            iab = int(ab) - 97;
            ba = tablica[ib][ia];
            iba = int(ba) - 97;
            if( iab != ib || iba != ib) {

                break;
            }
            if( ib == ilosc_elementow_zbioru-1) {

                element_neutralny = char(ia+97);
                return true;
            }
        }
    }
    cout << "Brak elementu neutralnego\n";
    exit(0);
}

bool istnieje_element_odwrotny()
{
    char ab, ba;
    int iab, iba;
    for(int ia=0; ia<ilosc_elementow_zbioru; ia++) {

        for(int ib=0; ib<ilosc_elementow_zbioru; ib++) {
            //if( ia == ib ) break;
            if (tablica[ia][ib] == element_neutralny)
            {
                if (tablica[ia][ib] != tablica[ib][ia])
                {
                    cout << "Brak elementu odwrotnego\n";
                    exit(0);
                }
            }


        }
    }
    return true;
}

bool przemiennosc_dzialania()
{
    char ab, ba;
    int iab, iba;
    for(int ia=0; ia<ilosc_elementow_zbioru; ia++) {

        for(int ib=0; ib<ilosc_elementow_zbioru; ib++) {
            //if( ia == ib ) break;
            ab = tablica[ia][ib];
            iab = int(ab) - 97;
            ba = tablica[ib][ia];
            iba = int(ba) - 97;
            if( iab != iba) {
            cout << "To jest grupa, ale nie abelowa\n";
            exit(0);
            }

        }
    }
    return true;
}

void wyswietlenie_tablicy_dzialan() {

    for (int i=0;i<ilosc_elementow_zbioru;i++)
    {
        for (int j=0;j<ilosc_elementow_zbioru;j++)
        {
            cout << tablica[i][j] << " ";
        }
        cout << "\n";
    }
}


int main()
{
    char znak_wczytywany;

    ifstream wejscie ("g.txt");
    while (wejscie >> znak_wczytywany)
    {
        wczytane_znaki.push_back(znak_wczytywany);
    }

    ilosc_elementow_zbioru = sqrt(wczytane_znaki.size());

    for (int i=0;i<ilosc_elementow_zbioru;i++)
    {
        for (int j=0;j<ilosc_elementow_zbioru;j++)
        {
            tablica[i][j] = wczytane_znaki[i*ilosc_elementow_zbioru+j];
        }
    }

    wyswietlenie_tablicy_dzialan();

    if( lacznosc_dzialania() && istnieje_element_neutralny() && istnieje_element_odwrotny() ) {
        if( przemiennosc_dzialania() ) {
            cout << "To jest grupa abelowa.";
        }
    }

    return 0;
}
