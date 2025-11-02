#include <iostream>
using namespace std;

// Définition de la classe Pile
class Pile {
private:
    int* elements;   // tableau dynamique pour stocker les éléments
    int sommet;      // indice du dernier élément ajouté
    int capacite;    // taille maximale de la pile

public:
    // --- Constructeur ---
    Pile(int taille) {
        capacite = taille;
        elements = new int[capacite]; // allocation dynamique du tableau
        sommet = -1; // -1 indique que la pile est vide
    }

    // --- Méthode pour empiler un élément (push) ---
    void push(int valeur) {
        if (sommet >= capacite - 1) {
            cout << "Erreur : la pile est pleine !" << endl;
        } else {
            sommet++;
            elements[sommet] = valeur;
            cout << "Empile : " << valeur << endl;
        }
    }

    // --- Méthode pour dépiler un élément (pop) ---
    int pop() {
        if (sommet < 0) {
            cout << "Erreur : la pile est vide !" << endl;
            return -1; // valeur de retour spéciale
        } else {
            int valeur = elements[sommet];
            sommet--;
            cout << "Depile : " << valeur << endl;
            return valeur;
        }
    }

    // --- Méthode pour vérifier si la pile est vide ---
    bool estVide() {
        return (sommet == -1);
    }

    // --- Destructeur ---
    ~Pile() {
        delete[] elements; // libération de la mémoire
    }
};

// --- Programme principal ---
int main() {
    // Création de deux piles de capacité 5
    Pile p1(5);
    Pile p2(5);

    cout << "=== Test de la pile p1 ===" << endl;
    p1.push(10);
    p1.push(20);
    p1.push(30);

    p1.pop(); // doit dépiler 30
    p1.pop(); // doit dépiler 20

    cout << "\n=== Test de la pile p2 ===" << endl;
    p2.push(5);
    p2.push(15);
    p2.pop(); // doit dépiler 15
    p2.pop(); // doit dépiler 5
    p2.pop(); // erreur car vide

    return 0;
}
