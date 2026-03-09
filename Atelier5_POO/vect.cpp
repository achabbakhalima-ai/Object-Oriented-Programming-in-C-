#include "vect.h"
#include <iostream>
using namespace std;

// Constructeur
vect::vect(int n) : nelem(n) {
    adr = new int[nelem];
    for(int i = 0; i < nelem; i++) {
        adr[i] = 0;  // initialisation à 0
    }
}

// Destructeur
vect::~vect() {
    delete[] adr;
}

// Opérateur []
int& vect::operator[](int i) {
    return adr[i];
}