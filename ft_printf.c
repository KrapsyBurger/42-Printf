#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


unsigned int	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int 	ft_putstr(const char *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 7);
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	if (s[0] == '\0')
	{
		return (0);
	}
	return (ft_strlen(s));
}


unsigned int	ft_putnbr(int nb)
{
	long	a;
	long	nb2;
	unsigned int	j;

	a = 1;
	nb2 = nb;
	j = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		j++;
	}
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 = -nb2;
		j++;
	}
	while (nb2 / a > 0)
	{
		a *= 10;
	}
	while (a > 1)
	{
		j++;
		a /= 10;
		ft_putchar((nb2 / a) % 10 + '0');
	}
	return (j);
}


unsigned int	ft_display(char c, va_list args)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
		return (1);
	}
	else if (c == 's')
	{
		return (ft_putstr(va_arg(args, const char*)));
	}	
	else if (c == 'u' && (unsigned int)c > 0)
	{
		return (ft_putnbr(va_arg(args, unsigned int)));
	}	
	else if (c == 'i' || c == 'd')
	{
		return (ft_putnbr(va_arg(args, int)));
	}
	return (0);
}


int ft_printf(const char *s, ...)
{
	va_list args;
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
			j += ft_display(s[++i], args) - 1;
			i++;;
		}
		ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (j);
}

int main()
{
	//ft_putnbr(ft_printf("%u", -1));
	printf("\n");
	printf("%u", -1);
	return (0);
}
