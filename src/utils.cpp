/// @file utils.cpp

#ifndef UTILS_CPP
#define UTILS_CPP

#include "../inc/utils.h"

/**
* @brief determines if number a zero
*
* @param [in] num number
*
* @return true if number is a zero and false if it's not
*/

bool is_zero(double num)
{

    assert(isfinite(num));

    if (fabs(num) < EPSILON)
        return true;
    return false;

}

/**
* @brief determines if two numbers equal
*
* @param [in] num1 1st number
* @param [in] num2 2nd number
*
* @return true if number is a zero and false if it's not
*/

bool is_equal(double num1, double num2)
{

    assert(isfinite(num1));
    assert(isfinite(num2));

    return is_zero(num1 - num2);

}

/**
* @brief cleans buffer
*/

void buffer_clean()
{

    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {}

}

char *read_file(size_t *size)
{
    
    assert(size != NULL);

    char *poem = NULL;

    FILE *file = fopen("input.txt", "rb");
    assert(file != NULL);

    *size = file_size(file);

    poem = (char *) calloc((*size) + 1, sizeof(char));
    assert(poem != NULL);

    assert(fread(poem, sizeof(char), *size, file) != 0);

    *(poem + *size) = '\0';

    assert(fclose(file) == 0);

    return poem;

}

size_t file_size(FILE *file)
{

    size_t size = 0;

    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    rewind(file);

    return size;

}

size_t str_count(char *poem)
{

    assert(poem != NULL);

    size_t str_num = 0;

    while (*poem != '\0')
    {
        if (*poem == '\n')
        {
            str_num++;
        }

        poem++;
    }

    return str_num;

}

#endif // UTILS_CPP

