#include <stdio.h>
#include <TXLib.h>

// ftell
// fseek
// rewind
// fread

void input(size_t *size, char **poem);
void output(char **addr, int str_num);
void stri_count(char *poem, int *str_num, size_t size);
void addr_array(char ***addr, int str_num, char **poem, size_t size);
void sort(char **addr, int str_num);

int main()
{
    size_t size = 0;
    int str_num = 0;
    char *poem = NULL;
    char **addr = NULL;

    input(&size, &poem);
    stri_count(poem, &str_num, size);

   int str = 1;

    addr = (char **)calloc(str_num, sizeof(char **));
    addr[0] = poem;

    for (size_t c = 0; c < size; c++)
    {
        printf("%c", poem[c]);
        if (poem[c] == '\n' || (poem[c] == '\r'))
        {
            poem[c] = '\0';
            if (str < str_num)
            {
                addr[str] = &poem[c + 1];
                str++;
            }
        }
    }

    sort(addr, str_num);
    printf("\nsorted poem:\n");
    output(addr, str_num);

    free(poem);

}

void sort(char **addr, int str_num)
{

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

void output(char **addr, int str_num)
{

    for (int i = 0; i < str_num; i++)
    {
        printf("\n%s", addr[i]); 
    }

}

void stri_count(char *poem, int *str_num, size_t size)
{

    for (size_t c = 0; c < size; c++)
    {
        if (poem[c] == '\n')
        {
            (*str_num)++;
        }
    }

}

void input(size_t *size, char **poem)
{

    FILE *file = NULL;

    file = fopen("input.txt", "r");
    fseek(file, 0L, SEEK_END);
    *size = ftell(file);
    rewind(file);

    *poem = (char *)calloc(*size, sizeof(char *));
    fread(*poem, sizeof(char), *size, file);
    fclose(file);

}

void addr_array(char ***addr, int str_num, char **poem, size_t size)
{

    int str = 1;

    *addr = (char **)calloc(str_num, sizeof(char **));
    (*addr)[0] = *poem;

    for (size_t c = 0; c < size; c++)
    {
        printf("%c", (*poem)[c]);
        if ((*poem)[c] == '\n' || ((*poem)[c] == '\r'))
        {
            (*poem)[c] = '\0';
            if (str < str_num)
            {
                (*addr)[str] = poem[c + 1];
                str++;
            }
        }
    }
}