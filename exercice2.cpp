#include <iostream>

int main() {
    char c = '\x05';   // valeur 5
    int n = 5;         // valeur 5
    long p = 1000;     // valeur 1000
    float x = 1.25;    // valeur 1.25
    double z = 5.5;    // valeur 5.5

    // 1. n + c + p
    long res1 = n + c + p;  // c et n promus en long
    std::cout << "1) n + c + p = " << res1 << " (type long)" << std::endl;

    // 2. 2 * x + c
    float res2 = 2 * x + c; // c promu en float
    std::cout << "2) 2 * x + c = " << res2 << " (type float)" << std::endl;

    // 3. (char) n + c → version moderne avec static_cast
    int res3 = static_cast<char>(n) + c; // promotion implicite après conversion
    std::cout << "3) static_cast<char>(n) + c = " << res3 << " (type int)" << std::endl;

    // 4. (float) z + n / 2 → version moderne
    float res4 = static_cast<float>(z) + n / 2; // n/2 est int, converti en float
    std::cout << "4) static_cast<float>(z) + n / 2 = " << res4 << " (type float)" << std::endl;

    return 0;
}

