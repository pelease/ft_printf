/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:52:10 by pelease           #+#    #+#             */
/*   Updated: 2020/01/22 14:56:46 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <inttypes.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h> 

typedef struct		s_fpf
{
	char 			flags[5];
	int				mwidth;
	int				precision;
	char			modf[5];
	char			type;
}					t_fpf;

typedef struct		s_arg
{
	char			*size_w;
	char			*size_pr;
	intmax_t		int_N;
	int				strlen;
	char			*str;
	char			sign;
}					t_arg;

int					ft_printf(const char *format, ...);
int					buffer(char **f, va_list ap, int *len);

void				flags_option(char **f, t_fpf *ft_pf);
void				mwidth_option(char **f, t_fpf *ft_pf);
void				precision_option(char **f, t_fpf *ft_pf);
void				modf_option(char **f, t_fpf *ft_pf);
void				type_option(char **f, va_list ap, int *len, t_fpf *ft_pf);

void				int_execution(va_list ap, int *len, t_fpf *ft_pf);
//void				octa_execution(va_list ap, int *len, t_fpf *ft_pf);

void				int_type_and_modf(va_list ap, t_fpf *ft_pf, t_arg *arg);
void				int_mwidth(t_fpf *ft_pf, t_arg *arg);
void				int_precision(t_fpf *ft_pf, t_arg *arg);

void				ft_itoa_printf(t_fpf *ft_pf, t_arg *arg);

#endif
