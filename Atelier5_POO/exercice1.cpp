#include <iostream>
#include <set>
#include <vector>
#include <list>
using namespace std;

// 2. Recherche dans un set
bool rechercheSet(const set<int>& s, int valeur) {
    return s.find(valeur) != s.end();
}

// 3. Recherche avec deux iterateurs spécifiques à set
bool rechercheIterSet(set<int>::const_iterator debut,
                      set<int>::const_iterator fin,
                      int valeur) {

    for(auto it = debut; it != fin; ++it) {
        if(*it == valeur) return true;
    }
    return false;
}

// 4. Template : recherche générique
template <typename Iter, typename T>
bool rechercheGenerique(Iter debut, Iter fin, const T& valeur) {
    for(Iter it = debut; it != fin; ++it) {
        if(*it == valeur) return true;
    }
    return false;
}

int main() {

    // 1. Remplir un set<int> de 1 à 100
    set<int> s;
    for(int i = 1; i <= 100; i++) {
        s.insert(i);
    }

    // Exemple : recherche dans le set
    cout << "50 dans set ? " << (rechercheSet(s, 50) ? "oui" : "non") << endl;

    // Exemple 1 : vector<string>
    vector<string> vec = {"Bonjour", "Hello", "Salam"};
    cout << "Hello dans vector ? "
         << (rechercheGenerique(vec.begin(), vec.end(), string("Hello")) ? "oui" : "non") << endl;

    // Exemple 2 : list<int>
    list<int> lst = {10, 20, 30, 40};
    cout << "30 dans list ? "
         << (rechercheGenerique(lst.begin(), lst.end(), 30) ? "oui" : "non") << endl;

    // Exemple 3 : tableau float
    float tab[] = {1.1f, 2.2f, 3.3f};
    cout << "2.2 dans tableau ? "
         << (rechercheGenerique(tab, tab + 3, 2.2f) ? "oui" : "non") << endl;

    return 0;
}
