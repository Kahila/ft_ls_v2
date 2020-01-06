//file will contain methods that will be used to sort
#include "ft_ls.h"

//method that will sort by ascii
char **sort_(char **inv)
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
            if (ft_strcmp(inv[i], inv[j]) < 0 && ft_strcmp(inv[i], inv[j]) != 0)
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