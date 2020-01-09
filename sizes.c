/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:54:46 by akalombo          #+#    #+#             */
/*   Updated: 2020/01/09 11:55:11 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//method that will be used to get the amount of space to allocate for valid dirs
int count_valid(char **argv, struct s_flags *dirs)
{
	DIR *mydir;
	int len;
	int start;

	len = 0;
	start = dirs->dir_start;
	while (argv[start])
	{
		mydir = opendir(argv[start]);
		if (mydir)
		{
			closedir(mydir);
			len++;
		}
		start++;
	}
	dirs->valid = len;
	return (dirs->valid);
}

//method that will be used to save all the valid dirs
char **store_valid(char **argv, struct s_flags *dirs)
{
	DIR *mydir;
	char **files;
	int i;
	int start;

	i = 0;
	files = (char**)malloc(sizeof(char*)*(count_valid(argv, dirs)+1));
	files[count_valid(argv, dirs)] = NULL;
	start = dirs->dir_start;
	while (argv[start])
	{
		mydir = opendir(argv[start]);
		if (mydir)
		{
			files[i] = ft_strcpy(ft_strnew(ft_strlen(argv[start])), argv[start]);
			closedir(mydir);
			i++;
		}
		start++;
	}
	return (sort_(files));
}
