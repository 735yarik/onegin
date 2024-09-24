/// @file input_output.cpp

#ifndef INPUT_OUTPUT_CPP
#define INPUT_OUTPUT_CPP

#include "../inc/input_output.h"

void addr_array(PoemStruct *poem_info)
{

    assert(poem_info != NULL);

    int str = 0;
    size_t c = 0;
    size_t str_begin = 0;

    poem_info->addr_begin = (char **) calloc(poem_info->str_num, sizeof(char *));
    poem_info->str_len = (size_t *) calloc(poem_info->str_num, sizeof(size_t));

    assert(poem_info->addr_begin != NULL);


    while ((poem_info->poem)[c] != '\0')
    {
        if ((poem_info->poem)[c] == '\r')
        {
            (poem_info->poem)[c] = '\0';
            
            //(poem_info->str_len)[str] = c - str_begin;
            (poem_info->addr_begin)[str] = &(poem_info->poem[str_begin]);

            str_begin = c + 2;
            str++;
        }

        c++;
    }

}

void input(PoemStruct *poem_info)
{

    poem_info->poem = read_file(&poem_info->size);
    poem_info->str_num = str_count(poem_info->poem);
    addr_array(poem_info);

}

void output(char **addr, int str_num)  
{

    FILE *file = fopen("output.txt", "w");
    
    for (int i = 0; i < str_num; i++)
    {
            fprintf(file, "%s\n", addr[i]);
    }

    fclose(file);

}

#include <stdio.h>

#endif // INPUT_OUTPUT_CPP