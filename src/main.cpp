/// @file main.cpp

#ifndef MAIN_CPP
#define MAIN_CPP

#include "../inc/input_output.h"
#include "../inc/sort.h"
#include "../inc/utils.h"

int main()  //asserts
{

    PoemStruct poem_info = {};

    input(&poem_info);

    sort(poem_info.addr_begin, poem_info.str_num, poem_info.str_len, strcmp);
    output(poem_info.addr_begin, poem_info.str_num);

    free(poem_info.poem);

}

#endif // MAIN_CPP
