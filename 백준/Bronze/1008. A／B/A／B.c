#include <unistd.h>

void	ft_write_integer(int nbr)
{
	char			*numbers;
	unsigned int	nbr_unsigned;

	numbers = "0123456789";
	if (nbr < 0)
		write(1, "-", 1);
	nbr_unsigned = nbr > 0 ? nbr : -nbr;
	if (nbr_unsigned >= 10)
		ft_write_integer(nbr / 10);
	write(1, numbers + (nbr_unsigned % 10), 1);
}

void	ft_write_fracional(double nbr)
{
	nbr = nbr > 0 ? nbr : -nbr;
	nbr -= (int)nbr;
	while (nbr > 0)
	{
		nbr *= 10;
		ft_write_integer((int)nbr);
		nbr -= (int)nbr;
	}
}

void	ft_putnbr(double nbr)
{
	ft_write_integer((int)nbr);
	if (nbr - (int)nbr == 0)
		return ;
	write(1, ".", 1);
	ft_write_fracional(nbr);
}

int		main(void)
{
	char str[3];

	read(0, str, 3);
	ft_putnbr(((double)str[0] - '0') / ((double)str[2] - '0'));
}
