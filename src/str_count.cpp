/// @file str_count.cpp

#ifndef STR_COUNT_CPP
#define STR_COUNT_CPP

#include "../inc/str_count.h"

void str_count(char *poem, int *str_num, size_t size)
{

    assert(poem != NULL);
    assert(str_num != NULL);
    assert(isfinite(size));

    for (size_t c = 0; c < size; c++)
    {
        if (poem[c] == '\n')
        {
            (*str_num)++;
        }
    }

}

#endif // STR_COUNT_CPP
