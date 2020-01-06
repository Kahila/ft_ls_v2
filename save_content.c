#include "ft_ls.h"

//method that will be used to count the amount of files to be allocted
int count_content(char *dir)
{
    int i;
    DIR *mydir;
    struct dirent *files;

    i = 0;
    mydir = opendir(dir);//mem alloc
    if (mydir)
    {
        while((files = readdir(mydir)))
            i++;
        closedir(mydir);//mem free
    }
    return (i);
}

//method that will be used to store all the files in a specific dir
char **save_content(char *dir)
{
    char **files;
    DIR *mydir;
    struct dirent *file;
    int i;
    int size;

    i = 0;
    size = count_content(dir);
    if (size == 0)
        return (NULL);
    files = (char **)malloc(sizeof(char*)*(size+1));
    files[size] = NULL;
    mydir = opendir(dir);
    while ((file = readdir(mydir)) && size)
    {
        files[i] = ft_strcpy(ft_strnew(ft_strlen(file->d_name)), file->d_name);
        i++;
        size--;
    }
    closedir(mydir);//mem free
    return (sort_(files));
}
