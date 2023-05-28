#include <stdlib.h>
#include "calculations.h"

//// Работа с простыми числами.

long long int coprime(long long int p){
    // Нахождение взаимно простого числа числу P-1
    // {GCD(X, P-1) = 1}

    p -= 1;

    long long int b = 2 + rand()%p; // NOLINT(cert-msc30-c, cert-msc50-cpp)

    while (gcd(p, b) != 1)
        b = 2 + rand(); // NOLINT(cert-msc30-c, cert-msc50-cpp)

    return b;
}
