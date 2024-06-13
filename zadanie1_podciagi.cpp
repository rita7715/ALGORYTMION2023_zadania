#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int odp=0;
vector<vector<int> > indeksy_ciagu;
vector<vector<int> > indeksy_uzupelniajace;
vector<int> biezace_indeksy;
vector <int> wszystkie_indeksy;
vector <int> pozostale_indeksy;

int n;


void wszystko(int n, string samzbior) {
    int ile_zer = 0;

    if (n == 0) {
        for (int i = 0; (i = samzbior.find('0', i)) != std::string::npos; i++) {
            ile_zer++;
        }
        if( ile_zer%2 == 0) {
            vector <int> v1;
            for (int i=0;i<samzbior.length();i++)
            {
                v1.push_back(i+1);
            }
            bool czy_bylo = false;
            for (int i = 0; i < indeksy_ciagu.size(); i++) {
                   vector <int> v2 = indeksy_ciagu[i];

                   vector<int> diff;

                   set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(diff, diff.begin()));
                   for (int j=0;j<v2.size();j++)
                   {
                       if (czy_bylo==true)
                       {
                           break;
                       }
                       if (samzbior[v2[j]-1] != samzbior[diff[j]-1])
                       {
                           break;
                       }
                       if (j==v2.size()-1)
                       {
                           ++odp;
                           czy_bylo=true;
                           break;
                       }


                   }


            }
        }
 return;
    }
    wszystko(n-1, samzbior + "0");
    wszystko(n-1, samzbior + "1");
}



void kombinacje(int j, int k)
{
    if (k == 0) {
        indeksy_ciagu.push_back(biezace_indeksy);
        return;
    }
    for (int i = j; i <= n; i++)
    {
        biezace_indeksy.push_back(i);
        kombinacje(i + 1, k - 1);
        biezace_indeksy.pop_back();
    }
}


int main() {

cout << "wpisz liczbe n\n";
    cin >> n;
    if (n%2!=0)
    {
        cout << 0;
        exit(0);
    }

    for (int i=0;i<n;i++)
    {
        wszystkie_indeksy.push_back(i+1);
    }

    kombinacje(2, n/2);
    wszystko(n, "");
    cout << "Ciagow o dlugosci " << n << " o podanej cesze jest " << odp;
    return 0;
}
