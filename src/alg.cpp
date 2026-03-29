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

// Глобальная переменная для определения контекста вызова
static uint16_t g_type = 0;  // 0 - exp, 1 - sin, 2 - cos

double calcItem(double x, uint16_t n) {
    switch (g_type) {
        case 0:  // exp
            return pown(x, n) / static_cast<double>(fact(n));
        case 1: {  // sin
            uint16_t exponent = 2 * n + 1;
            double numerator = pown(x, exponent);
            uint64_t denominator = fact(exponent);
            double result = numerator / static_cast<double>(denominator);
            if (n % 2 != 0) {
                result = -result;
            }
            return result;
        }
        case 2: {  // cos
            uint16_t exponent = 2 * n;
            double numerator = pown(x, exponent);
            uint64_t denominator = fact(exponent);
            double result = numerator / static_cast<double>(denominator);
            if (n % 2 != 0) {
                result = -result;
            }
            return result;
        }
        default:
            return 0.0;
    }
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    g_type = 0;
    for (uint16_t n = 0; n <= count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    g_type = 1;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    g_type = 2;
    for (uint16_t n = 0; n < count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}
