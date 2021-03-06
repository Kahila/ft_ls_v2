/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalombo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:43:57 by akalombo          #+#    #+#             */
/*   Updated: 2019/06/17 13:20:06 by akalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int i;

	if (!s2 || !s1)
		return (0);
	i = 0;
	while (n != 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 == *s2)
			i++;
		else
			return (0);
		n--;
		s1++;
		s2++;
	}
	return (1);
}
