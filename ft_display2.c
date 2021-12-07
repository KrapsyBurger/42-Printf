/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:47:57 by nfascia           #+#    #+#             */
/*   Updated: 2021/12/07 00:52:31 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	denom;
	long			nbr2;
	unsigned int	j;

	base_len = ft_strlen(base);
	denom = 1;
	nbr2 = nbr;
	j = 0;
	if (nbr2 < 0)
	{
		return (0);
	}
	while (nbr2 / denom / base_len > 0)
	{
		denom *= base_len;
	}
	while (denom > 0)
	{
		j++;
		ft_putchar(base[nbr2 / denom % base_len]);
		denom /= base_len;
	}
	return (j);
}

unsigned int	ft_put_pointer(void *a, char *base)
{
	unsigned int		base_len;
	unsigned long long	denom;
	void				*nbr2;
	unsigned int		j;

	base_len = ft_strlen(base);
	denom = 1;
	nbr2 = a;
	j = 0;
	ft_putstr("0x");
	if (nbr2 < 0)
	{
		return (0);
	}
	while ((unsigned long long)nbr2 / denom / base_len > 0)
	{
		denom *= base_len;
	}
	while (denom > 0)
	{
		j++;
		ft_putchar(base[(unsigned long long)nbr2 / denom % base_len]);
		denom /= base_len;
	}
	return (j + 2);
}

unsigned int	ft_final_display(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, const char *)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_put_pointer(va_arg(args, void *), "0123456789abcdef"));
	return (ft_putchar(c));
}
