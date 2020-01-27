#include "../include/ft_printf.h"

void			int_type_and_modf(va_list ap, t_fpf *ft_pf, t_arg *arg)
{
	int			i;

	i = 4;
	while (--i >= 0)
	{
		if (ft_pf->modf[i] == '1')
			break ;
	}
	if (i != -1)
	{
		if (i == 0)
			arg->int_N = (char)va_arg(ap, int);
		else if (i == 1)
			arg->int_N = (short)va_arg(ap, int);
		else if (i == 2)
			arg->int_N = va_arg(ap, long);
		else if (i == 3)
			arg->int_N = va_arg(ap, long long);
	}
	else
		arg->int_N = va_arg(ap, int);
	arg->str = ft_itoa(arg->int_N);
	arg->sign = (arg->str[0] == '-') ? '-' : '+';
	arg->sign == '-' ? arg->str++ : 0;
	arg->strlen = ft_strlen(arg->str);
}

void			int_precision(t_fpf *ft_pf, t_arg *arg)
{
	int			i;

	i = -1;
	if (arg->str[0] == '-')
		arg->strlen -= 1;
	if (ft_pf->precision > 0 && ft_pf->precision > arg->strlen)
	{
		ft_pf->precision -= arg->strlen;
		arg->size_pr = (char*)malloc(sizeof(char) * (ft_pf->precision + 1));
		while (++i < ft_pf->precision)
			arg->size_pr[i] = '0';
		arg->size_pr[ft_pf->precision] = '\0';
	}
	else
	{
		arg->size_pr = (char*)malloc(sizeof(char));
		arg->size_pr[0] = '\0';
	}
	if (arg->str[0] == '-')
		arg->strlen += 1;
	
}

void			int_mwidth(t_fpf *ft_pf, t_arg *arg)
{
	int			i;
	int			tmp;

	i = -1;
	tmp = 0;
	tmp = (arg->sign == '-') ? 1 : 0;
	//printf("\n%d\n%d\n", ft_pf->mwidth, arg->strlen + ft_pf->precision);
	if (ft_pf->mwidth > arg->strlen + ft_pf->precision)
		ft_pf->mwidth -= arg->strlen + tmp + ft_pf->precision;
	else
		ft_pf->mwidth = 0;
	if (ft_pf->mwidth > 0)
	{
		arg->size_w = (char*)malloc(sizeof(char) * (ft_pf->mwidth + 1));
		while (++i < ft_pf->mwidth)
			arg->size_w[i] = ' ';
		arg->size_w[ft_pf->mwidth] = '\0';
	}
	else
	{
		arg->size_w = (char*)malloc(sizeof(char));
		arg->size_w[0] = '\0';
	}
}