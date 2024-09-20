/// @file addr_array.cpp

#ifndef ADDR_ARRAY_CPP
#define ADDR_ARRAY_CPP

#include "../inc/addr_array.h"

void addr_array(PoemStruct *poem_info)
{

    assert(poem_info != NULL);

    int str = 1;

    poem_info->addr_begin = (char **) calloc(poem_info->str_num, sizeof(char *));
    poem_info->str_len = (size_t *) calloc(poem_info->str_num, sizeof(size_t));

    assert(poem_info->addr_begin != NULL);

    (poem_info->addr_begin)[0] = poem_info->poem;

    for (size_t c = 0; c < poem_info->size; c++)
    {

        if ((poem_info->poem)[c] == '\n')
        {
            (poem_info->poem)[c] = '\0';
            if (str < poem_info->str_num)
            {
                (poem_info->addr_begin)[str] = &(poem_info->poem[c + 1]);
                str++;
            }
        }

        if (poem_info->poem[c] == '\r')
        {
            poem_info->poem[c] = '\0';
        }
    }

    for (size_t c = 0; c < poem_info->str_num; c++)
    {
        (poem_info->str_len)[c] = strlen((poem_info->addr_begin)[c]);
    }

}

#endif // ADDR_ARRAY_CPP
