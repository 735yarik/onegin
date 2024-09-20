/// @file input_output.cpp

#ifndef INPUT_OUTPUT_CPP
#define INPUT_OUTPUT_CPP

#include "../inc/input_output.h"

char *read_file(size_t *size)
{
    
    assert(size != NULL);

    char *poem = NULL;

    FILE *file = fopen("input.txt", "rb");

    // assert(*file != NULL);

    fseek(file, 0L, SEEK_END);
    *size = ftell(file);
    rewind(file);

    poem = (char *) calloc((*size) + 1, sizeof(char));
    assert(poem != NULL);

    assert(fread(poem, sizeof(char), *size, file) != 0);

    *(poem + *size) = '\0';

    assert(fclose(file) == 0);

    return poem;

}

void output(char **addr, int str_num)  
{

    assert(addr != NULL);
    assert(isfinite(str_num));
    
    for (int i = 0; i < str_num; i++)
    {
        printf("\n%s", addr[i]); 
    }

}

#endif // INPUT_OUTPUT_CPP
