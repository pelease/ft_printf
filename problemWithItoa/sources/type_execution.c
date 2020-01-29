/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:27:08 by pelease           #+#    #+#             */
/*   Updated: 2020/01/22 21:28:46 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			int_execution(va_list ap, int *len, t_fpf *ft_pf)
{
	t_arg		arg;
	int_type_and_modf(ap, ft_pf, &arg);
	int_precision(ft_pf, &arg);
	int_mwidth(ft_pf, &arg);
	int_flags(ft_pf, &arg, len);
	ft_strdel(&arg.size_pr);
	ft_strdel(&arg.size_w);
	ft_strdel(&arg.str);
}

// void			octa_execution(va_list ap, int *len, t_fpf *ft_pf)
// {
// 	int			i;
// 	unsigned char		c;
// 	unsigned short		sh;

// 	i = 4;
// 	while (--i >= 0)
// 	{
// 		if (ft_pf->modf[i] == '1')
// 			break ;
// 	}
// 	if (i != -1)
// 	{
// 		if (i == 0)
// 		{
// 			c = va_arg(ap, int);
// 			ft_pf->int_N = c;
// 		}
// 		else if (i == 1)
// 		{
// 			sh = va_arg(ap, int);
// 			ft_pf->int_N = sh;
// 		}
// 		else if (i == 2)
// 			ft_pf->int_N = va_arg(ap, unsigned long);
// 		else if (i == 3)
// 			ft_pf->int_N = va_arg(ap, unsigned long long);
// 	}
// 	else
// 		ft_pf->int_N = va_arg(ap, unsigned int);
// 	printf("%o\n", ft_pf->int_N);
// 	//ft_itoa_base
// 	*len += 1;
// 	//func(unsigned char = va_arg())
// }