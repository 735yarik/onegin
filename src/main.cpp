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

    PoemStruct poem_info = {};

    poem_info.poem = read_file(&poem_info.size);
    poem_info.str_num = str_count(poem_info.poem, poem_info.size);
    addr_array(&poem_info);
    sort(poem_info.addr_begin, poem_info.str_num, poem_info.str_len);
    output(poem_info.addr_begin, poem_info.str_num);

    free(poem_info.poem);

}

#endif // MAIN_CPP
