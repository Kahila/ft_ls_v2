/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:50:36 by akalombo          #+#    #+#             */
/*   Updated: 2020/01/09 11:50:42 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//method that will be used to check if the passed file is in the current dir
int check_main(char *file)
{
	DIR *mydir;
	struct dirent *files;

	mydir = opendir("./");//mem alloc
	while ((files = readdir(mydir)))
	{
		if (ft_strcmp(file,files->d_name) == 0)
		{
			closedir(mydir);//mem free
			return (1);
		}
	}
	closedir(mydir);//mem free
	return (-1);
}

//method that will be used to get the index of the end of path
int end_path(char *path)
{
	int full;

	full = ft_strlen(path);
	while (path[full] != '/' && full != 0)
		full--;
	return (++full);//move to the start of the file name
}

//method that will check if the path is valid
char *valid_path(char *dir)
{
	char *path;
	int i;
	DIR *mydir;

	i = 0;
	path = ft_memalloc(end_path(dir));//mem alloc
	path[end_path(dir)] = '\0';
	while (dir[i] && i != end_path(dir))
	{
		path[i] = dir[i];
		i++;
	}
	if (!(mydir = opendir(path)))//mem alloc
	{
		free(path);//mem free
		return (NULL);
	}
	else
		closedir(mydir);//mem free
	return (path);
}

//method that will be used to check if the file at the end of path is valid
int file_valid(char *path, char *file)
{
	DIR *mydir;
	struct dirent *files;

	mydir = opendir(path);//mem alloc
	// printf("path = %s\n", path);
	while ((files = readdir(mydir)))
	{
		if (ft_strcmp(file,files->d_name) == 0)
		{
			closedir(mydir);//mem free
			free(path);//mem free
			return (1);
		}
	}
	closedir(mydir);//mem free
	free(path);//mem free
	return (-1);
}

int valid_file(char *dir)
{
	char *file;
	char *path;
	int len;
	int i;

	if (check_main(dir) == 1)
		return (1);
	if (end_path(dir) == 1 || !(path = valid_path(dir)))
		return (-1);
	i = 0;
	file = ft_memalloc((ft_strlen(dir) - end_path(dir)+1));//mem alloc
	file[ft_strlen(dir) - end_path(dir)] = '\0';
	len = end_path(dir);
	while (dir[len])
		file[i++] = dir[len++];
	if (file_valid(valid_path(dir), file) == -1)
	{
		free(file);//mem free
		free(path);//mem free
		return (-1);
	}
	free(file);//mem free
	free(path);//mem free
	return (1);
}
