/// @file input_output.h

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "../inc/utils.h"

struct StrStruct
{

    const char *addr_begin = NULL;
    size_t str_len = 0;

};

struct PoemStruct
{

    FILE *file = NULL;
    size_t size = 0;
    size_t str_num = 0;
    char *poem = NULL;
    StrStruct *str_info = NULL;

};

void addr_array(PoemStruct *poem_info);

void input(PoemStruct *poem_info);

void output(StrStruct *poem_info, int str_num);

void output_original(char *poem, int str_num);

#endif // INPUT_OUTPUT_H
