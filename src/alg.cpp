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

static uint16_t currentType = 0;

double calcItem(double x, uint16_t n) {
    switch (currentType) {
        case 0: {  // exp
            return pown(x, n) / static_cast<double>(fact(n));
        }
        case 1: {  // sin
            uint16_t exponent = 2 * n + 1;
            double numerator = pown(x, exponent);
            uint64_t denominator = fact(exponent);
            if (n % 2 != 0) {
                numerator = -numerator;
            }
            return numerator / static_cast<double>(denominator);
        }
        case 2: {  // cos
            uint16_t exponent = 2 * n;
            double numerator = pown(x, exponent);
            uint64_t denominator = fact(exponent);
            if (n % 2 != 0) {
                numerator = -numerator;
            }
            return numerator / static_cast<double>(denominator);
        }
        default: {
            return 0.0;
        }
    }
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    currentType = 0;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    double term = x;  // Первый член (n=0): x
    sum = term;
    
    for (uint16_t n = 1; n < count; ++n) {
        // Рекуррентное соотношение для sin
        // term(n) = term(n-1) * (-x*x) / ((2*n-1) * (2*n))
        term *= (-x * x) / ((2 * n - 1) * (2 * n));
        sum += term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    double term = 1.0;  // Первый член (n=0): 1
    sum = term;
    
    for (uint16_t n = 1; n < count; ++n) {
        // Рекуррентное соотношение для cos
        // term(n) = term(n-1) * (-x*x) / ((2*n-2) * (2*n-1))
        term *= (-x * x) / ((2 * n - 2) * (2 * n - 1));
        sum += term;
    }
    return sum;
}
