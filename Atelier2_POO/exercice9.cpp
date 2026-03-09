#include <iostream>
#include <cmath>  // pour sqrt()
using namespace std;

class Vecteur3D {
private:
    float x, y, z; // composantes du vecteur

public:
    // ----------------------------
    // Constructeur avec valeurs par défaut
    // ----------------------------
    Vecteur3D(float x_ = 0, float y_ = 0, float z_ = 0)
        : x(x_), y(y_), z(z_) {}

    // ----------------------------
    // Méthode d'affichage
    // ----------------------------
    void afficher() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    // ----------------------------
    // Somme de deux vecteurs (retour par valeur)
    // ----------------------------
    Vecteur3D somme_valeur(const Vecteur3D& v) const {
        return Vecteur3D(x + v.x, y + v.y, z + v.z);
    }

    // ----------------------------
    // Somme de deux vecteurs (retour par adresse)
    // ----------------------------
    static Vecteur3D* somme_adresse(const Vecteur3D* v1, const Vecteur3D* v2) {
        // résultat créé dynamiquement (à supprimer avec delete après usage)
        return new Vecteur3D(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
    }

    // ----------------------------
    // Somme de deux vecteurs (retour par référence)
    // ----------------------------
    static Vecteur3D& somme_reference(const Vecteur3D& v1, const Vecteur3D& v2) {
        // résultat statique 
        static Vecteur3D res;
        res = Vecteur3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
        return res;
    }

    // ----------------------------
    // Produit scalaire de deux vecteurs
    // ----------------------------
    float produitScalaire(const Vecteur3D& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    // ----------------------------
    // Fonction coincide : teste si deux vecteurs sont égaux
    // ----------------------------
    bool coincide(const Vecteur3D& v) const {
        return (x == v.x && y == v.y && z == v.z);
    }

    // ----------------------------
    // Calcul de la norme du vecteur
    // ----------------------------
    float norme() const {
        return sqrt(x * x + y * y + z * z);
    }

    // ----------------------------
    // Fonction normax : retourne le vecteur de plus grande norme
    // (retour par valeur ici)
    // ----------------------------
    static Vecteur3D normax_valeur(const Vecteur3D& v1, const Vecteur3D& v2) {
        if (v1.norme() >= v2.norme())
            return v1;
        else
            return v2;
    }

    // ----------------------------
    // Même chose, mais retour par adresse
    // ----------------------------
    static Vecteur3D* normax_adresse(const Vecteur3D* v1, const Vecteur3D* v2) {
        if (v1->norme() >= v2->norme())
            return (Vecteur3D*)v1;
        else
            return (Vecteur3D*)v2;
    }

    // ----------------------------
    // Même chose, mais retour par référence
    // ----------------------------
    static Vecteur3D& normax_reference(Vecteur3D& v1, Vecteur3D& v2) {
        if (v1.norme() >= v2.norme())
            return v1;
        else
            return v2;
    }
};

// --------------------------------------------------
// Programme principal pour tester la classe
// --------------------------------------------------
int main() {
    Vecteur3D v1(1, 2, 3);
    Vecteur3D v2(4, 5, 6);

    cout << "v1 = "; v1.afficher(); cout << endl;
    cout << "v2 = "; v2.afficher(); cout << endl;

    // --- Test somme par valeur ---
    cout << "\nSomme (par valeur) : ";
    Vecteur3D v3 = v1.somme_valeur(v2);
    v3.afficher();

    // --- Test somme par adresse ---
    cout << "\nSomme (par adresse) : ";
    Vecteur3D* v4 = Vecteur3D::somme_adresse(&v1, &v2);
    v4->afficher();
    delete v4; // libération mémoire

    // --- Test somme par référence ---
    cout << "\nSomme (par reference) : ";
    Vecteur3D& v5 = Vecteur3D::somme_reference(v1, v2);
    v5.afficher();

    // --- Produit scalaire ---
    cout << "\n\nProduit scalaire v1 · v2 = " << v1.produitScalaire(v2);

    // --- Normes ---
    cout << "\nNorme de v1 = " << v1.norme();
    cout << "\nNorme de v2 = " << v2.norme();

    // --- Test coincide ---
    cout << "\n\nv1 et v2 coincident ? " << (v1.coincide(v2) ? "Oui" : "Non");

    // --- Test normax ---
    cout << "\n\nVecteur avec la plus grande norme (par valeur) : ";
    Vecteur3D v6 = Vecteur3D::normax_valeur(v1, v2);
    v6.afficher();

    cout << "\nVecteur avec la plus grande norme (par adresse) : ";
    Vecteur3D* v7 = Vecteur3D::normax_adresse(&v1, &v2);
    v7->afficher();

    cout << "\nVecteur avec la plus grande norme (par reference) : ";
    Vecteur3D& v8 = Vecteur3D::normax_reference(v1, v2);
    v8.afficher();

    cout << endl;
    return 0;
}