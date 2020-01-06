#include "ft_ls.h"

//method that will check for the invalid files
void check_files(char **argv, struct s_flags dirs)
{
    DIR *mydir;
    char **files;
    int i;

    i = 0;
    files = store_invalid(argv, dirs);
    while (files[i])
    {
        mydir = opendir(files[i]);//mem alloc
        if (!mydir)
        {
            if (valid_file(files[i]) == -1)
            {
                ft_putstr("ls: ");
                ft_putstr(files[i]);
                ft_putstr(": No such file or directory\n");
            }
        }
        else
            closedir(mydir);//mem free
        free(files[i++]);//mem free
    }
    free(files);//mem free
    check_files_val(argv, dirs);
    return;
}

//method that will be used to get the amount of space to allocate for invalid files
int count_invalid(char **argv, struct s_flags *dirs)
{
    DIR *mydir;
    int len;
    int start;

    len = 0;
    start = dirs->dir_start;
    while (argv[start])
    {
        mydir = opendir(argv[start]);//mem alloc
        if (!mydir)
            len++;
        else
            closedir(mydir);//mem free
        start++;
    }
    dirs->invalid = len;
    return (dirs->invalid);
}

//method that will be used to save all the invalid files
char **store_invalid(char **argv, struct s_flags dirs)
{
    DIR *mydir;
    char **files;
    int i;
    int start;

    i = 0;
    files = (char**)malloc(sizeof(char*)*(count_invalid(argv, &dirs)+1));
    files[count_invalid(argv, &dirs)] = NULL;
    start = dirs.dir_start;
    while (argv[start])
    {
        mydir = opendir(argv[start]);//mem alloc
        if (!mydir)
        {
            files[i] = ft_strcpy(ft_strnew(ft_strlen(argv[start])), argv[start]);//mem alloc
            i++;
        }
        else
            closedir(mydir);//mem free
        start++;
    }
    return (sort_(files));
}

//method that will be used to sort the passed flags or dir by ascii
//method that will be used to save all dir's
void check_files_val(char **argv, struct s_flags dirs)
{
    DIR *mydir;
    char **files;
    int i;

    i = 0;
    files = store_invalid(argv, dirs);
    while (files[i])
    {
        mydir = opendir(files[i]);//mem alloc
        if (!mydir)
        {
            if (valid_file(files[i]) == 1)
            {
                ft_putstr(files[i]);
                ft_putchar('\n');
            }
        }
        else
            closedir(mydir);//mem free
        free(files[i]);//mem free
        i++;
    }
    free(files);//mem free
    return;
}