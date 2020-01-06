#include "ft_ls.h"

//method that will be used to get the date the file was last modified
int    l_mod(char *content)
{
    time_t month_mod;
    int i;

    struct stat buff;
    i = stat(content, &buff);
    month_mod = buff.st_mtime;
    return (month_mod);
}

//method that is used to sort the files by last modified
char **flag_t(char **inv)
{
    int i;
    int j;
    char *tmp;

    i = 0;
    while (inv[i])
    {
        j = 0;
        while (inv[j])
        {
            if (l_mod(inv[i]) > l_mod(inv[j]) && l_mod(inv[i]) != l_mod(inv[j]))
            {
                tmp = inv[j];
                inv[j] = inv[i];
                inv[i] = tmp;
            }
            j++;
        }
        i++;
    }
    return (inv);
}