/// @file input_output.cpp

#ifndef INPUT_OUTPUT_CPP
#define INPUT_OUTPUT_CPP

#include "../inc/input_output.h"

void input(size_t *size, char **poem)
{

    assert(size != NULL);
    assert(poem != NULL);

    FILE *file = NULL;

    file = fopen("input.txt", "rb");
    fseek(file, 0L, SEEK_END);
    *size = ftell(file);
    rewind(file);

    *poem = (char *)calloc((*size) + 1, sizeof(char));
    fread(*poem, sizeof(char), *size, file);

    *(*poem + *size) = '\0';

    fclose(file);

}

void output(char **addr, int str_num)  
{

    assert(addr != NULL);
    assert(isfinite(str_num));

    printf("\nsorted poem:");
    
    for (int i = 0; i < str_num; i++)
    {
        printf("\n%s", addr[i]); 
    }

}

#endif // INPUT_OUTPUT_CPP
