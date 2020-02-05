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

# define LLI long long int
# define ULLI unsigned long long int

# include <limits.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h> 

typedef struct		s_fpf
{
	char			flags[6];// 0->'-'; 1->'+'; 2->'#'; 3->'0'; 4->' '; 
	int				mwidth;
	char			pr_sign;
	int				precision;
	char			modf[6];
	char			type;
}					t_fpf;

typedef struct		s_arg
{
	char			*size_w;
	char			*size_pr;
	LLI				num_di;
	ULLI			num_u;
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
void				uint_execution(va_list ap, int *len, t_fpf *ft_pf);
//void				octa_execution(va_list ap, int *len, t_fpf *ft_pf);

void				int_type_and_modf(va_list ap, t_fpf *ft_pf, t_arg *arg);
void				int_mwidth(t_fpf *ft_pf, t_arg *arg);
void				int_precision(t_fpf *ft_pf, t_arg *arg);
void				int_flags(t_fpf *ft_pf, t_arg *arg, int *len);

void				ft_itoa_printf(t_fpf *ft_pf, t_arg *arg);

// void				all_conversion(t_fpf *ft_pf, t_arg *arg);
// void				octa_conversion(t_fpf *ft_pf, t_arg *arg);
// void				hex_conversion(t_fpf *ft_pf, t_arg *arg);

#endif
