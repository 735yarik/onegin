/// @file sort.h

#ifndef SORT_H
#define SORT_H

#include "../inc/main.h"

void sort(char **addr, size_t str_num, size_t *str_len);
void swapper(char **addr1, char **addr2);
void str_len_swapper(size_t *len1, size_t *len2);
int reverse_strcmp(char *str1, char *str2, size_t *str_len1, size_t *str_len2);

#endif // SORT_H
