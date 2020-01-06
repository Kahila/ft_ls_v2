#include "ft_ls.h"

int main (int argc, char **argv)
{
    struct s_flags flags;
    int len_invalid;
    char **dirs;//will contain all the valid dir's
    int i = 0;

    flags = flags_(argv, argc);
    dirs = store_valid(argv, &flags);
    len_invalid = count_invalid(argv, &flags);
    // printf("a = %i\n", flags.a);
    // printf("l = %i\n", flags.l);
    // printf("t = %i\n", flags.t);
    // printf("R = %i\n", flags.R);
    // printf("r = %i\n", flags.r);
    // printf("valid = %i\n", flags.valid);
    // printf("invalid = %i\n", flags.invalid);
    // printf("start = %i\n\n", flags.dir_start);
    // while (dirs[i])
    //     printf("valid dir = %s\n", dirs[i++]);
    // printf("**********************************\n\n");

    sudo_main_flags(argc, argv, flags);
    if (flags.valid != 0)
        folders(flags, argv);
    // while (1 == 1)
    // {}

    return (0);
}