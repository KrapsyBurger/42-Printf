#include "ft_printf.h"

unsigned int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

unsigned int	ft_putstr(const char *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
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
	long			a;
	long			nb2;
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
	if (nb2 == 0)
	{
		return (ft_putchar('0'));
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
}

unsigned int	ft_putnbr_base_pointer(unsigned long long a, char *base)
{
	unsigned int	base_len;
	unsigned int	denom;
	unsigned long long			nbr2;
	unsigned int	j;

	base_len = ft_strlen(base);
	denom = 1;
	nbr2 = a;
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