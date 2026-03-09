#include<iostream>
 using namespace std ;

 //Fonction qui vérifie si un nombre est multiple de 2
 int multipleDe2( int n){
    if (n%2 == 0)  // si le reste de la division par 2 est 0 
         return 1; // Oui,il est multiple de 2
    else
         return 0; // Non
}
// Fonction qui vérifie si un nombre ent un multiple de 3
 int multipleDe3(int n){
    if (n%3 == 0) // si le reste de la division par 3 est 0
        return 1; // oui
    else 
        return 0; // non
}
 int main(){
    int entier ;
    
    cout <<"Saisir un entier:"<< endl;
    cin>> entier;

    // Vérification multiple de 2
    if(multipleDe2(entier))
      cout<<"il est pair"<< endl;

     //Vérification multiple de 3
     if(multipleDe3(entier))
      cout<<"il est multiple de 3"<< endl;

      //Vérification multiple de 6(multiple de 2 et de 3 à la fois)
      if (multipleDe2(entier)&& multipleDe3(entier))
      cout <<"il est divisible par 6"<< endl;

      return 0;

 }
