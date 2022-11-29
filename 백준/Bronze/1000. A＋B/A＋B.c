#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char			*numbers;
	unsigned int	nbr_unsigned;

	numbers = "0123456789";
	if (nbr < 0)
		write(1, "-", 1);
	nbr_unsigned = nbr > 0 ? nbr : -nbr;
	if (nbr >= 10)
		ft_putnbr(nbr_unsigned / 10);
	write(1, numbers + (nbr_unsigned % 10), 1);
}

int		main(void)
{
	char	str[3];

	read(0, str, 3);
	ft_putnbr(str[0] - '0' + str[2] - '0');
	return (0);
}
