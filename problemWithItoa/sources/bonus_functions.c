#include "../include/ft_printf.h"

void			asterisk_precision(va_list ap, char **f, t_fpf *ft_pf)
{	
	ft_pf->precision = va_arg(ap, int);
	if (ft_pf->precision < 0)
	{
		ft_pf->precision = 0;
		ft_pf->pr_sign = 'N';
	}
	(*f)++;
}

void			asterisk_mwidth(va_list ap, char **f, t_fpf *ft_pf)
{
	ft_pf->mwidth = va_arg(ap, int);
	if (ft_pf->mwidth < 0)
	{
		ft_pf->mwidth *= -1;
		ft_pf->flags[0] = '1';
	}
	(*f)++;
}