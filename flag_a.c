/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:51:14 by akalombo          #+#    #+#             */
/*   Updated: 2020/01/09 11:51:22 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//method that will be used for the -a flag and basic ls
void flag_a(char** files, struct s_flags flags)
{
	int i;

	i = 0;
	while(files[i])
	{
		if (flags.a == 1 && files[i][0] == '.')
		{
			ft_putstr(files[i]);
			ft_putchar('\n');
		}
		else if (files[i][0] != '.')
		{
			ft_putstr(files[i]);
			ft_putchar('\n');
		}
		i++;
	}
	return;
}
