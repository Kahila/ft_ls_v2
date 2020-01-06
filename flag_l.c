#include "ft_ls.h"

//method that will deal with the -l flag
//method that will be used to get the date the file was last modified
char   *last_mod(char *content)
{
    time_t month_mod;
    char *ti;
    char *lastMode;
    int i;
    int j;

    lastMode = ft_memalloc(sizeof(char) * 12);//mem alloc
    struct stat buff;
    i = stat(content, &buff);
    month_mod = buff.st_mtime;
    ti = ctime(&month_mod);//ctime will return a string of the epoch time pasted
    i = 4;
    j = 0;
    while(i <= 15)
    {
        lastMode[j] = ti[i];
        i++;
        j++;
    }
    lastMode[12] = '\0';
    return (lastMode);
}

//method that will be used to determine the user to which file belongs
char    *user(char *content)
{
    struct stat buff;
    int i;
    struct passwd *ID;

    // content = ft_strjoin("libft/", content);
    i = stat(content, &buff);
    ID = getpwuid(buff.st_uid);
    if (ID != NULL)
        return (ID->pw_name);
    else
        return (ft_itoa(buff.st_uid));
}

//method that will be used to get the group to which file/dir belongs
char  *group(char *content)
{
    struct stat buff;
    int i;
    struct group *ID;

    i = stat(content, &buff);
    ID = getgrgid(buff.st_gid);
    return (ID->gr_name);
}

//this method will be used to get the permisions for the user.group and other
char            *permits(char *file)
{
    struct stat buff;
    int i;
    char *str;

    if ((stat(file, &buff) < 0))
            return (NULL);
    i = stat(file, &buff);
    str = ft_memalloc(sizeof(char)*10);//mem alloc
    S_ISDIR(buff.st_mode) ? str[0] = 'd' : (str[0] = '-');
    (buff.st_mode & S_IRUSR) ? str[1] = 'r' : (str[1] = '-');
    (buff.st_mode & S_IWUSR) ? str[2] = 'w' : (str[2] = '-');
    (buff.st_mode & S_IXUSR) ? str[3] = 'x' : (str[3] = '-');
    (buff.st_mode & S_IRGRP) ? str[4] = 'r' : (str[4] = '-');
    (buff.st_mode & S_IWGRP) ? str[5] = 'w' : (str[5] = '-');
    (buff.st_mode & S_IXGRP) ? str[6] = 'x' : (str[6] = '-');
    (buff.st_mode & S_IROTH) ? str[7] = 'r' : (str[7] = '-');
    (buff.st_mode & S_IWOTH) ? str[8] = 'w' : (str[8] = '-');
    (buff.st_mode & S_IXOTH) ? str[9] = 'x' : (str[9] = '-');
    str[10] = '\0';
    return (str);
}