#include "../include/ft_printf.h"

void			percent_execution(int *len, t_fpf *ft_pf)
{
	t_arg		arg;
	
	percent_mwidth(ft_pf, &arg);
	percent_flags(ft_pf, &arg, len);
	ft_strdel(&arg.size_w);
}

void			char_execution(va_list ap, int *len, t_fpf *ft_pf)
{
	t_arg		arg;

	char_type_and_mwidth(ap, ft_pf, &arg);
	char_flags(ft_pf, &arg, len);
	ft_strdel(&arg.size_w);
}

void			string_execution(va_list ap, int *len, t_fpf *ft_pf)
{
	t_arg		arg;

	string_type_precision(ap, ft_pf, &arg);
	string_mwidth(ft_pf, &arg);
	string_flags(ft_pf, &arg, len);
	ft_strdel(&arg.size_w);
}

// void			float_execution(va_list ap, int *len, t_fpf *ft_pf)
// {
// 	t_arg		arg;

// 	hex_type_and_modf(ap, ft_pf, &arg);
// 	int_precision(ft_pf, &arg);
// 	hex_mwidth(ft_pf, &arg);
// 	hex_flags(ft_pf, &arg, len);
// 	ft_strdel(&arg.size_pr);
// 	ft_strdel(&arg.size_w);
// 	ft_strdel(&arg.str);
// }
