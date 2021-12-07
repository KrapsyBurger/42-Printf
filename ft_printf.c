/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfascia <nathanfascia@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:52:54 by nfascia           #+#    #+#             */
/*   Updated: 2021/12/07 00:53:10 by nfascia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(s);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			j--;
			j += ft_final_display(s[++i], args) - 1;
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (j);
}
