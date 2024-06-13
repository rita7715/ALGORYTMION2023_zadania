#include <bits/stdc++.h>
using namespace std;

char *tr(char *str)
{
    static char buff[256];
    char cp[] = "\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215πÊÍ≥ÒÛúøü•∆ £—”åØè";
    char *bf = buff;
    while(*str)
    {
        char *pos=strchr(cp+18, *str);
        *(bf++)=pos?*(pos-18):*str;
        ++str;
    }
    *bf=0;
    return buff;
}

int main()
{
    ifstream wejscie("slownik.txt");
    string a;
    int ilosc_linii=0;
    vector <string> slowa;
    while(wejscie>> a)
    {
        if (a.length()==5)
        {
            ilosc_linii++;
            slowa.push_back(a);

        }
    }
   srand( (time(0)<<(time(0)%10)) + (time(0)%10) );
   int random_number = rand() % ilosc_linii-1;
    char* c = const_cast<char*>(slowa[random_number].c_str());
    string ccc = slowa[random_number];
    vector <char> znakislowa;
    vector <char> niepoprawne;
    string zoltelitery="";
    vector <int> indeks_zoltych_liter;
    string poprawne = ",,,,,";
//  cout <<   tr(c) << "\n";
   cout << tr("Odgadnij piÍcioliterowe s≥owo. Masz szeúÊ prÛb.\nLegenda:\n* - litera na dobrym miejscu\n' - litera na z≥ym miejscu\nbrak oznakowania - litery nie ma w wyrazie\n\n");
  string czy_latwiejsza="";
   while(czy_latwiejsza != "1" && czy_latwiejsza != "2")
   {
       cout << tr("1 - £atwiejsza wersja, 2 - trudniejsza wersja\nWersje rÛøniπ siÍ od siebie tym, øe w trudniejszej wersji:\n- Litery oznaczone gwiazdkπ musisz podaÊ na tym samym miejscu\n- Litery oznaczone apostrofem musisz podaÊ, ale na innym miejscu\n- Nieoznaczonych liter nie moøesz ponownie uøywaÊ\n");
       cout << tr("KtÛra wersja? ");
       cin >> czy_latwiejsza;
   }
   if (czy_latwiejsza == "2")
   {
       for (int i=1;i<=6;i++)
   {
       cout << "\n";
       for (int ii=0;ii<ccc.length();ii++)
    {
        znakislowa.push_back(c[ii]);
    }
       bool czy_odpowiedz = true;
       string wpisywany_tekst;

       bool czy_poprawny=false;
       while(czy_poprawny==false)
       {
           cout << "Twoja " << i << " proba\n";

       cin >> wpisywany_tekst;
       for (int k=0;k<ilosc_linii;k++)
       {
           if (wpisywany_tekst.length()>5)
           {
               cout << "Za dlugie slowo\n";
               break;
           }
           if (wpisywany_tekst.length()<5)
           {
               cout << "Za krotkie slowo\n";
               break;
           }
           char* ct = const_cast<char*>(slowa[k].c_str());
           if (wpisywany_tekst == tr(ct))
           {
               czy_poprawny = true;
               for (int j=0;j<niepoprawne.size();j++)
               {
                   for (int jj=0;jj<5;jj++)
                   {
                       if (wpisywany_tekst[jj] == niepoprawne[j])
                       {
                           czy_poprawny = false;
                           cout << "Zostala podana litera, ktora byla podana wczesniej i nie zostala oznaczona zadnym znakiem\n";
                           break;
                       }

                   }
                   if (czy_poprawny==false)
                       {
                           break;
                       }
               }
               if (czy_poprawny==false)
                       {
                           break;
                       }
               for (int jj=0;jj<5;jj++)
                   {
                       if (poprawne[jj] != ',' && poprawne[jj] != wpisywany_tekst[jj])
                       {
                           czy_poprawny = false;
                           cout << "Nie podano litery na poprawnym miejscu, choc juz wiadomo, ze tam powinna byc\n";
                           break;
                       }

                   }

               if (czy_poprawny==false)
                       {
                           break;
                       }
                       for (int jj=0;jj<zoltelitery.length();jj++)
                       {



                               if (wpisywany_tekst[indeks_zoltych_liter[jj]] == zoltelitery[jj])
                               {
                                   czy_poprawny = false;
                                   cout << "Litera oznaczona wczesniej apostrofem pojawila sie w tym samym miejscu\n";
                                   break;
                               }
                               for (int jjj=0;jjj<5;jjj++)
                               {
                                  if( wpisywany_tekst[jjj] == zoltelitery[jj])
                                  {
                                      break;
                                  }else
                                  {
                                      if (jjj==4)
                                      {
                                          czy_poprawny= false;
                                          cout << "Litera oznaczona wczesniej apostrofem sie nie pojawila\n";
                                          break;
                                      }
                                  }
                                  if (czy_poprawny==false)
                                  {
                                      break;
                                  }
                               }

                       }
                       break;

           }
           if (k==ilosc_linii-1)
               {
                   cout << "Nie ma takiego wyrazu w bazie\n";
               }

       }
       }

       char* wpisywany_tekst2 = const_cast<char*>(wpisywany_tekst.c_str());
       for (int j=0;j<5;j++)
       {


           if (wpisywany_tekst2[j] == tr(c)[j])
           {
               poprawne[j] = wpisywany_tekst2[j];
               remove(znakislowa.begin(),znakislowa.end(),wpisywany_tekst2[j]);
               cout << wpisywany_tekst2[j] << "* ";

           }else
           {
               czy_odpowiedz = false;
               for (int k=0;k<5;k++)
               {
                   if (tr(c)[k] == wpisywany_tekst2[j])
                   {
                       for (int l=0;l<znakislowa.size();l++)
                       {
                           if (wpisywany_tekst2[j] == znakislowa[l] && wpisywany_tekst2[l] != znakislowa[l])
                           {
                               zoltelitery += tr(wpisywany_tekst2)[j];
                               indeks_zoltych_liter.push_back(j);

               cout << wpisywany_tekst2[j] << "' ";
               remove(znakislowa.begin(),znakislowa.end(),znakislowa[l]);
               break;
                           }
                           if (l==znakislowa.size()-1)
                           {
                               for (int hh=0;hh<5;hh++)
                               {
                                   if (c[hh] == wpisywany_tekst2[j])
                                   {
                                       break;
                                   }else
                                   {
                                       if (hh==4)
                                       {
                                           niepoprawne.push_back(wpisywany_tekst2[j]);
                                       }
                                   }
                               }


               cout << wpisywany_tekst2[j] << " ";
               break;
                           }
                       }

               break;
                   }else
                   {

                       if (k==4)
                       {
                           niepoprawne.push_back(wpisywany_tekst2[j]);
               cout << wpisywany_tekst2[j] << " ";
                       }
                   }
               }


           }


       }
       if (czy_odpowiedz==true)
           {
               cout << tr("\nBrawo! Uda≥o Ci siÍ!");
               exit(0);
           }


   }
   }
if (czy_latwiejsza == "1")
{
    for (int i=1;i<=6;i++)
   {
       cout << "\n";
       for (unsigned int ii=0;ii<ccc.length();ii++)
    {
        znakislowa.push_back(ccc[ii]);
    }
       bool czy_odpowiedz = true;
       string wpisywany_tekst;

       bool czy_poprawny=false;
       while(czy_poprawny==false)
       {
           cout << "Twoja " << i << " proba\n";

       cin >> wpisywany_tekst;
       for (int k=0;k<ilosc_linii;k++)
       {
           if (wpisywany_tekst.length()>5)
           {
               cout << "Za dlugie slowo\n";
               break;
           }
           if (wpisywany_tekst.length()<5)
           {
               cout << "Za krotkie slowo\n";
               break;
           }
           char* ct = const_cast<char*>(slowa[k].c_str());
           if (wpisywany_tekst == tr(ct))
           {
               czy_poprawny = true;
               break;
           }
           if (k==ilosc_linii-1)
               {
                   cout << "Nie ma takiego wyrazu w bazie\n";
               }

       }
       }

       char* wpisywany_tekst2 = const_cast<char*>(wpisywany_tekst.c_str());
       for (int j=0;j<5;j++)
       {


           if (wpisywany_tekst2[j] == tr(c)[j])
           {
               remove(znakislowa.begin(),znakislowa.end(),wpisywany_tekst2[j]);
               cout << wpisywany_tekst2[j] <<"* ";

           }else
           {
               czy_odpowiedz = false;
               for (int k=0;k<5;k++)
               {
                   if (tr(c)[k] == wpisywany_tekst2[j])
                   {
                       for (int l=0;l<znakislowa.size();l++)
                       {
                           if (wpisywany_tekst2[j] == znakislowa[l] && znakislowa[l] != wpisywany_tekst2[l])
                           {
               cout << wpisywany_tekst2[j] << "' ";
               remove(znakislowa.begin(),znakislowa.end(),znakislowa[l]);
               break;
                           }
                           if (l==znakislowa.size()-1)
                           {
               cout << wpisywany_tekst2[j] << " ";
               break;
                           }
                       }

               break;
                   }else
                   {

                       if (k==4)
                       {
               cout << wpisywany_tekst2[j] << " ";
                       }
                   }
               }


           }


       }
       if (czy_odpowiedz==true)
           {
               cout << tr("\nBrawo! Uda≥o Ci siÍ!");
               exit(0);
           }


   }
}
   cout << tr("\nHas≥em by≥o ");
   cout << tr(c);
   cout << tr("\nSprÛbuj jeszcze raz. Na pewno Ci siÍ uda!");

    return 0;
}
