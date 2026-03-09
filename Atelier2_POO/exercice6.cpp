#include <iostream>
using namespace std;

// ==========================================================
// 1️.VERSION AVEC ADRESSES (pointeurs) - Méthode du C
// ==========================================================

// Fonction qui incrémente la valeur pointée par le pointeur
void incrementer(int *p) {
    (*p)++;  // On ajoute 1 à la valeur contenue à l’adresse p
}

// Fonction qui échange les valeurs de deux entiers via leurs adresses
void permuter(int *a, int *b) {
    int temp = *a;  // on sauvegarde la valeur pointée par a
    *a = *b;        // on met la valeur pointée par b dans a
    *b = temp;      // on met la valeur sauvegardée dans b
}

// ==========================================================
// 2️.VERSION AVEC RÉFÉRENCES - Méthode du C++
// ==========================================================

// Fonction qui incrémente directement la variable passée par référence
void incrementer_ref(int &x) {
    x++;  // La variable est modifiée directement
}

// Fonction qui échange deux variables passées par référence
void permuter_ref(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// ==========================================================
// 3️. PROGRAMME PRINCIPAL
// ==========================================================

int main() {
    // Déclaration des variables
    int a = 5, b = 10;

    cout << "===== VERSION AVEC ADRESSES (pointeurs) =====" << endl;
    cout << "Avant incrementer : a = " << a << endl;
    incrementer(&a); // on envoie l'adresse de a
    cout << "Après incrementer : a = " << a << endl;

    cout << "\nAvant permuter : a = " << a << ", b = " << b << endl;
    permuter(&a, &b); // on envoie les adresses
    cout << "Après permuter : a = " << a << ", b = " << b << endl;


    cout << "\n===== VERSION AVEC RÉFÉRENCES =====" << endl;
    cout << "Avant incrementer_ref : a = " << a << endl;
    incrementer_ref(a); // pas besoin d'adresse ni d'*
    cout << "Après incrementer_ref : a = " << a << endl;

    cout << "\nAvant permuter_ref : a = " << a << ", b = " << b << endl;
    permuter_ref(a, b);
    cout << "Après permuter_ref : a = " << a << ", b = " << b << endl;

    return 0;
}
