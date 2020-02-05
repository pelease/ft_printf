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

void			uint_execution(va_list ap, int *len, t_fpf *ft_pf)
{
	
}