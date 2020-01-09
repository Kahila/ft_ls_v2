/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:52:58 by akalombo          #+#    #+#             */
/*   Updated: 2020/01/09 11:53:03 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//method that checks the flags passed and returns error when am invalid one is passed
struct s_flags flags_help(char *argv, struct s_flags flags)
{
	int j;

	j = 1;
	while (argv[j])
	{
		if (argv[j] == 'a' && flags.a != 1)
			flags.a = 1;
		else if (argv[j] == 'l' && flags.l != 1)
			flags.l = 1;
		else if (argv[j] == 't' && flags.t != 1)
			flags.t = 1;
		if (argv[j] == 'r' && flags.r != 1)
			flags.r = 1;
		else if (argv[j] == 'R' && flags.R != 1)
			flags.R = 1;
		else if (argv[j] != 'a' && argv[j] != 'l' && argv[j] != 't' && argv[j] != 'r' && argv[j] != 'R')
		{
			ft_putstr("ls: illegal option -- ");
			ft_putchar(argv[j]);
			ft_putstr("\nusage: ls [-atrlR] [file ...]\n");
			exit(INVALID_FLAG);
		}
		j++;
	}
	return (flags);
}

//method used to initialize the flags
struct s_flags init_flags(struct s_flags *flags, int argc)
{
	if (argc == 1)
		flags->dir_start = 1;
	else
		flags->dir_start = 0;
	flags->a = 0;
	flags->valid = 0;
	flags->invalid = 0;
	flags->l = 0;
	flags->R = 0;
	flags->r = 0;
	flags->t = 0;
	return (*flags);
}

//method that will check the flags passed
struct s_flags flags_(char **argv, int argc)
{
	int i;
	struct s_flags flags;

	i = 1;
	flags = init_flags(&flags, argc);
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--") == 0)
		{
			flags.dir_start = ++i;
			return (flags);
		}
		else if (!argv[i][1])
		{
			flags.dir_start = 1;
			break;
		}
		flags = flags_help(argv[i], flags);
		flags.dir_start = ++i;
	}
	return (flags);
}

int sudo_main_flags(int argc, char **argv, struct s_flags flags)
{
	int len;
	char **files;
	int i;

	i  = 0;
	check_files(argv, flags);
	files = save_content("./");//mem alloc
	if (flags.t == 1)
		files = flag_t(files);
	if (flags.r == 1)
		files = flag_r(files);
	if (flags.invalid == 0 && flags.valid == 0 && flags.l != 1)
		flag_a(files, flags);
	if (flags.invalid == 0 && flags.valid == 0 && flags.l == 1)
		l_display(files, flags, "./");
	while (files[i])
		free(files[i++]);//mem free
	free(files);//mem free
	return (0);
}
