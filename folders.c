/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   folders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:53:17 by akalombo          #+#    #+#             */
/*   Updated: 2020/01/09 11:53:21 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//file will deal with functions that are used when valid dir's are passed with flags
void folders(struct s_flags flags, char **argv)
{
	char **dirs;
	char **files;
	int i;
	int j;

	i = 0;
	dirs = store_valid(argv, &flags);
	while (dirs[i])
	{
		files = save_content(dirs[i]);
		if (flags.t == 1)
			files = flag_t(files);
		if (flags.r == 1)
			files = flag_r(files);
		if (flags.l != 1)
			flag_a(files, flags);
		if (flags.l == 1)
			l_display(files, flags, dirs[i]);
		j = 0;
		while (files[j])
			free(files[j++]);//mem free
		free(files);//mem free
		i++;
	}
	return;
}
