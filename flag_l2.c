/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_l2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:51:54 by akalombo          #+#    #+#             */
/*   Updated: 2020/01/09 11:52:00 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//method will be used to get the paths of the files in subdir
char *get_path(char *folder, char *content)
{
	char *fullpath;
	char *add;
	DIR *check;

	if (content)
	{
		check = opendir(folder);//mem alloc
		if (!check)
			return NULL;
		fullpath = ft_strjoin(folder, "/");//mem alloc
		add = fullpath;//mem free
		fullpath = ft_strjoin(fullpath, content);//mem alloc
		free(add);//mem free
		closedir(check);//free mem
		return (fullpath);
	}
	return NULL;
}

//method that will be used to save the properties in the s_flag_l struct
struct s_flag_l flag_l(char *file, char *dir)
{
	struct s_flag_l props;
	char *full_path;

	full_path = get_path(dir, file);//mem alloc
	props.nLinks = get_nLinks(full_path);
	props.dirORfile = is_file(props.nLinks);
	props.nBytes = nBytes(full_path);
	props.last_modified = last_mod(full_path);
	props.user = user(full_path);
	props.group = group(full_path);
	props.fileName = file;
	props.permits = permits(full_path);
	free(full_path);//mem free
	return (props);
}

//method used to display the properties
void display(char *files, struct s_flag_l props)
{
	files = NULL;
	ft_putstr(props.permits);
	free(props.permits);//mem free
	ft_putchar('\t');
	ft_putnbr(props.nLinks);
	ft_putchar('\t');
	ft_putstr(props.user);
	ft_putchar('\t');
	ft_putstr(props.group);
	ft_putchar('\t');
	ft_putnbr(props.nBytes);
	ft_putchar('\t');
	ft_putstr(props.last_modified);
	free(props.last_modified);//mem free
	ft_putchar('\t');
	ft_putstr(props.fileName);
}
