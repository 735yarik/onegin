/// @file sort.h

#ifndef SORT_H
#define SORT_H

#include "../inc/input_output.h"

void sort(StrStruct *str_info, size_t str_num, int (*cmp)(const char *, const char *, size_t *, size_t *));

void swapper(StrStruct *str1, StrStruct *str2);

int direct_strcmp(const char *str1, const char *str2, size_t *str_len1, size_t *str_len2);

int reverse_strcmp(const char *str1, const char *str2, size_t *str_len1, size_t *str_len2);

#endif // SORT_H
