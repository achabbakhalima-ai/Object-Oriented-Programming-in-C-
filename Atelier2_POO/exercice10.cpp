#include <iostream>
using namespace std;

// Définition de la classe Complexe
class Complexe {
private:
    float re; // partie réelle
    float im; // partie imaginaire

public:
    // Constructeur par défaut
    Complexe() {
        re = 0;
        im = 0;
    }

    // Constructeur avec paramètres
    Complexe(float r, float i) {
        re = r;
        im = i;
    }

    // Saisie d’un nombre complexe
    void saisir() {
        cout << "Entrer la partie reelle : ";
        cin >> re;
        cout << "Entrer la partie imaginaire : ";
        cin >> im;
    }

    // Affichage d’un nombre complexe
    void afficher() const {
        if (im >= 0)
            cout << re << " + " << im << "i";
        else
            cout << re << " - " << -im << "i";
    }

    // Addition
    Complexe addition(const Complexe &c) const {
        return Complexe(re + c.re, im + c.im);
    }

    // Soustraction
    Complexe soustraction(const Complexe &c) const {
        return Complexe(re - c.re, im - c.im);
    }

    // Multiplication
    Complexe multiplication(const Complexe &c) const {
        return Complexe(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    // Division
    Complexe division(const Complexe &c) const {
        float denom = c.re * c.re + c.im * c.im;
        if (denom == 0) {
            cout << "Erreur : division par zero !" << endl;
            return Complexe(0, 0);
        }
        float reel = (re * c.re + im * c.im) / denom;
        float imag = (im * c.re - re * c.im) / denom;
        return Complexe(reel, imag);
    }

    // Égalité
    bool egal(const Complexe &c) const {
        return (re == c.re && im == c.im);
    }
};

int main() {
    Complexe c1, c2, resultat;
    int choix;

    cout << "=== Programme de calcul sur les nombres complexes ===" << endl;
    cout << "Saisir le premier nombre complexe :" << endl;
    c1.saisir();
    cout << "Saisir le deuxieme nombre complexe :" << endl;
    c2.saisir();

    cout << "\n===== MENU =====" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Soustraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Test d'egalite" << endl;
    cout << "================" << endl;
    cout << "Choisissez une operation : ";
    cin >> choix;
    cout << endl;

    switch (choix) {
        case 1:
            resultat = c1.addition(c2);
            cout << "Resultat : ";
            resultat.afficher();
            break;
        case 2:
            resultat = c1.soustraction(c2);
            cout << "Resultat : ";
            resultat.afficher();
            break;
        case 3:
            resultat = c1.multiplication(c2);
            cout << "Resultat : ";
            resultat.afficher();
            break;
        case 4:
            resultat = c1.division(c2);
            cout << "Resultat : ";
            resultat.afficher();
            break;
        case 5:
            if (c1.egal(c2))
                cout << "Les deux nombres complexes sont egaux." << endl;
            else
                cout << "Les deux nombres complexes ne sont pas egaux." << endl;
            break;
        default:
            cout << "Choix invalide !" << endl;
    }

    cout << endl;
    return 0;
}
