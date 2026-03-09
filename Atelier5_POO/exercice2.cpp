#include <iostream>
#include <stdexcept> 
using namespace std;

class Test{
public:
       static int tableau[] ;
public :
    static int division(int indice , int diviseur){
        if(indice <0 || indice >= 10)
          throw runtime_error("indice Inaccessible ");
        if(diviseur == 0)
          throw runtime_error("Division par zero! ");

        return tableau[indice]/diviseur;
   }
};
int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5} ;

int main() {
   int x, y;
   bool testValide = false;


   while(!testValide){
      try{
   cout << "Entrez l'indice de l'entier a diviser: " << endl;
     cin>>x ;
   cout << "Entrez le diviseur: " << endl;
     cin>>y ;
   cout << "Le resultat de la division est : "
                 << Test::division(x, y) << endl;
         testValide = true;
      }catch(const exception& e){
        cout<<"ERREUR: "<< e.what()<< endl; 
        cout << "Veillez ressayer:" << endl;
         
      }
    }
    cout << "Programme termine avec succes!" << endl;
   return 0;
}