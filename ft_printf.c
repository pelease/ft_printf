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

#include "ft_printf.h"
#include "./libft/libft.h"

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
			buffer(&f, ap, &len);
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

	while (**f != '\0')
	{
		if (**f == '-' || **f == '+' || **f == '#' || **f == '0' || **f == ' ')
			flags_option(f, &ft_pf);
		else if (**f >= '1' && **f <= '9')
			mwidth_option(f, &ft_pf);
		else if (**f == '.')
			precision_option(f, &ft_pf);
		// else if (**f == 'h' || **f == 'l' || **f == 'L')
		// 	modf_option(f, &ft_pf);
		else if (**f == 'd' || **f == 'i' || **f == 'o' || **f == 'u' ||
				**f == 'x' || **f == 'X' || **f == 'f' || **f == 'c' ||
				**f == 's' || **f == 'p')
		{
			type_option(f, ap, len, &ft_pf);
			return (*len);
		}
		else
			(*f)++;
	}
	return (0);
}

void			flags_option(char **f, t_fpf *ft_pf)
{
	int			i;

	i = 0;
	while (i < 5)
		ft_pf->flags[i++] = '0';
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
}

void			mwidth_option(char **f, t_fpf *ft_pf)
{
	int 		x;
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
	printf("%d\n", ft_pf->precision);
}

// void			modf_option(char **f, t_fpf *ft_pf)
// {

// }

void			type_option(char **f, va_list ap, int *len, t_fpf *ft_pf)
{
	int 		x;
	
	if (**f == 'd')
		x = va_arg(ap, int);
	ft_pf->modf[0] = '1';
	*len = ft_pf->modf[0];

}

int				main(void)
{
	int			a;

	a = 5;
	ft_printf("%798.13.12.d", a);
	return (0);
}
