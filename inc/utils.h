/// @file utils.h

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define RESET "\033[0m"
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"

const double EPSILON = 1e-7;

void buffer_clean();

bool is_zero(double num);

bool is_equal(double num1, double num2);

char *read_file(size_t *size);

size_t file_size(FILE *file);

size_t str_count(char *poem);

#endif // UTILS_H

