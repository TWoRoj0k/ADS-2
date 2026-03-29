// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1.0;
    }
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

static double calcItemExp(double x, uint16_t n) {
    if (n == 0) {
        return 1.0;
    }
    static double prevTerm = 1.0;
    static double prevN = 0;
    
    if (n == prevN + 1) {
        prevTerm = prevTerm * x / n;
        prevN = n;
        return prevTerm;
    } else {
        prevN = 0;
        prevTerm = 1.0;
        return calcItemExp(x, n);
    }
}

double calcItem(double x, uint16_t n) {
    if (n == 0) return 1.0;
    
    double result = 1.0;
    for (uint16_t i = 1; i <= n; ++i) {
        result *= x / i;
    }
    return result;
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    double term = 1.0;  // term for n=0
    
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            term = 1.0;
        } else {
            term *= x / n; 
        }
        sum += term;
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    double term = x;  // term for n=0: x^1/1!
    int sign = 1;
    
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            term = x;
        } else {
            // Рекуррентное соотношение для sin
            term *= (-x * x) / ((2 * n) * (2 * n + 1));
        }
        sum += term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    double term = 1.0;  // term for n=0: x^0/0!
    
    for (uint16_t n = 0; n < count; ++n) {
        if (n == 0) {
            term = 1.0;
        } else {
            // Рекуррентное соотношение для cos
            term *= (-x * x) / ((2 * n - 1) * (2 * n));
        }
        sum += term;
    }
    return sum;
}
