/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:01:02 by pelease           #+#    #+#             */
/*   Updated: 2020/01/29 16:01:05 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static LLI			delete_size(t_arg arg)
{
	LLI				i;

	i = 1;
	while (arg.int_N <= -10 || arg.int_N >= 10)
	{
		arg.int_N /= 10;
		i *= 10;
	}
	return (i);
}

static int			str_size(t_arg arg)
{
	int				i;

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

static int			itoa_output(t_arg *arg, LLI del_size)
{
	int				s_size;
	LLI				num;

	s_size = 0;
	num = arg->int_N;
	if (num < 0)
		num = num * (-1);
	while (del_size > 0)
	{
		arg->str[s_size] = (num / del_size) % 10 + '0';
		s_size++;
		del_size /= 10;
	}
	return (s_size);
}

void				ft_itoa_printf(t_arg *arg)
{
	int				a;
	int				s_size;
	long long int	del_size;

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
	s_size = itoa_output(arg, del_size);
	if (a == 1)
		arg->str[s_size - 1] = '8';
	arg->str[s_size] = '\0';
	arg->strlen = ft_strlen(arg->str);
}
