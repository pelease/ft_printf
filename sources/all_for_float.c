/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_for_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:36:44 by pelease           #+#    #+#             */
/*   Updated: 2020/02/09 21:36:46 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			float_left_side(va_list ap, t_fpf *ft_pf, t_arg *arg)
{
	int			i;
	long double	fl;

	fl = 5.0;
	i = -1;
	ft_pf->precision = (ft_pf->pr_sign == 'N') ? 6 : ft_pf->precision;
	while (++i < ft_pf->precision + 1)
		fl /= 10;
	if (ft_pf->precision >= 20 && arg->num_fl >= 1.0110000000000100100)
		fl += 1.0;
	ft_bzero((void*)arg->f, 51);
	if (ft_pf->modf[4] == '1')
		arg->num_fl = va_arg(ap, long double);
	else
		arg->num_fl = va_arg(ap, double);
	arg->num_fl = (arg->num_fl < 0) ? arg->num_fl - fl : arg->num_fl + fl;
	arg->num_di = (long long)arg->num_fl;
	arg->sign = (arg->num_fl < 0) ? '-' : '+';
	arg->num_fl -= arg->num_di;
	ft_itoa_printf(ft_pf, arg);
}

void			float_mwidth(t_fpf *ft_pf, t_arg *arg)
{
	int			i;
	int			tmp;

	tmp = (arg->sign == '-') ? 2 : 1;
	if ((arg->sign == '+' && ft_pf->flags[1] == '1') || (ft_pf->flags[4] == '1'
		&& ft_pf->flags[0] == '1'))
		tmp = 2;
	i = (ft_pf->PREC == 0 && ft_pf->pr_sign == 'Y' && ft_pf->flags[2] != '1');
	ft_pf->mwidth = (ft_pf->mwidth > arg->strlen + (tmp - i) + ft_pf->precision)
		? ft_pf->mwidth - (arg->strlen + (tmp - i) + ft_pf->precision) : 0;
	tmp = -1;
	if (ft_pf->mwidth > 0)
	{
		if (!(arg->size_w = (char*)malloc(sizeof(char) * (ft_pf->mwidth + 1))))
			exit(1);
		while (++tmp < ft_pf->mwidth)
			arg->size_w[tmp] = ' ';
		arg->size_w[ft_pf->mwidth] = '\0';
	}
	else
	{
		if (!(arg->size_w = (char*)malloc(sizeof(char))))
			exit(1);
		arg->size_w[0] = '\0';
	}
}

void			float_right_side(t_fpf *ft_pf, t_arg *arg)
{
	int			i;

	i = -1;
	arg->num_fl = (arg->num_fl < 0) ? -arg->num_fl : arg->num_fl;
	while (++i < ft_pf->precision)
	{
		arg->num_fl *= 10;
		arg->f[i] = (long long)arg->num_fl + '0';
		arg->num_fl -= (long long)arg->num_fl;
	}
	if (arg->num_di > 0 && ft_pf->precision >= 20
		&& arg->num_fl >= 0.0110000000000100100 && arg->f[i - 1] < '9')
		arg->f[i - 1]++;
}

void			float_flags(t_fpf *ft_pf, t_arg *arg, int *len)
{
	int			test;

	test = 0;
	if (ft_pf->flags[0] != '1')
		float_not_minus_side(len, arg, ft_pf, test);
	else
		float_minus_side(len, arg, ft_pf, test);
}
