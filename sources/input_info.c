/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:55:58 by pelease           #+#    #+#             */
/*   Updated: 2020/01/21 18:56:00 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			flags_option(char **f, t_fpf *ft_pf)
{
	int			i;

	i = 0;
	if (ft_pf->flags[0] != '0' && ft_pf->flags[0] != '1')
	{
		while (i < 5)
			ft_pf->flags[i++] = '0';
	}
	if (**f == '-')
		ft_pf->flags[0] = '1';
	else if (**f == '+')
		ft_pf->flags[1] = '1';
	else if (**f == '#')
		ft_pf->flags[2] = '1';
	else if (**f == '0')
		ft_pf->flags[3] = '1';
	else
		ft_pf->flags[4] = '1';
	(*f)++;
	//printf("%s\n", ft_pf->flags);
	
}

void			mwidth_option(char **f, t_fpf *ft_pf)
{
	int			x;
	int			i;

	i = 0;
	ft_pf->mwidth = ft_atoi(*f);
	x = ft_pf->mwidth;
	while (x > 0)
	{
		x /= 10;
		i++;
	}
	(*f) += i;
}

void			precision_option(char **f, t_fpf *ft_pf)
{
	int			x;
	int			i;

	i = 0;
	(*f)++;
	if (**f >= '1' && **f <= '9')
	{
		ft_pf->precision = ft_atoi(*f);
		x = ft_pf->precision;
		while (x > 0)
		{
			x /= 10;
			i++;
		}
		(*f) += i;
	}
	else
	{
		ft_pf->precision = 0;
		if (**f == '0')
			(*f)++;
	}
	//printf("%d\n", ft_pf->precision);
}

void			modf_option(char **f, t_fpf *ft_pf)
{
	int			i;

	i = 0;
	if (ft_pf->modf[0] != '0' && ft_pf->modf[0] != '1')
	{
		while (i < 5)
			ft_pf->modf[i++] = '0';
	}
	if (**f == 'h' && f[0][1] != 'h')
		ft_pf->modf[0] = '1';
	else if (**f == 'h' && f[0][1] == 'h')
		ft_pf->modf[1] = '1';
	else if (**f == 'l' && f[0][1] != 'l')
		ft_pf->modf[2] = '1';
	else if (**f == 'l' && f[0][1] == 'l')
		ft_pf->modf[3] = '1';
	else if (**f == 'L')
		ft_pf->modf[4] = '1';
	if ((**f == 'h' && f[0][1] == 'h') || (**f == 'l' && f[0][1] == 'l'))	
		(*f)++;
	(*f)++;
	//printf("%s\n", ft_pf->modf);
}

void			type_option(char **f, va_list ap, int *len, t_fpf *ft_pf)
{
	char		c;

	if (**f == 'd' || **f == 'i')
		int_execution(ap, len, ft_pf);
	// if (**f == 'o')
	// 	c = 'o';
	// if (**f == 'u')
	// 	c = 'u';
	// if (**f == 'x')
	// 	c = 'x';
	// if (**f == 'X')
	// 	c = 'X';
	// if (**f == 'f')
	// 	c = 'f';
	// if (**f == 'c')
	// 	c = 'c';
	// if (**f == 's')
	// 	c = 's';
	// if (**f == 'p')
	// 	c = 'p';
	// if (**f == '%')
	// 	c = '%';
}
