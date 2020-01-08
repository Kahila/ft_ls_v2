#include "ft_ls.h"

//method that will be used to get the path
char *full_path(char *dir, char *file)
{
    int len;
    char *path;
    int i;
    int j;
    
    i = j = 0;
    len = ft_strlen(dir) + ft_strlen(file);
    path = ft_memalloc(len + 1);
    while (dir[j])
    {
        path[i] = dir[j++];
        i++;
    }
    j = 0;
    path[i] = '/';
    i++;
    while (file[j])
    {
        path[i] = file[j++];
        i++;
    }
    path[i] = '/';
    path[i+1] = '\0';
    return (path);
}

//method that will be used to get the size of the dir's
int dirs_count(char **content, char *file)
{
    int i;
    DIR *mydir;
    int count;

    count = i = 0;
    while (content[i])
    {
        // mydir = opendir(full_path(file, content[i]));
        if ((mydir = opendir(full_path(file, content[i]))) && ft_strcmp("..", content[i]) != 0 && ft_strcmp(".", content[i]) != 0)//mem alloc
        {
            closedir(mydir);//mem free
            count++;
        }
        i++;
    }
    return (count);
}

//method that will store the dir's in the curr dir
char **sub_dir(char *dir)
{
    char **content;
    char **dirs;
    DIR *mydir;
    char *path;
    int i;
    int j;

    content = save_content(dir);
    dirs = (char **)malloc(sizeof(char*)*(dirs_count(content, dir)));//mem alloc
    j = i = 0;
    while (content[i])
    {
        path = full_path(dir, content[i]);
        if ((mydir = opendir(path)) && ft_strcmp("..", content[i]) != 0 && ft_strcmp(".", content[i]) != 0)//mem alloc
        {
            dirs[j] = full_path(dir, content[i]);
            //printf(">>>%s\n", dirs[j]);
            closedir(mydir);//mem free
            j++;
        }
        // if (mydir)
        //     closedir(mydir);
        // ft_putchar('\n');
        // free(content[i]);//mem free
        i++;
    }
    dirs[j] = NULL;
    free(content);//mem free
    return (dirs);
}

//method that will walk the dir tree
void flag_R_(char *dir)
{
    char **dirs;
    char **content;
    int i;
    int j;
    DIR *mydir;
    int count = 0;
    
    i = 0;
    dirs = sub_dir(dir);
    // while (dirs[i])
    //     printf("----%s\n",dirs[i++]);
    i = 0;
    // printf("---%s\n", dir);
    // && (mydir = opendir(dirs[i])
    while (dirs[i])
    {
        if ((mydir = opendir(dirs[i])))
        {

            printf("!!! %s | \n", dirs[i]);
            content = save_content(dirs[i]);
            count = dirs_count(content, dirs[i]);
            // printf(">>>%i\n", count);
            j = 0;
            if (count > 0 )
            {
                // dirs = sub_dir(dirs[i]);
                // printf("\n");
                flag_R_(dirs[i]);
                printf("*********************************************\n");
            }
            free(dirs[i]);
            while (content[j])
                free(content[j++]);
            free(content);
            // while (1==1)
            // {}
        }
        i++;
    }
}

//method that will print the dir's in the sub dir's
int main(int argc, char **argv)
{
    struct s_flags flags;
    int len_invalid;
    char **dirs;//will contain all the valid dir's
    int i = 0;
    flags = flags_(argv, argc);
    dirs = store_valid(argv, &flags);
    while (dirs[i])
    {
        printf(">>%s\n", dirs[i]);
        flag_R_(dirs[i]);
        i++;
    }


    return (0);
}