#include<iostream>
#include<vector>
#include <string>

using namespace std;



/* 1.Classe de base : Ressource
-Attributs communs :id , titre , auteur , annee
-Méthode : afficherInfos() , telecharger() */
class Ressource {
protected:
    int id;             // identifiant unique
    string titre;  // titre de la ressource
    string auteur; // auteur ou éditeur
    int annee;          // année de publication

public:
    // Constructeur
    Ressource(int i,const string &t,const string &a,int an)
        : id(i), titre(t), auteur(a), annee(an) {}

    // Méthode virtuelle pour affichage : permet redéfinir dans les classes dérivées
     virtual void afficherInfos() const {
      std ::  cout << "ID: " <<id << ", Titre: " << titre<< ", Auteur: " << auteur << ", Année: " << annee << endl;
    }

    // Méthode virtuelle pour téléchargement : 
     virtual void telecharger() const {
      std ::  cout << "Téléchargement générique de : " << titre << endl;
    }

    // Getters utiles (accès sûr aux attributs)
    int getId() const { return id; }
    string getTitre() const { return titre; }
    string getAuteur() const { return auteur; }
    int getAnnee() const { return annee; }
    //5.Surcharge de l'opérateur ==
     bool operator==(const Ressource &r) const {
        return id == r.id;
    }

    // Destructeur virtuel : important pour l'héritage polymorphe
    virtual ~Ressource() {}
};

/*3.Classe Telechargeable: Fournit une méthode telecharger()et afficherMessage() */
  class Telechargeable {
public:
    virtual void telecharger() const {
     std :: cout << "Téléchargement depuis la classe Telechargeable..." << endl;
    }

    void afficherMessage() const {
     std ::cout << "Cette ressource est téléchargeable." << endl;
    }

    virtual ~Telechargeable() {}
};
//2.Classe dérivées : Livre, Magazine, Vedio
class Livre : public Ressource, public Telechargeable {
    int nbPages;

public:
    Livre(int i, string t, string a, int an, int n)
        : Ressource(i, t, a, an), nbPages(n) {}

    void afficherInfos() const override {
      std ::  cout << "[Livre] ";
        Ressource::afficherInfos();
       std :: cout << "Nombre de pages : " << nbPages << endl;
    }

    void telecharger() const override {
      std :: cout << "Téléchargement du livre \"" << titre << "\" en format PDF..." << endl;
    }
};

class Magazine : public Ressource, public Telechargeable {
    int numero;

public:
    Magazine(int i, string t, string a, int an, int num)
        : Ressource(i, t, a, an), numero(num) {}

    void afficherInfos() const override {
      std ::  cout << "[Magazine] ";
        Ressource::afficherInfos();
       std :: cout << "Numéro : " << numero << endl;
    }

    void telecharger() const override {
      std ::  cout << "Téléchargement du magazine \"" << titre << "\" numéro " << numero << "..." << endl;
    }
};

class Video : public Ressource, public Telechargeable {
    int duree; // en minutes

public:
    Video(int i, string t, string a, int an, int d)
        : Ressource(i, t, a, an), duree(d) {}

    void afficherInfos() const override {
      std :: cout << "[Vidéo] ";
        Ressource::afficherInfos();
      std :: cout << "Durée : " << duree << " minutes" << endl;
    }

    void telecharger() const override {
     std :: cout << "Téléchargement de la vidéo \"" << titre << "\" en MP4..." << endl;
    }
};
//4. Classe Mediatheque
class Mediatheque {
    vector<Ressource*> ressources;

public:
    void ajouter(Ressource *r) {
        ressources.push_back(r);
    }

    void afficherToutes() const {
     std ::  cout << "\n=== Liste des ressources ===\n";
        for (auto r : ressources) {
            r->afficherInfos();
         std ::  cout << "----------------------\n";
        }
    }

    // Recherche par titre
    void rechercher(const string &titre) const {
     std ::  cout << "\n Recherche par titre : " << titre << endl;
        for (auto r : ressources)
            if (r->getTitre() == titre)
                r->afficherInfos();
    }

    // Recherche par année
    void rechercher(int annee) const {
      std ::  cout << "\n Recherche par année : " << annee << endl;
        for (auto r : ressources)
            if (r->getAnnee() == annee)
                r->afficherInfos();
    }

    // Recherche par auteur + année
    void rechercher(const string &auteur, int annee) const {
       std :: cout << "\n Recherche par auteur + année : " << auteur << ", " << annee << endl;
        for (auto r : ressources)
            if (r->getAuteur() == auteur && r->getAnnee() == annee)
                r->afficherInfos();
    }

    ~Mediatheque() {
        // Libération de la mémoire
        for (auto r : ressources)
            delete r;
    }
};
// 6.Fonction principale
int main() {
    // Création de ressources
    Livre *l1 = new Livre(1, "Le Pain Nu", "Mohammed Choukri", 1973, 200);
    Magazine *m1 = new Magazine(2, "TelQuel", "Rédaction", 2023, 45);
    Video *v1 = new Video(3, "Ali Zaoua", "Nabil Ayouch", 2000, 95.0);

    // Création de la médiathèque
    Mediatheque med;
    med.ajouter(l1);
    med.ajouter(m1);
    med.ajouter(v1);

    // Afficher toutes les ressources
    med.afficherToutes();

    // Tester les téléchargements (héritage multiple)
     std ::cout << "\n=== Test de téléchargement ===\n";
    l1->telecharger();        // Appelle la version Livre
    m1->telecharger(); // Appelle la version magazine
    v1->afficherMessage();    // Message général

    // Tester la recherche
    med.rechercher("Le Pain Nu");
    med.rechercher(1973);
    med.rechercher("Le Pain Nu", 1973);

    // Comparaison de ressources
    std :: cout << "\n=== Test de comparaison ===\n";
    if (*l1 == *m1)
      std ::cout << "Les deux ressources sont identiques.\n";
    else
     std ::  cout << "Les deux ressources sont différentes.\n";

    return 0;
}
