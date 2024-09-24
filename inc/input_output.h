/// @file input_output.h

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "../inc/utils.h"

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

void addr_array(PoemStruct *poem_info);

void input(PoemStruct *poem_info);

void output(char **addr, int str_num);

#endif // INPUT_OUTPUT_H
