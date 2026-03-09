#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Déclaration préalable de la classe AgentBancaire pour pouvoir l'utiliser comme ami
class AgentBancaire;

// Classe représentant un client
class Client {
private:
    string nom;
    string CIN;
    int idClient;

public:
    Client(string n, string c, int id) : nom(n), CIN(c), idClient(id) {}

    // Méthode pour afficher les informations publiques du client
    void afficherInfo() {
        cout << "Client ID: " << idClient << ", Nom: " << nom << ", CIN: " << CIN << endl;
    }

    // Déclaration de la classe AgentBancaire comme amie pour accès aux infos privées
    friend class AgentBancaire;
    friend class Banque;
};

// Classe représentant un compte bancaire
class CompteBancaire {
private:
    int numeroCompte;
    double solde;
    string codeSecret;
    Client* proprietaire;  // Référence vers le client

public:
    CompteBancaire(int num, double s, string code, Client* c)
        : numeroCompte(num), solde(s), codeSecret(code), proprietaire(c) {}

    // Méthodes pour effectuer des opérations de base
    void depot(double montant) {
        solde += montant;
        cout << "Depot de " << montant << " effectué. Nouveau solde: " << solde << endl;
    }

    bool retrait(double montant) {
        if (montant <= solde) {
            solde -= montant;
            cout << "Retrait de " << montant << " effectué. Nouveau solde: " << solde << endl;
            return true;
        } else {
            cout << "Solde insuffisant!" << endl;
            return false;
        }
    }

    // Déclaration de la classe AgentBancaire comme amie pour accès aux infos privées
    friend class AgentBancaire;

    // Déclaration de la classe Banque comme amie pour rapport d'audit
    friend class Banque;
};

// Classe représentant un agent bancaire autorisé
class AgentBancaire {
private:
    string nomAgent;
public:
    AgentBancaire(string nom) : nomAgent(nom) {}

    // Méthode pour afficher le code secret d'un compte
    void afficherCodeSecret(CompteBancaire& compte) {
        cout << "Code secret du compte " << compte.numeroCompte << ": " << compte.codeSecret << endl;
    }

    // Transfert entre comptes
    void transfert(CompteBancaire& src, CompteBancaire& dest, double montant) {
        if (src.retrait(montant)) {
            dest.depot(montant);
            cout << "Transfert de " << montant << " du compte " 
                 << src.numeroCompte << " au compte " << dest.numeroCompte << " effectué." << endl;
        }
    }
};

// Classe Banque pour centraliser la gestion
class Banque {
private:
    vector<Client> clients;
    vector<CompteBancaire> comptes;

public:
    void ajouterClient(Client c) {
        clients.push_back(c);
    }

    void ajouterCompte(CompteBancaire c) {
        comptes.push_back(c);
    }
    // Méthode d'audit pour afficher tous les comptes et informations sensibles
    void audit() {
        cout << "\n--- Rapport d'audit bancaire ---\n";
        for (auto& compte : comptes) {
            cout << "Compte: " << compte.numeroCompte 
                 << ", Solde: " << compte.solde 
                 << ", Code secret: " << compte.codeSecret
                 << ", Proprietaire: " << compte.proprietaire->nom << endl;
        }
        cout << "-------------------------------\n";
    }
};

int main() {
    // Création de clients
    Client client1("Ahmed", "LG123456", 1);
    Client client2("Fatima", "L654321", 2);

    // Création de comptes
    CompteBancaire compte1(101, 1000.0, "abc321", &client1);
    CompteBancaire compte2(102, 500.0, "def654", &client2);

    // Création d'une banque et ajout des clients et comptes
    Banque banque;
    banque.ajouterClient(client1);
    banque.ajouterClient(client2);
    banque.ajouterCompte(compte1);
    banque.ajouterCompte(compte2);

    // Création d'un agent
    AgentBancaire agent("Said");

    // Simuler des opérations
    compte1.depot(200);
    compte2.retrait(100);
    agent.transfert(compte1, compte2, 300);
    agent.afficherCodeSecret(compte1);

    // Affichage du rapport d'audit
    banque.audit();

    return 0;
}