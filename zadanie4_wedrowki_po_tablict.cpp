#include <iostream>
#include <vector>
#include <cstdio>
#include <deque>
#include <ctime>
#include <cstdlib>
using namespace std;

int n;
int tablica[100][100];
int tablica_z_wynikami[100][100];
vector<pair<int, int> > tablica_sasiadow[100][100];

bool pionoweZero, pionowePlus, pionoweMinus, poziomeZero, poziomePlus, poziomeMinus = false;
int punkty_tablicy = 0;

struct dane_wierzcholka
{
    pair <int, int> biezacy;
    pair <int, int> poprzednik;
};





void wyswietl_tablice_poczatkowa() {

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%3d", tablica[i][j]-1);
        }
        cout << "\n";
    }
}
void wypelnij_tablice_wektorow_sasiadow() {

    vector<pair<int, int> > *wektor_par;
    pair<int, int> wierzcholek;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            wektor_par = new vector<pair<int, int> >;
            if( i>0 && j>0 && tablica[i-1][j-1] == tablica[i][j] ) {
                wierzcholek.first = i-1; wierzcholek.second = j-1;
                wektor_par->push_back(wierzcholek);
            }
            if( i>0 && tablica[i-1][j] == tablica[i][j] ) {
                wierzcholek.first = i-1; wierzcholek.second = j;
                wektor_par->push_back(wierzcholek);
            }
            if( i>0 && j<n-1 && tablica[i-1][j+1] == tablica[i][j] ) {
                wierzcholek.first = i-1; wierzcholek.second = j+1;
                wektor_par->push_back(wierzcholek);
            }
            if(j<n-1 && tablica[i][j+1] == tablica[i][j] ) {
                wierzcholek.first = i; wierzcholek.second = j+1;
                wektor_par->push_back(wierzcholek);
            }
            if(i<n-1 && j<n-1 && tablica[i+1][j+1] == tablica[i][j] ) {
                wierzcholek.first = i+1; wierzcholek.second = j+1;
                wektor_par->push_back(wierzcholek);
            }
            if(i<n-1 && tablica[i+1][j] == tablica[i][j] ) {
                wierzcholek.first = i+1; wierzcholek.second = j;
                wektor_par->push_back(wierzcholek);
            }
            if(i<n-1 && j>0 && tablica[i+1][j-1] == tablica[i][j] ) {
                wierzcholek.first = i+1; wierzcholek.second = j-1;
                wektor_par->push_back(wierzcholek);
            }
            if(j>0 && tablica[i][j-1] == tablica[i][j] ) {
                wierzcholek.first = i; wierzcholek.second = j-1;
                wektor_par->push_back(wierzcholek);
            }
            tablica_sasiadow[i][j] = *wektor_par;
        }

    }
}





void BFS(pair<int, int> wierzcholek_startowy, bool czy_pionowo)
{
  deque<dane_wierzcholka> kolejka_analizowanych;
  deque<dane_wierzcholka> kolejka_odwiedzonych;
  dane_wierzcholka wierzcholek;
  pair<int, int> sasiad;
  bool znaleziony;
  dane_wierzcholka odwiedzony, pierwszy;

  pierwszy.biezacy = wierzcholek_startowy;
  pierwszy.poprzednik.first = pierwszy.poprzednik.second = -1;
  kolejka_analizowanych.push_front(pierwszy); 

  while(kolejka_analizowanych.size() != 0) 
  {
	  wierzcholek = kolejka_analizowanych.front(); 
      kolejka_analizowanych.pop_front();

      for(int a=0; a<tablica_sasiadow[wierzcholek.biezacy.first][wierzcholek.biezacy.second].size(); a++) {
        sasiad = tablica_sasiadow[wierzcholek.biezacy.first][wierzcholek.biezacy.second][a];
        znaleziony = false;
        for (int a=0;a<kolejka_odwiedzonych.size();a++)
        {
            if( kolejka_odwiedzonych.at(a).biezacy == sasiad ) {
                znaleziony = true;
                break;
            }
        }
        if( znaleziony == false ) {
            for (int b=0;b<kolejka_analizowanych.size();b++)
            {
                if( kolejka_analizowanych.at(b).biezacy == sasiad ) {
                    znaleziony = true;
                    break;
                }
            }
            if( znaleziony == false ){
                odwiedzony.biezacy = sasiad;
                odwiedzony.poprzednik = wierzcholek.biezacy;
                kolejka_analizowanych.push_back(odwiedzony);
            }

        }
      }
      kolejka_odwiedzonych.push_back(wierzcholek);

      int indx = kolejka_odwiedzonych.size()-1;
      if (czy_pionowo==true && wierzcholek.biezacy.first==n-1)
      {
          ++punkty_tablicy;
          while(wierzcholek.poprzednik.first!=-1)
          {
            if (kolejka_odwiedzonych[indx].biezacy == wierzcholek.poprzednik)
            {
                ++tablica_z_wynikami[wierzcholek.biezacy.first][wierzcholek.biezacy.second];

              wierzcholek = kolejka_odwiedzonych[indx];
            }
            --indx;

          }
          ++tablica_z_wynikami[wierzcholek.biezacy.first][wierzcholek.biezacy.second];
          return;
      }
      if (czy_pionowo==false && wierzcholek.biezacy.second==n-1)
      {
          ++punkty_tablicy;
          while(wierzcholek.poprzednik.first!=-1)
          {
              if (kolejka_odwiedzonych[indx].biezacy == wierzcholek.poprzednik)
            {
                ++tablica_z_wynikami[wierzcholek.biezacy.first][wierzcholek.biezacy.second];

              wierzcholek = kolejka_odwiedzonych[indx];
            }
            --indx;
          }
          ++tablica_z_wynikami[wierzcholek.biezacy.first][wierzcholek.biezacy.second];
          return;
      }
  }
}




