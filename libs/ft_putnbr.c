#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	int div;
	int res;

	div = 1000000000;

	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb == -2147483648)
	{
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb == 0)
		ft_putchar('0');
	
	while (div > nb)
		div /= 10;

	while (div > 0)
	{
		res = nb / div;
		nb %= div;
		div /= 10;
		res += '0';
		ft_putchar(res);
	}
	
	ft_putchar('\n');
}
