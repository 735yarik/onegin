/// @file sort.cpp

#ifndef SORT_CPP
#define SORT_CPP

#include "../inc/sort.h"

void sort(StrStruct *str_info, size_t str_num, int (*cmp)(const char *, const char *, size_t *, size_t *))
{

    assert(str_info != NULL);
    assert(isfinite(str_num));
    assert(cmp != NULL);

    for (int i = 0; i < str_num - 1; i++)
    {
        for (int j = i + 1; j < str_num; j++)
        {
            if (cmp((str_info[i]).addr_begin, (str_info[j]).addr_begin, &(str_info[i]).str_len, &(str_info[j]).str_len) > 0)
            {
                swapper(str_info + j, str_info + i);
            }
        }
    }

}

void swapper(StrStruct *str1, StrStruct *str2)
{

    assert(str1 != NULL);
    assert(str2 != NULL);

    StrStruct buffer = *str1;

    *str1 = *str2;
    *str2 = buffer;

}

int direct_strcmp(const char *str1, const char *str2, size_t *str_len1, size_t *str_len2)
{

    assert(str1 != NULL);
    assert(str2 != NULL);
    assert(str_len1 != NULL);
    assert(str_len2 != NULL);

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
    assert(str_len1 != NULL);
    assert(str_len2 != NULL);

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