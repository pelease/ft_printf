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

// void			all_conversion(t_fpf *ft_pf, t_arg *arg)
// {
// 	if (ft_pf->type != 'x' && ft_pf->type != 'X')
// 		octa_conversion(ft_pf, arg);
// 	else
// 		hex_conversion(ft_pf, arg);
// }

// void			octa_conversion(t_fpf *ft_pf, t_arg *arg)
// {
// 	ULLI		octa;
// 	ULLI		num;
// 	ULLI		tmp;

// 	num = 0;
// 	tmp = 1;
// 	octa = arg->ouxX_N;
// 	while (octa != 0)
// 	{
// 		num = num + octa % 8 * tmp;
// 		tmp *= 10; 
// 	}
// 	arg->ouxX_N = num;
// }

// void			hex_conversion(t_fpf *ft_pf, t_arg *arg)
// {
// 	char		strx[] = "123456789abcdef";
// 	char		strX[] = "123456789ABCDEF";
// }
