#include <iostream>
using namespace std;

// ===========================================================
// Fonction récursive pour afficher toutes les permutations
// ===========================================================

// La fonction prend :
// - une chaîne de caractères `str`
// - un indice `g` = position de départ
// - un indice `d` = position de fin
void permuter(string &str, int g, int d) {
    // Cas de base : si la position de départ = position de fin,
    // on a une permutation complète, donc on l'affiche
    if (g == d) {
        cout << str << endl;
    } else {
        // On échange chaque caractère possible avec celui de départ
        for (int i = g; i <= d; i++) {
            // Échanger str[g] et str[i]
            char temp = str[g];
            str[g] = str[i];
            str[i] = temp;

            // Appel récursif : on fixe le caractère à la position g,
            // et on permute les caractères restants
            permuter(str, g + 1, d);

            // Retour en arrière (backtracking)
            // pour restaurer la chaîne initiale avant la prochaine boucle
            temp = str[g];
            str[g] = str[i];
            str[i] = temp;
        }
    }
}

// ===========================================================
//  Fonction principale
// ===========================================================
int main() {
    string mot;

    cout << "Entrez une chaine de caracteres : ";
    cin >> mot;

    cout << "\nToutes les permutations possibles sont : " << endl;
    permuter(mot, 0, mot.length() - 1);

    return 0;
}
