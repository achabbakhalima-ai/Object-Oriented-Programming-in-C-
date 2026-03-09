#include <iostream>
using namespace std;

int main() {
    // 1️.Déclaration d'un entier
    int a = 10; // variable normale contenant la valeur 10

    // 2️.Déclaration d'une référence vers cet entier
    // Une référence est un "autre nom" pour la même variable
    int& ref_a = a;

    // 3️. Déclaration d’un pointeur vers cet entier
    // Un pointeur contient l’ADRESSE de la variable
    int* p_a = &a;

    // 4️. Affichons les valeurs et adresses
   

    cout << "Valeur de a           : " << a << endl;
    cout << "Adresse de a (&a)     : " << &a << endl << endl;

    cout << "Valeur de ref_a       : " << ref_a << endl;
    cout << "Adresse de ref_a (&ref_a) : " << &ref_a << endl << endl;

    cout << "Valeur du pointeur p_a (adresse qu'il contient) : " << p_a << endl;
    cout << "Adresse du pointeur p_a (&p_a) : " << &p_a << endl;
    cout << "Valeur pointée (*p_a) :: " << *p_a << endl;

    return 0;
}
