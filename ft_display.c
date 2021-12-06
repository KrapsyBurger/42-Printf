#include "ft_printf.h"

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

int	ft_countnum(int a)
{
	int	j;
	unsigned int	i;

	j = 0;
	i = 1;
	if (a < 0)
		a *= -1;
	while (a / i > 0)
	{
		i *= 10;
		j++;
	}
	return (j);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_putstr(const char *s)
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