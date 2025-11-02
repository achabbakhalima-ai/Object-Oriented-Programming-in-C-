#include <iostream>
#include <cstring> // pour memset et strcpy
using namespace std;

// =====================
// Définition de la classe Fichier
// =====================
class Fichier {
private:
    char* P;       // pointeur vers la zone mémoire (adresse du fichier en mémoire)
    int longueur;  // taille du fichier (en octets)

public:
    // --- Constructeur ---
    Fichier() {
        P = nullptr;     // au départ, aucun espace mémoire n’est alloué
        longueur = 0;
        cout << "Constructeur : Fichier créé." << endl;
    }

    // --- Méthode Creation ---
    void Creation(int taille) {
        // Allouer dynamiquement 'taille' octets
        P = new char[taille];
        longueur = taille;
        cout << "Creation : espace mémoire de " << longueur << " octets alloué." << endl;
    }

    // --- Méthode Remplit ---
    void Remplit() {
        if (P == nullptr) {
            cout << "Erreur : la mémoire n’a pas été allouée !" << endl;
            return;
        }

        // On va remplir la mémoire avec des caractères arbitraires (ici des lettres)
        for (int i = 0; i < longueur - 1; i++) {
            P[i] = 'A' + (i % 26); // lettres de A à Z
        }
        P[longueur - 1] = '\0'; // fin de chaîne (sécurité)
        cout << "Remplit : la zone mémoire a été remplie." << endl;
    }

    // --- Méthode Affiche ---
    void Affiche() {
        if (P == nullptr) {
            cout << "Erreur : la mémoire n’a pas été allouée !" << endl;
            return;
        }

        cout << "Affiche : contenu du fichier en mémoire :" << endl;
        cout << P << endl;
    }

    // --- Destructeur ---
    ~Fichier() {
        if (P != nullptr) {
            delete[] P; // libère la mémoire
            cout << "Destructeur : mémoire libérée." << endl;
        }
        else {
            cout << "Destructeur : aucune mémoire à libérer." << endl;
        }
    }
};

// =====================
// Programme principal
// =====================
int main() {
    cout << "=== Début du programme ===" << endl;

    // Création d'un objet Fichier dynamiquement (avec new)
    Fichier* f = new Fichier();

    // Appel des trois méthodes
    f->Creation(30);   // alloue 30 octets
    f->Remplit();      // remplit la mémoire
    f->Affiche();      // affiche le contenu

    // Destruction de l’objet (appel du destructeur)
    delete f;

    cout << "=== Fin du programme ===" << endl;
    return 0;
}
