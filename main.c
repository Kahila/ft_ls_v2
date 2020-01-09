/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:54:09 by akalombo          #+#    #+#             */
/*   Updated: 2020/01/09 11:54:16 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main (int argc, char **argv)
{
	struct s_flags flags;
	int len_invalid;
	char **dirs;//will contain all the valid dir's

	flags = flags_(argv, argc);
	dirs = store_valid(argv, &flags);
	len_invalid = count_invalid(argv, &flags);
	sudo_main_flags(argc, argv, flags);
	if (flags.valid != 0)
		folders(flags, argv);
	return (0);
}
