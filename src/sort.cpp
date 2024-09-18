/// @file sort.cpp

#ifndef SORT_CPP
#define SORT_CPP

#include "../inc/sort.h"

void sort(char **addr, int str_num)
{

    assert(addr != NULL);
    assert(isfinite(str_num));

    char *buffer =NULL;

    for (int i = 0; i < str_num - 1; i++)
    {
        for (int j = i + 1; j < str_num; j++)
        {   
            if (strcmp(addr[j], addr[i]) < 0)
            {
                buffer = addr[j];
                addr[j] = addr[i];
                addr[i] = buffer;
            }
        }
    }

}

#endif //SORT_CPP