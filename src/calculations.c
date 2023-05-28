//// Вычислительные функции

long long int mod(long long int a, long long int b){
    // Деление по модулю.
    // Эта формула выводится из определения.

    return a - ((a / b) * b);
}

long long int gcd(long long int a, long long int b){
    // Алгоритм Евклида для нахождения НОД.

    if (a < b){
        a = a + b;
        b = a - b;
        a = a - b;
    }

    while (b != 0){
        long long int buff = b;
        b = mod(a, b);
        a = buff;
    }
    return a;
}

long long int invert_mod(long long int p, long long int c){
    // Инверсия числа C по модулю P - 1.
    // Реализован на основе расширенного алгоритма Евклида.

    p -= 1;

    if (c > p)
        c = mod(c, p);

    long long int u[] = {p, 0};
    long long int v[] = {c, 1};
    long long int t[] = {0, 0};

    while (v[0] != 1){
        t[0] = mod(u[0], v[0]);
        t[1] = u[1] - ((u[0] / v[0]) * v[1]);

        u[0] = v[0];
        u[1] = v[1];

        v[0] = t[0];
        v[1] = t[1];
    }

    if (v[1] < 0)
        v[1] = p + v[1];

    return v[1];
}

