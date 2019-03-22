/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:51:26 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 16:23:03 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*take_piece(char *point)
{
	char	*pos;

	pos = ft_strchr(point, '%');
	return (pos);
}

void		process_piece(char const *str, t_nigga **nig)
{
	char	*p;

	if ((p = ft_strchr(str, '.')))
	{
		check_min_width(str, nig);
		check_precision(p + 1, nig);
	}
	else
	{
		check_min_width(str, nig);
		(*nig)->p_s = 0;
	}
	// printf("addres {%p} min [%i], max [%i]\n", (*nig), (*nig)->m_s, (*nig)->p_s);
}

int			find_greater(int a, int b)
{
	return (a > b ? a : b);
}

char const	*find_width_digits(char const *str, t_nigga **nig)
{
	t_nigga *none;

	none = *nig;
	while (*str && *str != '.')
	{
		if (ft_isdigit(*str))
			return (str);
		str++;
	}
	return (NULL);
}

char const	*find_precision_digits(int *f, char const *str, t_nigga **nig)
{
	t_nigga *none;

	none = *nig;
	while (*str && (*str) != *(*nig)->conv)
	{
		if (!ft_isdigit(*str))
			(*f)++;
		if (ft_isdigit(*str))
			return (str);
		str++;
	}
	return (str ? str : NULL);
}
