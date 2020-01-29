/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:37:11 by pelease           #+#    #+#             */
/*   Updated: 2020/01/23 21:37:18 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void			diou_conversion(t_fpf *ft_pf, t_arg *arg);
// {
// 	if (ft_pf->type == 'o' || ft_pf->type == 'u')
// 		arg->int_N = (unsigned long long int)arg->int_N;
// }

























static int		delete_size(t_arg arg)
{
	int i;

	i = 1;
	while (arg.int_N <= -10 || arg.int_N >= 10)
	{
		arg.int_N /= 10;
		i *= 10;
	}
	return (i);
}

static int		str_size(t_arg arg)
{
	int i;

	i = 0;
	if (arg.int_N == 0)
		i++;
	while (arg.int_N != 0)
	{
		arg.int_N /= 10;
		i++;
	}
	return (i);
}

static int		solving(t_arg *arg, intmax_t del_size)
{
	int			s_size;
	intmax_t	num;

	s_size = 0;
	num = arg->int_N;
	printf("num = %d\n", num);
	if (num < 0)
		num = num * (-1);
	printf("num = %d\n", num);
	while (del_size > 0)
	{
		arg->str[s_size] = (num / del_size) % 10 + '0';
		s_size++;
		del_size /= 10;
	}
	//printf("%c%s\n", arg->sign, arg->str);
	return (s_size);
}

void			ft_itoa_printf(t_fpf *ft_pf, t_arg *arg)
{
	int		a;
	int		s_size;
	int		del_size;

	// if (ft_pf->type != 'x' && ft_pf->type != 'X')
	// 	diou_conversion(ft_pf, arg);
	// else
	// 	hex_conversion();
	del_size = delete_size(*arg);
	a = 0;
	arg->sign = (arg->int_N < 0) ? '-' : '+';
	arg->str = (char*)malloc(sizeof(char) * (str_size(*arg) + 1));
	if (!arg->str)
		exit(1);
	if (arg->int_N == LLONG_MIN)
	{
		arg->int_N += 1;
		a = 1;
	}
	//printf("%d,\n %d,\n %d\n", arg->int_N, del_size, str_size(*arg));
	s_size = solving(arg, (intmax_t)del_size);
	if (a == 1)
		arg->str[s_size - 1] = '8';
	arg->str[s_size] = '\0';
	arg->strlen = ft_strlen(arg->str);
}
