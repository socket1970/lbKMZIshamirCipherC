#include "gmp.h" // GNU Multi-Precision Library

//// Непосредственно работа с шифром.

void ull2mpz(mpz_t z, unsigned long long ull)
{
    mpz_import(z, 1, -1, sizeof ull, 0, 0, &ull);
    //// Большое спасибо -
    ////        https://stackoverflow.com/questions/6248723/mpz-\t-to-unsigned-long-long-conversion-gmp-lib
}
long long int test(long long int Ca,
                   long long int Da,
                   long long int Cb,
                   long long int Db,
                   long long int p,
                   long long int m){

    // Производит шифрование и дешифрование. Возвращает x4, которое равно исходному сообщению m.

    // Объявление переменных типа mpz_t(из библиотеки gmp).
    mpz_t Ca_, Da_, Cb_, Db_, p_, m_;
    mpz_t x1, x2, x3, x4;

    // Инициализация переменных
    mpz_init(Ca_);
    mpz_init(Da_);
    mpz_init(Cb_);
    mpz_init(Db_);

    mpz_init(p_);
    mpz_init(m_);

    mpz_init(x1);
    mpz_init(x2);
    mpz_init(x3);
    mpz_init(x4);

    // Приводит тип (unsigned) long long int к типу mpz_t.
    ull2mpz(Ca_, Ca);
    ull2mpz(Da_, Da);
    ull2mpz(Cb_, Cb);
    ull2mpz(Db_, Db);
    ull2mpz(p_, p);
    ull2mpz(m_, m);

    // Вычисления всех x.
    mpz_powm(x1, m_, Ca_, p_); // x1 = (m^Ca) mod p
    mpz_powm(x2, x1, Cb_, p_); // x2 = (x1^Cb) mod p
    mpz_powm(x3, x2, Da_, p_); // x3 = (x2^Da) mod p
    mpz_powm(x4, x3, Db_, p_); // x4 = (x3^Db) mod p


    // Вывод на экран переписки.
    gmp_printf("\033[36m \tЗначения: \033[39m \n"
                   "\033[95m \t\tx1 - \033[39m %Zd\n"
                   "\033[95m \t\tx2 - \033[39m %Zd\n"
                   "\033[95m \t\tx3 - \033[39m %Zd\n"
                   "\033[95m \t\tx4 - \033[39m %Zd\n"

               "\033[36m \tПараметры: \033[39m \n"
                   "\033[95m \t\tCa - \033[39m %Zd\n"
                   "\033[95m \t\tCb - \033[39m %Zd\n"
                   "\033[95m \t\tDa - \033[39m %Zd\n"
                   "\033[95m \t\tDb - \033[39m %Zd\n\n"

                   "\033[95m \t\tp - \033[39m %Zd\n"
                   "\033[95m \t\tm - \033[39m %Zd\n",

               x1, x2, x3, x4,
               Ca_, Cb_, Da_, Db_,
               p_, m_);


    return mpz_get_si(x4);
}

void test2(long long int x1,
           long long int p,
           long long int Cb,
           long long int Db){
    // Производит обмен сообщениями между Алисой и Бобом, где Бобом выступает этот клиент(мы).

    // Объявление переменных типа mpz_t(из библиотеки gmp).
    mpz_t x1_, x2_, x3_, x4_;
    mpz_t Cb_, Db_, p_;

    // Инициализация переменных
    mpz_init(x1_);
    mpz_init(x2_);
    mpz_init(x3_);
    mpz_init(x4_);

    mpz_init(Cb_);
    mpz_init(Db_);

    mpz_init(p_);

    // Приводит тип (unsigned) long long int к типу mpz_t.
    ull2mpz(x1_, x1);
    ull2mpz(Cb_, Cb);
    ull2mpz(Db_, Db);
    ull2mpz(p_, p);

    /*************************/
    // Вывод на экран переписки.
    gmp_printf("\033[36m \tКлючи: \033[39m \n"
               "\033[95m \t\tCb =\033[39m %Zd\n"
               "\033[95m \t\tDb =\033[39m %Zd\n"

               "\033[36m \tЗначения: \033[39m \n"
               "\033[95m \t\tx1 =\033[39m %Zd\n",
               Cb_, Db_, x1_);

    mpz_powm(x2_, x1_, Cb_, p_); // x2 = (x1^Cb) mod p

    gmp_printf("\033[95m \t\tx2 =\033[39m %Zd\n\t"
               "\033[36mВведите \033[95mx3 =\033[39m ", x2_);
    gmp_scanf("%Zd", x3_); // Ввод с клавиатуры x3.

    mpz_powm(x4_, x3_, Db_, p_); // x4 = (x3^Db) mod p

    gmp_printf("\033[95m \t\tx4 =\033[39m %Zd\n", x4_);
}


