#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

void			ft_putchar(char c);
unsigned int	ft_putstr(const char *s);
unsigned int	ft_putnbr(int nb);
unsigned int	ft_display(char c, va_list args);
int 			ft_printf(const char *s, ...);
unsigned int	ft_strlen(const char *s);

#endif