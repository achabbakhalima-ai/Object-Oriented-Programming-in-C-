#include <iostream>

int main() {
    int n = 5, p = 9;
    int q;
    float x;

    // 1. q = n < p
    q = n < p;  // true = 1
    std::cout << "1) q = n < p -> q = " << q << std::endl;

    // 2. q = n == p
    q = n == p; // false = 0
    std::cout << "2) q = n == p -> q = " << q << std::endl;

    // 3. q = p % n + p > n
    q = p % n + p > n; // priorité : %, +, >
    std::cout << "3) q = p % n + p > n -> q = " << q << std::endl;

    // 4. x = p / n
    x = p / n; // division entière puis conversion en float
    std::cout << "4) x = p / n -> x = " << x << std::endl;

    // 5. x = (float) p / n
    x = static_cast<float>(p) / n; // division flottante
    std::cout << "5) x = static_cast<float>(p) / n -> x = " << x << std::endl;

    // 6. x = (p + 0.5) / n
    x = (p + 0.5f) / n; // division flottante
    std::cout << "6) x = (p + 0.5) / n -> x = " << x << std::endl;

    // 7. x = (int) (p + 0.5) / n
    x = static_cast<int>(p + 0.5f) / n; // conversion en int, division entière, puis promotion en float
    std::cout << "7) x = static_cast<int>(p + 0.5) / n -> x = " << x << std::endl;

    // 8. q = n * (p > n ? n : p)
    q = n * (p > n ? n : p); // ternaire, p > n vrai → valeur = n
    std::cout << "8) q = n * (p > n ? n : p) -> q = " << q << std::endl;

    // 9. q = n * (p < n ? n : p)
    q = n * (p < n ? n : p); // ternaire, p < n faux → valeur = p
    std::cout << "9) q = n * (p < n ? n : p) -> q = " << q << std::endl;

    return 0;
}