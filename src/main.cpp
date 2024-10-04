/// @file main.cpp

#ifndef MAIN_CPP
#define MAIN_CPP

#include "../inc/input_output.h"
#include "../inc/sort.h"
#include "../inc/utils.h"

void free_all(PoemStruct *poem_info);

int main()  
{

    PoemStruct poem_info = {};

    input(&poem_info);

    sort(poem_info.str_info, poem_info.str_num, direct_strcmp);
    output(poem_info.str_info, poem_info.str_num);

    sort(poem_info.str_info, poem_info.str_num, reverse_strcmp);
    output(poem_info.str_info, poem_info.str_num);

    output_original(poem_info.poem, poem_info.str_num);

    free(poem_info.poem);
    free(poem_info.str_info);

    free_all(&poem_info);

}

void free_all(PoemStruct *poem_info)
{
    
    free(poem_info->poem);
    free(poem_info->str_info);

    poem_info->file = NULL;
    poem_info->size = 0;
    poem_info->str_num = 0;
    poem_info->poem = NULL;
    poem_info->str_info = NULL;

}

#endif // MAIN_CPP
