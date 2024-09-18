/// @file main.cpp

#ifndef MAIN_CPP
#define MAIN_CPP

#include "../inc/main.h"
#include "../inc/input_output.h"
#include "../inc/str_count.h"
#include "../inc/addr_array.h"
#include "../inc/sort.h"

int main()
{

    poem_struct poem_info = {};

    input(&poem_info.size, &poem_info.poem);
    str_count(poem_info.poem, &poem_info.str_num, poem_info.size);
    addr_array(&poem_info);
    sort(poem_info.addr, poem_info.str_num);
    output(poem_info.addr, poem_info.str_num);

    free(poem_info.poem);

}

#endif // MAIN_CPP
