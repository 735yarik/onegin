/// @file sort.cpp

#ifndef SORT_CPP
#define SORT_CPP

#include "../inc/sort.h"

void sort(char **addr, size_t str_num, size_t *str_len, int (*cmp)(const char *, const char *, size_t *, size_t *))
{

    assert(str_len != NULL);
    assert(addr != NULL);
    assert(isfinite(str_num));
    assert(cmp != NULL);

    for (int i = 0; i < str_num - 1; i++)
    {
        for (int j = i + 1; j < str_num; j++)
        {
            if (cmp(addr[i], addr[j], str_len + i, str_len + j) > 0)
            {
                swapper(addr+j, addr+i);
                str_len_swapper(str_len + i, str_len + j);
            }
        }
    }

}

void swapper(char **addr1, char **addr2)
{

    assert(addr1 != NULL);
    assert(addr2 != NULL);

    char *buffer = NULL;

    buffer = *addr1;
    *addr1 = *addr2;
    *addr2 = buffer;

}

void str_len_swapper(size_t *len1, size_t *len2)
{

    assert(len1 != NULL);
    assert(len2 != NULL);

    size_t buffer = 0;

    buffer = *len1;
    *len1 = *len2;
    *len2 = buffer;

}

int direct_strcmp(const char *str1, const char *str2, size_t *str_len1, size_t *str_len2)
{

    assert(str1 != NULL);
    assert(str2 != NULL);

    int i = 0;
    int j = 0;

    while (true)
    {
        while (!isalpha(str1[i]))
        {
            i++;
        }

        while (!isalpha(str2[j]))
        {
            j++;
        }
        
        if (str1[i] != str2[j])
        {
            return str1[i] - str2[j];
        }

        i++;
        j++;
    }

}

int reverse_strcmp(const char *str1, const char *str2, size_t *str_len1, size_t *str_len2)
{

    assert(str1 != NULL);
    assert(str2 != NULL);

    int i = 0;
    int j = 0;

    while (true)
    {
        while (!isalpha(str1[*str_len1-i-1]))
        {
            i++;
        }

        while (!isalpha(str2[*str_len2-j-1]))
        {
            j++;
        }
        
        if (str1[*str_len1-i-1] != str2[*str_len2-j-1])
        {
            return str1[*str_len1-i-1] - str2[*str_len2-j-1];
        }

        i++;
        j++;
    }

    return 0;
}

#endif //SORT_CPP