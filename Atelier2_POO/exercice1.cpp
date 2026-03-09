#include<iostream>
using namespace std ;

void afficher_appel(){
    static int compteur=0;    //variaible statique qui garde sa valeur entre les appels
compteur++;
cout<<"Appel numéro "<< compteur << endl;
}
int main (){
    afficher_appel(); // 1er appel
    afficher_appel(); // 2e appel
    afficher_appel(); // 3e appel
    return 0;
}