/// @file sort.cpp

#ifndef SORT_CPP
#define SORT_CPP

#include "../inc/sort.h"

void sort(char **addr, size_t str_num, size_t *str_len, int (*cmp)(const char *, const char *))
{

    assert(str_len != NULL);
    assert(addr != NULL);
    assert(isfinite(str_num));

    for (int i = 0; i < str_num - 1; i++)
    {
        for (int j = i + 1; j < str_num; j++)
        {
            if (cmp(addr[i], addr[j]) > 0)
            {
                swapper(addr+j, addr+i);
            }
        }
    }

}

void swapper(char **addr1, char **addr2)
{

    char *buffer = NULL;

    buffer = *addr1;
    *addr1 = *addr2;
    *addr2 = buffer;

}

void str_len_swapper(size_t *len1, size_t *len2)
{

    size_t buffer = 0;

    buffer = *len1;
    *len1 = *len2;
    *len2 = buffer;

}

int reverse_strcmp(const char *str1, const char *str2)
{

    int i = 0;
    int j = 0;

    size_t str_len1 = strlen(str1);
    size_t str_len2 = strlen(str2);

    while (true)
    {
        while (!isalpha(str1[str_len1-i-1]))
        {
            i++;
        }

        while (!isalpha(str2[str_len2-j-1]))
        {
            j++;
        }
        
        if (str1[str_len1-i-1] != str2[str_len2-j-1])
        {
            return str1[str_len1-i-1] - str2[str_len2-j-1];
        }

        i++;
        j++;
    }

    return 0;
}

#endif //SORT_CPP