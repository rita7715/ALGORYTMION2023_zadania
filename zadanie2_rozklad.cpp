#include <bits/stdc++.h>

using namespace std;

int liczba_rozkladow=0;
vector<int> rozklad;
vector<int> pierwsze;

void odejmowanie(int a, int i)
{
	if (a == 0) {
            ++liczba_rozkladow;
            for (int i=0;i<rozklad.size()-1;i++)
            {
                cout << rozklad[i] << " + ";
            }
            cout << rozklad[rozklad.size()-1];
            cout << "\n";

		return;
	}

	while (i < pierwsze.size() && a - pierwsze[i] >= 0) {

		rozklad.push_back(pierwsze[i]);

		odejmowanie(a - pierwsze[i], i);
		i++;


		rozklad.pop_back();
	}
}

bool czy_pierwsza(int n){
    for(int i = 2;i<=sqrt(n);i++){
          if(n % i == 0) return false;
    }
    return true;
}


int main()
{
    int n;

    cin >> n;

    if (n <=3)
    {
        cout << 0;
        exit(0);
    }

	for (int i=2;i<n;i++)
    {
        if (czy_pierwsza(i))
        {
            pierwsze.push_back(i);
        }
    }

    cout << "Poszczegolne rozklady: \n";
	odejmowanie(n, 0);
	cout << "\nLiczba rozkladow: " << liczba_rozkladow;

    return 0;
}
