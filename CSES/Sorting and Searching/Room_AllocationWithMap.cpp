// 100% CORRECT
#include<iostream>
#include<map>
using namespace std;

typedef unsigned long long ull;

multimap<int, pair<int, int>> mp; // mapa koja sortira po pocetku, a vrednosti su kraj i indeks pocetnog unosa
multimap<int, pair<int, int>>::iterator it;

int res[(int)2e5]; // niz rezultata; res[i] = k => i = indeks pocetnog unosa, k = soba

multimap<int, int> s; // mapa koja sortira po kraju sobe, a vrednost je soba
multimap<int, int>::iterator roomIt;

int roomIndex; int k = 1; // roomIndex cuva trenutno potrebnu sobu, a k = broj soba

int main()
{
    // UNOS
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    int n; cin >> n;
    for (int i = 0; i < n; i++) { cin >> a >> b; mp.emplace(make_pair(a, make_pair(b, i))); }

    // prva soba
    s.emplace(make_pair(mp.begin()->second.first, k)); // mp.begin()->second.first = vreme odlaska
    res[mp.begin()->second.second] = k; // mp.begin()->second.second = indeks unosa

    it = mp.begin(); it++;
    for (;it != mp.end(); it++)
    {   
        roomIt = s.lower_bound(it->first);
        if (roomIt == s.begin()) // ako ne postoji soba gde je odlazak manji od trenutnog dolaska
        {   
            k++;
            s.emplace(make_pair(it->second.first, k)); // nova soba
            res[it->second.second] = k;
        }
        else // ako postoji soba gde je odlazak jednak ili veci od trenutnog dolaska, zatim pogledamo prvu sobu iza
        {
            roomIt--; // prva soba iza ce imati odlazak manji od trenutnog dolaska
            roomIndex = roomIt->second;
            res[it->second.second] = roomIndex;
            s.erase(roomIt);
            s.emplace(make_pair(it->second.first, roomIndex));
        }
    }
    cout << k << '\n'; // ili s.size()
    for (int i = 0; i < n; i++) cout << res[i] << ' ';


    return 0;
}
