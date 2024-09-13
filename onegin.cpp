#include <stdio.h>
#include <TXLib.h>

// ftell
// fseek
// rewind
// fread

int main()
{
    size_t size = 0;
    int str_num = 0;
    int str = 1;
    char *poem = NULL;
    char **addr = NULL;
    char *buffer =NULL;
    FILE *file = NULL;

    file = fopen("input.txt", "r");
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    rewind(file);

    poem = (char *)calloc(size, sizeof(char));
    fread(poem, sizeof(char), size, file);

    for (size_t c = 0; c < size; c++)
    {
        if (poem[c] == '\n')
        {
            str_num++;
        }
    }

    addr = (char **)calloc(str_num, sizeof(char *));
    addr[0] = &poem[0];

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

    fclose(file);
    free(poem);

    printf("\nsorted poem:\n");
    for (int i = 0; i < str_num; i++)
    {
        printf("\n%s", addr[i]);
    }
}
