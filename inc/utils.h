/// @file utils.h

#ifndef UTILS_H
#define UTILS_H

#include "../inc/main.h"

#define RESET "\033[0m"
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"

const double EPSILON = 1e-7;

void buffer_clean();

bool is_zero(double num);

bool is_equal(double num1, double num2);

#endif // UTILS_H

