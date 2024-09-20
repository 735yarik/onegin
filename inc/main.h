/// @file main.h

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct PoemStruct
{

    FILE *file = NULL;
    size_t size = 0;
    size_t str_num = 0;
    char *poem = NULL;
    char **addr_begin = NULL;
    size_t *str_len = NULL;

};


#endif // MAIN_H