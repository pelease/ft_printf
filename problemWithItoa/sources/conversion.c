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

#include "../include/ft_printf.h"

static void		uint_conversion(t_arg *arg)
{
	int			i;

	i = arg->strlen - 1;
	if (!(arg->str = (char*)malloc(sizeof(char) * (arg->strlen + 1))))
		exit(1);
	arg->str[arg->strlen] = '\0';
	while (i >= 0)
	{
		arg->str[i--] = (arg->num_u % 10) + '0';
		arg->num_u /= 10;
	}
}

// static void		octa_conversion(t_fpf *ft_pf, t_arg *arg)
// {
// 	int			i;
// 	ULLI		num;
// 	ULLI		tmp;

// 	num = 0;
// 	tmp = 1;
// 	i = 0;
// 	if (!(arg->str = (char*)malloc(sizeof(char) * (i + 1))))
// 		exit(1);
// 	while (arg->num_u != 0)
// 	{
// 		num = num + arg->num_u % 8 * tmp;
// 		tmp *= 10;
// 		arg->num_u /= 8;
// 		i++;
// 	}
// 	arg->num_u = num;

// }

// static void		hex_conversion(t_fpf *ft_pf, t_arg *arg)
// {
// 	char		str[] = "123456789abcdef";
// 	char		cap_str[] = "123456789ABCDEF";
// }

void			all_conversion(t_arg *arg)
{
	// if (ft_pf->type == 'o')
	// 	octa_conversion(ft_pf, arg);
	// else if (ft_pf->type == 'x' || ft_pf->type == 'X')
	// 	hex_conversion(ft_pf, arg);
	// else
		uint_conversion(arg);	
}