void wyswietl_sasiadow_dla_wierzkolka(int i, int j) {

    pair<int, int> wierzcholek;
    for(int a=0; a<tablica_sasiadow[i][j].size(); a++) {
        wierzcholek = tablica_sasiadow[i][j][a];
    }
}


int main()
{
    pair <int, int> tmp;
    int biezacy_element;

    cout << "Podaj szerokosc tablicy:\n";
    cin >> n;
    srand(time(NULL));

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            tablica[i][j] = rand() % 3;
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            tablica_z_wynikami[i][j] = 0;
        }
    }
    cout << "Wygenerowana tablica wejsciowa:\n";
    wyswietl_tablice_poczatkowa();
    wypelnij_tablice_wektorow_sasiadow();

    wyswietl_sasiadow_dla_wierzkolka(0,1);

    for( int kolumna=0; kolumna<n; kolumna++) {
        biezacy_element = tablica[0][kolumna];
        if( biezacy_element == 0 && !pionoweMinus) {
            tmp.first = 0; tmp.second=kolumna;
            pionoweMinus=true;
            BFS(tmp, true);
        }
        if( biezacy_element == 1 && !pionoweZero) {
            tmp.first = 0; tmp.second=kolumna;
            pionoweZero=true;
            BFS(tmp, true);
        }
        if( biezacy_element == 2 && !pionowePlus) {
            tmp.first = 0; tmp.second=kolumna;
            pionowePlus=true;
            BFS(tmp, true);
        }
    }
    for( int wiersz=0; wiersz<n; wiersz++) {
        biezacy_element = tablica[wiersz][0];
        if( biezacy_element == 0 && !poziomeMinus) {
            tmp.first = wiersz; tmp.second=0;
            poziomeMinus=true;
            BFS(tmp, false);
        }
        if( biezacy_element == 1 && !poziomeZero) {
            tmp.first = wiersz; tmp.second=0;
            poziomeZero=true;
            BFS(tmp, false);
        }
        if( biezacy_element == 2 && !poziomePlus) {
            tmp.first = wiersz; tmp.second=0;
            poziomePlus=true;
            BFS(tmp, false);
        }
    }


    cout << "\nTablica znalezionych sciezek\n";
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
           if (tablica_z_wynikami[i][j] == 0)
           {
               cout << " -  ";
           }
           if (tablica_z_wynikami[i][j] == 1)
           {
               printf("%2d", tablica[i][j]-1); cout << "  ";
           }
           if (tablica_z_wynikami[i][j] == 2)
           {
                printf("%2d", tablica[i][j]-1); cout << "* ";
           }
        }
        cout << "\n";
    }

    cout << "Punkty tablicy: " << punkty_tablicy;
    cout << "\nLegenda:\n - -> przez ten punkt nie przechodzi sciezka\n -1 -> przez ten punkt przechodzi jedna sciezka -1 \n -1* -> przez ten punkt przechodza dwie sciezki -1\n 0 -> przez ten punkt przechodzi jedna sciezka 0 \n 0* -> przez ten punkt przechodza dwie sciezki 0\n 1 -> przez ten punkt przechodzi jedna sciezka 1 \n 1* -> przez ten punkt przechodza dwie sciezki 1\n";


    return 0;
}
