/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:06:59 by pelease           #+#    #+#             */
/*   Updated: 2020/01/21 13:07:01 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	char		*f;

	f = (char*)format;
	len = 0;
	va_start(ap, format);
	while (*f)
	{
		if (*f == '%')
		{
			f++;
			if (buffer(&f, ap, &len) == 0)
				break ;
		}
		else
		{
			write(1, f, 1);
			len++;
		}
		f++;
	}
	va_end(ap);
	return (len);
}

int				buffer(char **f, va_list ap, int *len)
{
	t_fpf		ft_pf;

	ft_pf.mwidth = 0;
	ft_pf.precision = 0;
	while (**f != '\0')
	{
		if (**f == '-' || **f == '+' || **f == '#' || **f == '0' || **f == ' ')
			flags_option(f, &ft_pf);
		else if (**f >= '1' && **f <= '9')
			mwidth_option(f, &ft_pf);
		else if (**f == '.')
			precision_option(f, &ft_pf);
		else if (**f == 'h' || **f == 'l' || **f == 'L')
			modf_option(f, &ft_pf);
		else if (**f == 'd' || **f == 'i' || **f == 'o' || **f == 'u' ||
				**f == 'x' || **f == 'X' || **f == 'f' || **f == 'c' ||
				**f == 's' || **f == 'p' || **f == '%')
		{
			type_option(f, ap, len, &ft_pf);
			return (*len);
		}
		else
			(*f)++;
	}
	return (0);
}
