/// @file main.cpp

#ifndef MAIN_CPP
#define MAIN_CPP

#include "../inc/input_output.h"
#include "../inc/sort.h"
#include "../inc/utils.h"

int main()  
{

    PoemStruct poem_info = {};

    input(&poem_info);

    sort(poem_info.addr_begin, poem_info.str_num, poem_info.str_len, direct_strcmp);
    output(poem_info.addr_begin, poem_info.str_num);

    sort(poem_info.addr_begin, poem_info.str_num, poem_info.str_len, reverse_strcmp);
    output(poem_info.addr_begin, poem_info.str_num);

    output_original(poem_info.poem, poem_info.str_num);

    free(poem_info.poem);
    free(poem_info.addr_begin);
    free(poem_info.str_len);

}

#endif // MAIN_CPP
