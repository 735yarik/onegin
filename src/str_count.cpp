/// @file str_count.cpp

#ifndef STR_COUNT_CPP
#define STR_COUNT_CPP

#include "../inc/str_count.h"

size_t str_count(char *poem, size_t size)
{

    assert(poem != NULL);
    assert(isfinite(size));

    size_t str_num = 0;

    while (*poem != EOF)
    {
        if (*poem == '\n')
        {
            str_num++;
        }

        poem++;
    }

    return str_num;

}

#endif // STR_COUNT_CPP
