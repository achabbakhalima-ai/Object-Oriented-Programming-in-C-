#include <iostream>
using namespace std;

// ------------------------
// Structure Element
// ------------------------
struct Element {
    int valeur;       // valeur stockée
    Element* suivant; // pointeur vers l'élément suivant
};

// ------------------------
// Classe Liste
// ------------------------
class Liste {
private:
    Element* premier; // pointeur sur le premier élément de la liste

public:
    // --- Constructeur ---
    Liste() {
        premier = nullptr;
        cout << "Liste créée." << endl;
    }

    // --- Destructeur ---
    ~Liste() {
        while (premier != nullptr) {
            supprimerDebut(); // supprimer tous les éléments pour éviter les fuites
        }
        cout << "Liste détruite, mémoire libérée." << endl;
    }

    // --- Ajouter un élément au début ---
    void ajouterDebut(int val) {
        Element* nouveau = new Element; // création d'un nouvel élément
        nouveau->valeur = val;
        nouveau->suivant = premier;     // le suivant pointe sur l'ancien premier
        premier = nouveau;              // le nouveau devient le premier
        cout << "Ajouté : " << val << endl;
    }

    // --- Supprimer l'élément au début ---
    void supprimerDebut() {
        if (premier == nullptr) {
            cout << "La liste est vide, rien à supprimer." << endl;
            return;
        }
        Element* temp = premier;   // sauvegarde du premier
        premier = premier->suivant; // le suivant devient le nouveau premier
        cout << "Supprimé : " << temp->valeur << endl;
        delete temp;               // libération de la mémoire
    }

    // --- Afficher la liste ---
    void afficher() {
        if (premier == nullptr) {
            cout << "La liste est vide." << endl;
            return;
        }
        cout << "Contenu de la liste : ";
        Element* courant = premier;
        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }
        cout << endl;
    }
};

// ------------------------
// Programme principal
// ------------------------
int main() {
    Liste maListe;

    // Ajouter des éléments
    maListe.ajouterDebut(10);
    maListe.ajouterDebut(20);
    maListe.ajouterDebut(30);

    // Afficher la liste
    maListe.afficher(); // Doit afficher : 30 20 10

    // Supprimer des éléments
    maListe.supprimerDebut(); // Supprime 30
    maListe.afficher();       // Doit afficher : 20 10

    maListe.supprimerDebut(); // Supprime 20
    maListe.supprimerDebut(); // Supprime 10
    maListe.supprimerDebut(); // Liste vide

    maListe.afficher();       // Liste vide

    return 0;
}
