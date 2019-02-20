/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:33:35 by akorol            #+#    #+#             */
/*   Updated: 2019/02/20 11:33:52 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*join_sign_f(char *str, t_nigga **nig)
{
	char	*buf;

	buf = str;
	if ((*nig)->sign == '-')
	{
		str = ft_strjoin("-", buf);
		free(buf);
	}
	else if ((*nig)->plus)
	{
		str = ft_strjoin("+", buf);
		free(buf);
	}
	return (str);
}

void		add_sign_f(char *str, t_nigga **nig)
{
	if ((*nig)->zero)
	{
		if ((*nig)->sign == '-')
			str[0] = '-';
		else if ((*nig)->plus)
			str[0] = '+';
	}
	else
	{
		while (*str)
		{
			if (ft_isdigit(*str))
			{
				if ((*nig)->sign == '-')
					*(--str) = '-';
				else if ((*nig)->plus)
					*(--str) = '+';
				break;
			}
			str++;
		}
	}
}

char		*string_tuning_f(char *buf, char *str, t_nigga **nig)
{
	buf = ft_strnew((*nig)->m_s);
	fill2(buf, (*nig)->m_s);
	if ((*nig)->minus)
	{
		if ((*nig)->blank || (*nig)->sign == '-' || (*nig)->plus)
			custom_strcpy(buf + 1, str);
		else
			custom_strcpy(buf, str);
	}
	else
		custom_strcpy(buf + (*nig)->m_s - ft_strlen(str), str);
	if ((*nig)->zero && !(*nig)->minus)
		fill_wz_zero(buf);
	if ((*nig)->blank && !(*nig)->plus)
		buf[0] = ' ';
	add_sign_f(buf, nig);
	return (buf);
}

void		buf_tuning_f(char *str, t_nigga **nig)
{
	char	*buf;
	char	*trash;

	buf = NULL;
	if ((*nig)->m_s > ft_strlen(str))
		buf = string_tuning_f(buf, str, nig);
	else
	{
		if ((*nig)->blank && !(*nig)->plus && (*nig)->sign != '-')
			buf = ft_strjoin(" ", str);
		else
			buf = join_sign_f(str, nig);
	}
	if ((*nig)->out)
	{
		trash = (*nig)->out;
		(*nig)->out = ft_strjoin(trash, buf);
		free(trash);
	}
	else
	{
		(*nig)->out = ft_strdup(buf);
	}
	if (buf)
		free(buf);
	// system("leaks a.out");		//search for leaks in the section of grabbing width and precision
}


