#include <stdio.h>
#include <assert.h>
#include <TXLib.h>

struct poem_struct
{

    size_t size;
    int str_num;
    char *poem;
    char **addr;

};

void input(size_t *size, char **poem);
void str_count(char *poem, int *str_num, size_t size);
void addr_array(struct poem_struct *poem_info);
void sort(char **addr, int str_num);
void output(char **addr, int str_num);

//assert

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

void str_count(char *poem, int *str_num, size_t size)
{

    assert(poem != NULL);
    assert(str_num != NULL);
    assert(isfinite(size));

    for (size_t c = 0; c < size; c++)
    {
        if (poem[c] == '\n')
        {
            (*str_num)++;
        }
    }

}

void addr_array(poem_struct *poem_info)
{

    assert(poem_info != NULL);

    int str = 0;

    poem_info->addr = (char **)calloc(poem_info->str_num, sizeof(char *));          // char *
    (poem_info->addr)[0] = poem_info->poem;

    for (size_t c = 0; c < poem_info->size; c++)
    {
        printf("%c", (poem_info->poem)[c]);

        if ((poem_info->poem)[c] == '\n')
        {
            (poem_info->poem)[c] = '\0';
            if (str < poem_info->str_num)
            {
                (poem_info->addr)[str] = &(poem_info->poem[c + 1]);
                str++;
            }
        }

        if (poem_info->poem[c] == '\r')
        {
            poem_info->poem[c] = '\0';
        }
    }

}

void sort(char **addr, int str_num)
{

    assert(addr != NULL);
    assert(isfinite(str_num));

    char *buffer =NULL;

    for (int i = 0; i < str_num - 1; i++)
    {
        for (int j = i + 1; j < str_num; j++)
        {   
            if (strcmp(addr[j], addr[i]) < 0)
            {
                buffer = addr[j];
                addr[j] = addr[i];
                addr[i] = buffer;
            }
        }
    }

}

//isalpha

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
