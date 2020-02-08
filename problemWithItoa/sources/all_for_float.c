#include "../include/ft_printf.h"

void			float_left_side(va_list ap, t_fpf *ft_pf, t_arg *arg)
{
	ft_bzero((void*)arg->f, 50);
	if (ft_pf->flags[5] == '1')
		arg->num_fl = va_arg(ap, long double);
	else
		arg->num_fl = va_arg(ap, double);
	arg->num_di = (LLI)arg->num_fl;
	ft_pf->precision = (ft_pf->pr_sign == 'N') ? 6 : ft_pf->precision;
	arg->num_fl -= arg->num_di;
	arg->num_fl = (arg->num_fl < 0) ? -arg->num_fl : arg->num_fl;
}

void			float_mwidth(t_fpf *ft_pf, t_arg *arg)
{
	int			i;
	int			tmp;

	tmp = (arg->sign == '-') ? 2 : 1;
	if ((arg->sign == '+' && ft_pf->flags[1] == '1') || (ft_pf->flags[4] == '1'
		&& ft_pf->flags[0] == '1'))
		tmp = 2;
	i = (ft_pf->PREC == 0 && ft_pf->pr_sign == 'Y' && ft_pf->flags[2] != '1');
	ft_pf->mwidth = (ft_pf->mwidth > arg->strlen + (tmp - i) + ft_pf->precision)
		? ft_pf->mwidth - (arg->strlen + (tmp - i) + ft_pf->precision) : 0;
	tmp = -1;
	if (ft_pf->mwidth > 0)
	{
		if (!(arg->size_w = (char*)malloc(sizeof(char) * (ft_pf->mwidth + 1))))
			exit(1);
		while (++tmp < ft_pf->mwidth)
			arg->size_w[tmp] = ' ';
		arg->size_w[ft_pf->mwidth] = '\0';
	}
	else
	{
		if (!(arg->size_w = (char*)malloc(sizeof(char))))
			exit(1);
		arg->size_w[0] = '\0';
	}
}

void			float_right_side(t_fpf *ft_pf, t_arg *arg)
{
	int			i;
	LD			fl;
	
	fl = 5.0;
	i = -1;
	while (++i < ft_pf->precision + 1)
		fl /= 10;
	arg->num_fl += fl;
	if ((LLI)arg->num_fl == 1)
	{	
		arg->num_di = (arg->num_di < 0) ? arg->num_di - 1
			: arg->num_di + 1;
		arg->num_fl -= 1;
	}
	i = -1;
	while (++i < ft_pf->precision)
	{
		arg->num_fl *= 10;
		arg->f[i] = (LLI)arg->num_fl + '0';
		arg->num_fl -= (LLI)arg->num_fl;
	}
	ft_itoa_printf(ft_pf, arg);
}

void			float_flags(t_fpf *ft_pf, t_arg *arg, int *len)
{
	if (ft_pf->flags[0] != '1')
		float_not_minus_side(len, arg, ft_pf);
	else
		float_minus_side(len, arg, ft_pf);
}
