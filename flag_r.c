/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:52:20 by akalombo          #+#    #+#             */
/*   Updated: 2020/01/09 11:52:25 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int count(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//method that will be used for the -r dir
char **flag_r(char **inv)
{
	int i;
	int j;
	char **new;

	i = 0;
	j = count(inv);
	new = (char**)malloc(sizeof(char*)*count(inv) + 1);
	new[count(inv)] = NULL;
	j--;
	while (j >= 0)
	{
		new[i] = ft_strcpy(ft_strnew(ft_strlen(inv[j])), inv[j]);//mem alloc
		free(inv[j]);//mem free
		j--;
		i++;
	}
	free(inv);//mem free
	return (new);
}
