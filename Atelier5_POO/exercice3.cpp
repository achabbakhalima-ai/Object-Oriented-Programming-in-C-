#include <iostream>
#include "vect.h"   
using namespace std;

// Classe dérivée vectok
class vectok : public vect {
public:
    // Constructeur : appel du constructeur de la classe de base
    vectok(int n) : vect(n) {}

    // Constructeur par copie : copie profonde
    vectok(const vectok& v) : vect(v.nelem) {
        for (int i = 0; i < nelem; i++)
            adr[i] = v.adr[i];
    }

    // Opérateur d’affectation : copie profonde
    vectok& operator=(const vectok& v) {
        if (this != &v) {  // éviter l’auto-affectation
            // libérer l’ancien espace
            delete[] adr;

            // allouer un nouvel espace et copier les éléments
            nelem = v.nelem;
            adr = new int[nelem];
            for (int i = 0; i < nelem; i++)
                adr[i] = v.adr[i];
        }
        return *this;
    }

    // Fonction membre taille()
    int taille() const {
        return nelem;
    }
};

// Programme de test
int main() {
    vectok v1(5);
    for (int i = 0; i < v1.taille(); i++)
        v1[i] = i * 10;

    cout << "v1 : ";
    for (int i = 0; i < v1.taille(); i++)
        cout << v1[i] << " ";
    cout << endl;

    // Test du constructeur par copie
    vectok v2 = v1;
    v2[0] = 100;  // modifier v2 ne doit pas affecter v1

    cout << "v2 : ";
    for (int i = 0; i < v2.taille(); i++)
        cout << v2[i] << " ";
    cout << endl;

    cout << "v1 après modification de v2 : ";
    for (int i = 0; i < v1.taille(); i++)
        cout << v1[i] << " ";
    cout << endl;

    // Test de l’opérateur d’affectation
    vectok v3(3);
    v3 = v1;

    cout << "v3 après affectation : ";
    for (int i = 0; i < v3.taille(); i++)
        cout << v3[i] << " ";
    cout << endl;

    return 0;
}
