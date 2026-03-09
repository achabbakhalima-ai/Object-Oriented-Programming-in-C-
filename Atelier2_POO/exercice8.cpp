#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Voiture {
private:
    string marque;     // marque de la voiture (ex: "Toyota")
    string modele;     // modèle de la voiture (ex: "Corolla")
    int annee;         // année de fabrication
    float kilometrage; // kilométrage actuel (en kilomètres)
    float vitesse;     // vitesse actuelle (en km/h)

public:
    // -------------------------
    // Constructeur par défaut
    // -------------------------
    Voiture()
        : marque("Inconnue"), modele("Inconnu"), annee(0),
          kilometrage(0.0f), vitesse(0.0f) {
       
    }

    // -------------------------
    // Constructeur avec paramètres
    // -------------------------
    Voiture(const string& m, const string& mod, int an, float km, float vit)
        : marque(m), modele(mod), annee(an),
          kilometrage(km), vitesse(vit) {
        // Si vitesse ou kilometrage fournis négatifs, on les corrige ici (optionnel)
        if (kilometrage < 0.0f) kilometrage = 0.0f;
        if (vitesse < 0.0f) vitesse = 0.0f;
    }

    // -------------------------
    // Méthode : accelerer
    // Incrémente la vitesse actuelle de la valeur passée.
    // -------------------------
    void accelerer(float valeur) {
        // On ignore les accélérations négatives ici (on pourrait appeler freiner)
        if (valeur <= 0.0f) return;
        vitesse += valeur;
    }

    // -------------------------
    // Méthode : freiner
    // Diminue la vitesse, sans devenir négative.
    // -------------------------
    void freiner(float valeur) {
        if (valeur <= 0.0f) return;
        vitesse -= valeur;
        if (vitesse < 0.0f) vitesse = 0.0f; // la vitesse ne peut pas être négative
    }

    // -------------------------
    // Méthode : avancer
    // Incrémente le kilométrage selon la distance parcourue.
    // -------------------------
    void avancer(float distance) {
        if (distance <= 0.0f) return; // on n'accepte pas de distance négative ou nulle
        kilometrage += distance;
    }

    // -------------------------
    // Méthode : afficherInfo
    // Affiche les caractéristiques courantes de la voiture.
    // -------------------------
    void afficherInfo() const {
        cout << fixed << setprecision(2);
        cout << "Marque      : " << marque << '\n';
        cout << "Modele      : " << modele << '\n';
        cout << "Annee       : " << annee << '\n';
        cout << "Kilometrage : " << kilometrage << " km\n";
        cout << "Vitesse     : " << vitesse << " km/h\n";
    }

    // -------------------------
    // Destructeur
    // Affiche un message indiquant que la voiture est détruite.
    // -------------------------
    ~Voiture() {
        cout << "Destruction de la voiture " << marque << " " << modele << " (" << annee << ").\n";
    }
};

// -------------------------
// Programme de test (main)
// -------------------------
int main() {
    cout << "=== Test du constructeur par defaut ===\n";
    Voiture v1;                  // constructeur par défaut
    v1.afficherInfo();
    cout << '\n';

    cout << "=== Test du constructeur avec parametres ===\n";
    Voiture v2("Peugeot", "208", 2019, 45230.5f, 0.0f);
    v2.afficherInfo();
    cout << '\n';

    cout << "=== Test accelerer / freiner / avancer ===\n";
    cout << "- On accelere de 50 km/h\n";
    v2.accelerer(50.0f);
    v2.afficherInfo();
    cout << '\n';

    cout << "- On avance de 120.5 km\n";
    v2.avancer(120.5f);
    v2.afficherInfo();
    cout << '\n';

    cout << "- On freine de 30 km/h\n";
    v2.freiner(30.0f);
    v2.afficherInfo();
    cout << '\n';

    cout << "- On freine brutalement de 100 km/h (doit passer a 0 et non negatif)\n";
    v2.freiner(100.0f);
    v2.afficherInfo();
    cout << '\n';

    cout << "Fin du main : les destructeurs vont s'executer automatiquement.\n";

    return 0;
}