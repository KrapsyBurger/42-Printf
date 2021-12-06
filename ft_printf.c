#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


/*unsigned int	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
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

unsigned int	ft_putunsigned(unsigned int nb)
{
	unsigned long	a;
	unsigned long	nb2;
	unsigned int	j;

	a = 1;
	nb2 = nb;
	j = 0;
	if (nb2 < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		ft_putchar('0');
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
}*/

unsigned int	ft_display(char c, va_list args)
{
	if (c == 'c')
		return(ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, const char*)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));

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

/*int main()
{
	char *a;
	ft_putnbr(ft_printf("%p", a));
	return (0);
}*/
