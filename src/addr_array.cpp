/// @file addr_array.cpp

#ifndef ADDR_ARRAY_CPP
#define ADDR_ARRAY_CPP

#include "../inc/addr_array.h"

void addr_array(poem_struct *poem_info)
{

    assert(poem_info != NULL);

    int str = 0;

    poem_info->addr = (char **)calloc(poem_info->str_num, sizeof(char *));          // char *
    (poem_info->addr)[0] = poem_info->poem;

    for (size_t c = 0; c < poem_info->size; c++)
    {
        printf("%c", (poem_info->poem)[c]);

        if ((poem_info->poem)[c] == '\n')
        {
            (poem_info->poem)[c] = '\0';
            if (str < poem_info->str_num)
            {
                (poem_info->addr)[str] = &(poem_info->poem[c + 1]);
                str++;
            }
        }

        if (poem_info->poem[c] == '\r')
        {
            poem_info->poem[c] = '\0';
        }
    }

}

#endif // ADDR_ARRAY_CPP
