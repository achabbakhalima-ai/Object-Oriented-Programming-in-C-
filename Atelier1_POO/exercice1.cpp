#include <iostream>


int main() {
    char c = '\x01';    // valeur 1
    short int p = 10;   // valeur 10


    // 1. p + 3
    // p est short int, 3 est int → p est promu automatiquement en int
    int res1 = p + 3;
    std::cout << "1) p + 3 = " << res1 << " (type int)" << std::endl;


    // 2. c + 1
    // c est char, 1 est int → c est promu automatiquement en int
    int res2 = c + 1;
    std::cout << "2) c + 1 = " << res2 << " (type int)" << std::endl;


    // 3. p + c
    // c est char, p est short int → les deux sont promus en int
    int res3 = p + c;
    std::cout << "3) p + c = " << res3 << " (type int)" << std::endl;


    // 4. 3 * p + 5 * c
    // p et c sont promus en int automatiquement
    int res4 = 3 * p + 5 * c;
    std::cout << "4) 3 * p + 5 * c = " << res4 
              << " (type int)" << std::endl;


    // 5. Exemple de conversion forcée avec static_cast
    // Convertir p en char avant addition avec c 
    int res5 = static_cast<char>(p) + c;
    std::cout << "5) static_cast<char>(p) + c = " << res5 
              << " (type int)" << std::endl;


    return 0;
}


