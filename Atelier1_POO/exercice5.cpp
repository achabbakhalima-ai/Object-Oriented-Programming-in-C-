#include <iostream>
using namespace std;

// 🔹 Fonction pour remplir le tableau via pointeurs
void remplir(int* arr, int n) {
    cout << "Entrez " << n << " entiers :" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> *(arr + i); // utilisation de l'arithmétique de pointeurs
    }
}

// 🔹 Fonction pour afficher le tableau via pointeurs
void afficher(const int* arr, int n) {
    cout << "[ ";
    for (int i = 0; i < n; ++i) {
        cout << *(arr + i);
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

// 🔹 Fonction qui retourne une référence vers le plus grand élément
int& trouverMax(int* arr, int n) {
    int* maxPtr = arr; // pointeur vers le maximum (initialement premier élément)
    for (int i = 1; i < n; ++i) {
        if (*(arr + i) > *maxPtr)
            maxPtr = arr + i; // on déplace le pointeur vers le nouvel élément max
    }
    return *maxPtr; // on retourne une référence vers la valeur max
}

// 🔹 Fonction qui inverse le tableau en place (sans tableau intermédiaire)
void inverser(int* arr, int n) {
    int* debut = arr;         // pointeur sur le début du tableau
    int* fin = arr + n - 1;   // pointeur sur la fin du tableau

    while (debut < fin) {
        // échange des deux valeurs
        int temp = *debut;
        *debut = *fin;
        *fin = temp;

        ++debut;  // on avance vers le centre
        --fin;    // on recule vers le centre
    }
}

int main() {
    int n;
    cout << "Entrez la taille du tableau : ";
    cin >> n;

    // 🔹 Allocation dynamique du tableau
    int* arr = new int[n];

    // 🔹 Remplissage du tableau
    remplir(arr, n);

    cout << "\nTableau original : ";
    afficher(arr, n);

    // 🔹 Recherche du maximum
    int& maxVal = trouverMax(arr, n);
    cout << "\nLe maximum est : " << maxVal << endl;

    // 🔹 Modification du maximum directement via la référence
    cout << "Entrez une nouvelle valeur pour le maximum : ";
    cin >> maxVal; // modifie directement le tableau !
    
    cout << "\nTableau après modification du maximum : ";
    afficher(arr, n);

    // 🔹 Inversion du tableau
    inverser(arr, n);
    cout << "\nTableau après inversion : ";
    afficher(arr, n);

    // 🔹 Libération de la mémoire
    delete[] arr;
    cout << "\nMémoire libérée avec succès." << endl;

    return 0;
}

