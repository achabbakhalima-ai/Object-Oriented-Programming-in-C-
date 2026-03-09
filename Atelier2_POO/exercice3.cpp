
#include <iostream>
using namespace std;

int main() {
    int tab[10]; // Déclaration d'un tableau de 10 entiers

    // ===============================
    // LECTURE DU TABLEAU
    // ===============================
    cout << "Entrez 10 nombres entiers :" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Nombre " << i + 1 << " : ";
        cin >> tab[i];
    }

   
    // A.formalisme tableau
    

    // On suppose au départ que le plus grand et le plus petit sont le premier élément
    int max1 = tab[0];
    int min1 = tab[0];

    // Parcours du tableau avec les indices
    for (int i = 1; i < 10; i++) {
        if (tab[i] > max1)
            max1 = tab[i]; // nouvelle valeur maximale trouvée
        if (tab[i] < min1)
            min1 = tab[i]; // nouvelle valeur minimale trouvée
    }

    cout << "\n=== formalisme tableau ===" << endl;
    cout << "Le plus grand nombre est : " << max1 << endl;
    cout << "Le plus petit nombre est : " << min1 << endl;


   
    // B. formalisme pointeur 
    

    // Déclaration d’un pointeur vers int
    int *p;

    // On suppose au départ que le plus grand et le plus petit sont le premier élément
    int max2 = *tab; // *tab équivaut à tab[0]
    int min2 = *tab;

    // Parcours du tableau avec un pointeur
    // p commence au deuxième élément (tab + 1)
    // et s’arrête avant tab + 10 (après le dernier élément)
    for (p = tab + 1; p < tab + 10; p++) {
        if (*p > max2)
            max2 = *p; // *p = valeur du tableau pointée par p
        if (*p < min2)
            min2 = *p;
    }

    cout << "\n===formalisme pointeur ===" << endl;
    cout << "Le plus grand nombre est : " << max2 << endl;
    cout << "Le plus petit nombre est : " << min2 << endl;

    return 0;
}
