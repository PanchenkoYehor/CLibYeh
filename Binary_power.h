//
// Created by panen on 08.07.2020.
//

#ifndef ALGO_BINARY_POWER_H
#define ALGO_BINARY_POWER_H

//Here is a two functions which calculated Base^Exp and (Base^Exp) % MOD
//It`s necessary to specify ONE = BASE^0, BASE = BASE^1 and EXP = Exponent
//The operation '*' must be associative to correctness for using Pow and PowMod, otherwise use naive multiplication

template<typename T, typename Te>
T Pow(T ONE, T BASE, Te EXP) {
    T RESULT = ONE;
    while (EXP) {
        if (EXP % 2 == 1) {
            RESULT = RESULT * BASE;
        }
        BASE = BASE * BASE;
        EXP = EXP / 2;
    }
    return RESULT;
}

template<typename T, typename Te, typename Tm>
T PowMod(T ONE, T BASE, Te EXP, Tm MOD) {
    T RESULT = ONE % MOD;
    while (EXP) {
        if (EXP % 2 == 1) {
            RESULT = RESULT * BASE % MOD;
        }
        BASE = BASE * BASE % MOD;
        EXP = EXP / 2;
    }
    return RESULT;
}

template<typename T, typename Te>
T PowNaive(T ONE, T BASE, Te EXP) {
    T RESULT = ONE;
    for (Te i = 0; i < EXP; i++)
        RESULT = RESULT * BASE;
    return RESULT;
}

template<typename T, typename Te, typename Tm>
T PowModNaive(T ONE, T BASE, Te EXP, Tm MOD) {
    T RESULT = ONE % MOD;
    for (Te i = 0; i < EXP; i++)
        RESULT = RESULT * BASE % MOD;
    return RESULT;
}

#endif //ALGO_BINARY_POWER_H