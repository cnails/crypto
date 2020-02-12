#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char    *ret_key(char *key, char *message)
{
    int     len;
    int     i;
    int     j;
    int     len_key;
    char    *new_key;

    i = 0;
    j = 0;
    len_key = strlen(key);
    len = strlen(message);
    new_key = (char *)malloc(sizeof(char) * len);
    while (len)
    {
        if (i == len_key)
            i = 0;
        new_key[j] = key[i];
        i++;
        j++;
        len--;
    }
    new_key[j] = '\0';
    return (new_key);
}

int     main(int ac, char **av)
{
    int     i;
    char    *key;
    char    *message;
    char    *result;
    char    alphabet[29] = {"abcdefghijklmnopqrstuvwxyz !\0"};

    if (ac != 3)
    {
        printf("usage: ./a.exe \"key\" \"message\"\n");
        exit(0);
    }
    i = 0;
    key = strlen(av[1]) > strlen(av[2]) ? strdup(av[1]) : ret_key(av[1], av[2]);
    printf("key = {%s}\n", key);
    message = strdup(av[2]);
    printf("result = {");
    result = (char *)malloc(sizeof(char) * strlen(message));
    while (message[i])
    {
        result[i] = alphabet[(message[i] - (message[i] >= 'a' && message[i] <= 'z' ? 'a' : 'A') + key[i] - '0') % 28];
        printf("%c", result[i]);
        i++;
    }
    result[i] = '\0';
    printf("}\n");
    free(key);
    free(message);
}
