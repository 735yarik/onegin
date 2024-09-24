/// @file sort.h

#ifndef SORT_H
#define SORT_H

#include "../inc/input_output.h"

void sort(char **addr, size_t str_num, size_t *str_len, int (*cmp)(const char *, const char *));
void swapper(char **addr1, char **addr2);
void str_len_swapper(size_t *len1, size_t *len2);
int reverse_strcmp(const char *str1, const char *str2);

#endif // SORT_H
