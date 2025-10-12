#include <iostream>
using namespace std;

int main() {
    int i, j, n;

    // A. Post-incrément
    i = 0;
    n = i++;  // post-incrément : n prend la valeur de i avant l'incrément
              // i est ensuite augmenté de 1
    cout << "A) i = " << i << ", n = " << n << endl;
    // Affiche : i = 1, n = 0

    // B. Pré-incrément
    i = 10;
    n = ++i;  // pré-incrément : i est incrémenté avant affectation à n
    cout << "B) i = " << i << ", n = " << n << endl;
    // Affiche : i = 11, n = 11

    // C. Post et pré-incrément avec multiplication
    i = 20;
    j = 5;
    n = i++ * ++j;  
    // ++j → j = 6 ; i++ = 20 utilisé pour la multiplication, puis i devient 21
    // n = 20 * 6 = 120
    cout << "C) i = " << i << ", j = " << j << ", n = " << n << endl;
    // Affiche : i = 21, j = 6, n = 120

    // D. Opérateur d'affectation +=
    i = 15;
    n = i += 3;  // i = i + 3 = 18 ; n = 18
    cout << "D) i = " << i << ", n = " << n << endl;
    // Affiche : i = 18, n = 18

    // E. Opérateur d'affectation *= avec pré-décrément
    i = 3;
    j = 5;
    n = i *= --j;  
    // --j → j = 4 ; i = i * j = 3 * 4 = 12 ; n = 12
    cout << "E) i = " << i << ", j = " << j << ", n = " << n << endl;
    // Affiche : i = 12, j = 4, n = 12

    return 0;
}

