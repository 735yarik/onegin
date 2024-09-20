/// @file sort.cpp

#ifndef SORT_CPP
#define SORT_CPP

#include "../inc/sort.h"

void sort(char **addr, size_t str_num, size_t *str_len)
{

    assert(addr != NULL);
    assert(isfinite(str_num));

    for (int i = 0; i < str_num - 1; i++)
    {
        for (int j = i + 1; j < str_num; j++)
        {
            if (reverse_strcmp(addr[i], addr[j], str_len + i, str_len + j) > 0)
            {
                swapper(addr+j, addr+i);
                str_len_swapper(str_len + i, str_len + j);
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

int reverse_strcmp(char *str1, char *str2, size_t *str_len1, size_t *str_len2)
{
    for (int i = 0; i < *str_len1 && i < *str_len2; i++)
    {
        int j = i;

        while (!isalpha(str1[*str_len1-i-1]))
        {
            i++;
        }
        
        while (!isalpha(str2[*str_len2-j-1]))
        {
            j++;
        }
        
        if (str1[*str_len1-i-1] > str2[*str_len2-j-1])
        {
            i, j = 0;
            return 1;
        }
        else if (str1[*str_len1-i-1] < str2[*str_len2-j-1])
        {
            i, j = 0;
            return -1;
        }
    }

    return 0;
}

#endif //SORT_CPP