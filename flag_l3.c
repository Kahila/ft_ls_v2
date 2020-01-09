/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:52:07 by akalombo          #+#    #+#             */
/*   Updated: 2020/01/09 11:52:12 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//this method will be used to get the number of links for each file/folder
int get_nLinks(char *content)
{
	int i;
	int nlinks;
	struct stat buff;
	i = stat(content, &buff);
	nlinks = buff.st_nlink;
	return (nlinks);
}

//this method will tell if a file is a folder or not
int is_file(int nlinks)
{
	if (nlinks == 1)
		return (IS_FILE);
	else
		return (IS_FOLDER);
}

//method that will be used to get the number of bytes per file/dir
int nBytes(char *content)
{
	int Bytes;
	int i;
	struct stat buff;
	i = stat(content, &buff);
	Bytes = buff.st_size;
	return (Bytes);
}

//displaying content
void    l_display(char **files, struct s_flags flags, char *path)
{
	int i;
	struct s_flag_l props;

	i = 0;
	while(files[i])
	{
		if (flags.a == 1 && files[i][0] == '.')
		{
			props = flag_l(files[i], path);
			display(files[i], props);
			ft_putchar('\n');
		}
		else if (files[i][0] != '.')
		{
			props = flag_l(files[i], path);
			display(files[i], props);
			ft_putchar('\n');
		}
		i++;
	}
	return;
}
