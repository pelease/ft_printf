/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pelease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:29:07 by pelease           #+#    #+#             */
/*   Updated: 2019/09/30 18:10:23 by pelease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	unsigned char a;

	a = (unsigned char)c;
	if (a == ' ' || a == '\t' || a == '\n'
		|| a == '\v' || a == '\f' || a == '\r')
		return (1);
	else
		return (0);
}