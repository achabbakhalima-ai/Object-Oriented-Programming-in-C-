#include <iostream>
using namespace std;

int main() {
    int n; // variable pour la taille du tableau

    // 1️. Lecture de la taille du tableau
    cout << "Entrez la taille du tableau : ";
    cin >> n;

    if (n <= 0) {
        cout << "La taille doit être positive !" << endl;
        return 1; // arrêt du programme
    }

    // 2️. Allocation dynamique du premier tableau
    // new int[n] alloue un espace pour n entiers dans le tas (heap)
    int* tab = new int[n];

    // 3️. Lecture des valeurs du tableau
    cout << "\nEntrez " << n << " nombres entiers :" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nombre " << i + 1 << " : ";
        cin >> tab[i];
    }

    // 4️.Création dynamique d’un deuxième tableau pour stocker les carrés
    int* tabCarre = new int[n];

    // Calcul des carrés
    for (int i = 0; i < n; i++) {
        tabCarre[i] = tab[i] * tab[i];
    }

    // 5️.Suppression du premier tableau (il ne sert plus)
    delete[] tab;
    tab = nullptr; // sécurité : éviter d’utiliser une zone déjà libérée

    // 6️. Affichage du second tableau (les carrés)
    cout << "\nLes carrés des nombres sont : ";
    for (int i = 0; i < n; i++) {
        cout << tabCarre[i] << " ";
    }
    cout << endl;

    // 7️. Suppression du second tableau
    delete[] tabCarre;
    tabCarre = nullptr;

    cout << "\nMémoire libérée. Fin du programme." << endl;

    return 0;
}
