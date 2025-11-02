#include <iostream>
#include <string>
using namespace std;

// ===================== Classe Client =====================
class Client {
private:
    int id;
    string nom;
    string prenom;

public:
    // Constructeur vide
    Client() : id(0), nom(""), prenom("") {}

    // Constructeur avec paramètres
    Client(int i, const string& n, const string& p) : id(i), nom(n), prenom(p) {}

    // Constructeur par copie
    Client(const Client& c) : id(c.id), nom(c.nom), prenom(c.prenom) {}

    // Destructeur
    ~Client() {
        // Pas de mémoire dynamique ici, donc rien à libérer
        // Réponse question: le destructeur n'est pas strictement nécessaire ici.
    }

    // Méthode pour afficher le client
    void afficher() const {
        cout << "Client ID: " << id << ", Nom: " << nom << ", Prénom: " << prenom << endl;
    }
};

// ===================== Classe Compte =====================
class Compte {
private:
    int numero;
    float solde;
    Client* client;               // pointeur vers un Client
    static int nbComptes;         // compteur statique partagé

public:
    // Constructeur vide
    Compte() : numero(0), solde(0), client(nullptr) {
        nbComptes++;              // Incrément du compteur
    }

    // Constructeur avec paramètres
    Compte(int num, float s, Client* c) : numero(num), solde(s) {
        client = new Client(*c);  // Copie profonde pour éviter les problèmes de mémoire
        nbComptes++;
    }

    // Constructeur par copie
    Compte(const Compte& c) : numero(c.numero), solde(c.solde) {
        client = new Client(*c.client); // Copie profonde
        nbComptes++;
    }

    // Destructeur
    ~Compte() {
        delete client;            // Libération de la mémoire
        nbComptes--;              // Décrément du compteur
        // Réponse question: si on oublie de libérer la mémoire, il y aura une fuite mémoire.
    }

    // Méthode pour afficher le compte
    void afficher() const {
        cout << "Compte Numero: " << numero << ", Solde: " << solde << endl;
        if (client)
            client->afficher();
    }

    // Méthode statique pour afficher le nombre total de comptes
    static void afficherNbComptes() {
        cout << "Nombre total de comptes: " << nbComptes << endl;
        // Réponse question: le compteur doit être statique pour être partagé entre tous les comptes
    }
};

// Initialisation du compteur statique
int Compte::nbComptes = 0;

// ===================== Fonction utilitaire =====================
inline float calculInteret(float solde, float taux) {
    // Réponse question: inline ici car fonction très courte, pour éviter le coût d'appel
    return solde * (1 + taux);
}

// ===================== Programme principal =====================
int main() {
    cout << "=== Création des clients ===" << endl;
    Client c1(1, "Alami", "Ahmed");
    Client c2(2, "Bnoun", "Fatima");

    cout << "\n=== Création des comptes ===" << endl;
    Compte compte1(1001, 5000, &c1);
    Compte compte2(1002, 3000, &c2);

    cout << "\n=== Affichage des comptes ===" << endl;
    compte1.afficher();
    compte2.afficher();
    Compte::afficherNbComptes();

    cout << "\n=== Copie d'un compte ===" << endl;
    Compte compte3 = compte1;  // Test du constructeur de copie
    compte3.afficher();
    Compte::afficherNbComptes();

    cout << "\n=== Application d'intérêts ===" << endl;
    float nouveauSolde = calculInteret(5000, 0.05); // taux de 5%
    cout << "Solde après intérêt: " << nouveauSolde << endl;

    cout << "\n=== Fin du programme, destruction automatique des comptes ===" << endl;
    // Les destructeurs sont appelés automatiquement ici
    // Réponse question: si les destructeurs n'étaient pas correctement définis, on aurait des fuites mémoire

    return 0;
}

/*
------------------------- Questions de réflexion -------------------------
1. Copie superficielle vs copie profonde:
   - Superficielle: copie seulement le pointeur, pas l'objet pointé → peut causer double libération.
   - Profonde: copie l'objet pointé lui-même → nécessaire ici pour Client dans Compte.

2. Pourquoi le compteur doit être statique?
   - Il est partagé par tous les comptes, sinon chaque objet aurait son propre compteur.

3. Différence méthode statique vs normale:
   - Statique: pas besoin d'instance, peut seulement accéder aux membres statiques.
   - Normale: nécessite une instance, peut accéder à tous les membres.

4. Quand rendre une fonction inline?
   - Pour les fonctions très courtes et appelées souvent, pour réduire le coût d'appel.

5. Si on oublie de libérer la mémoire dans le destructeur:
   - On provoque des fuites mémoire, ce qui peut ralentir ou planter le programme.
*/
