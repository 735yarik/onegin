/// @file input_output.cpp

#ifndef INPUT_OUTPUT_CPP
#define INPUT_OUTPUT_CPP

#include "../inc/input_output.h"

const char *OUTPUT_FILE = "output.txt";

void addr_array(PoemStruct *poem_info)
{

    assert(poem_info != NULL);

    int str = 0;
    size_t c = 0;
    size_t str_begin = 0;

    poem_info->str_info = (StrStruct *) calloc(poem_info->str_num, sizeof(StrStruct));
    assert(poem_info->str_info != NULL);


    while (poem_info->poem[c] != '\0')
    {
        if ((poem_info->poem)[c] == '\r')
        {
            (poem_info->poem)[c] = '\0';
            
            ((poem_info->str_info)[str]).str_len = c - str_begin;
            ((poem_info->str_info)[str]).addr_begin = &(poem_info->poem[str_begin]);

            str_begin = c + 2;
            str++;
        }

        c++;
    }

}

void input(PoemStruct *poem_info)
{

    assert(poem_info != NULL);

    poem_info->poem = read_file(&poem_info->size);
    poem_info->str_num = str_count(poem_info->poem);
    addr_array(poem_info);

}

void output(StrStruct *poem_info, int str_num)  
{

    assert(poem_info != NULL);

    FILE *file = fopen(OUTPUT_FILE, "a");
    assert(file != NULL);
    
    for (int i = 0; i < str_num; i++)
    {
        fprintf(file, "%s\n", poem_info[i].addr_begin);
    }

    fprintf(file, "\n");

    assert(!fclose(file));

}

void output_original(char *poem, int str_num)
{

    assert(poem != NULL);
    assert(str_num != 0);

    FILE *file = fopen(OUTPUT_FILE, "a");
    assert(file != NULL);

    int str = 0;
    int c = 0;

    for (int i = 0; i < str_num; i++)
    {
        while (poem[c] != '\0')
        {
            fprintf(file, "%c", poem[c]);
            c++;
        }
        c++;
    }

    assert(fclose(file) == 0);

}

#include <stdio.h>

#endif // INPUT_OUTPUT_CPP