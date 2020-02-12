#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int     check_repl(char *str, char c, int i)
{
    while (str[i])
    {
        if (c == str[i])
            return (0);
        i--;
    }
    return (1);
}

char    *remove_repl(char *str)
{
    int     i;
    char    c;
    char    *new;
    int     j;

    i = 0;
    j = 0;
    while (str[i])
    {
        j += check_repl(str, str[i], i);
        i++;
    }
    new = (char *)malloc(sizeof(char) * (j + 1));
    i = 0;
    j = 0;
    while (str[i])
    {
        if (check_repl(str, str[i], i - 1))
        {
            new[j] = str[i];
            j++;
        }
        i++;
    }
    new[j] = '\0';
    return (new);
}

char    *new_alphabet(char *key)
{
    int     i;
    char    *alphabet;
    char    *new_alpha;

    i = 0;
    new_alpha = (char *)malloc(sizeof(char) * 31);
    alphabet = (char[31]){"abcdefghijklmnopqrstuvwxyz ,.!\0"};
    while (key[i])
    {
        new_alpha[i] = key[i];
        i++;
    }
    while (*alphabet)
    {
        if (check_repl(key, *alphabet, strlen(key) - 1))
        {
            new_alpha[i] = *alphabet;
            i++;
        }
        alphabet++;
    }
    new_alpha[i] = '\0';
    return (new_alpha);
}

int     main(int ac, char **av)
{
    int     i;
    int     j;
    int     len;
    char    *key;
    char    *string;
    char    *alpha;

    i = 0;
    if (ac != 3)
    {
        printf("usage: ./a.exe \"key\" \"string\"");
        exit(0);
    }
    key = remove_repl(av[1]);
    printf("key = %s\n", key);
    string = strdup(av[2]);
    len = strlen(key);
    alpha = new_alphabet(key);
    printf("alphabetum = %s\n", alpha);
    while (string[i])
    {
        j = 0;
        while (alpha[j])
        {
            if (string[i] == alpha[j])
            {
                string[i] = j + len < 30 ? alpha[j + len] : alpha[len - (30 - j)];
                break;
            }
            j++;
            if (!alpha[j])
            {
                printf("wrong message!\n");
                exit(0);
            }
        }
        i++;
    }
    string[i] = '\0';
    printf("result = %s\n", string);
    free(key);
    free(string);
    free(alpha);
}
