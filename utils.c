/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:42:22 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/23 13:45:33 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (i[c])
	{
		write(1, &i[c], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sym;
	long	res;

	i = 0;
	sym = 1;
	res = 0;
	while ((i[str] == ' ') || (i[str] >= '\t' && i[str] <= '\r'))
		i++;
	if (i[str] == '-')
		sym *= -1;
	if (i[str] == '+' || i[str] == '-')
		i++;
	while (i[str] && (i[str] >= '0' && i[str] <= '9'))
	{
		if (res * sym > 2147483647)
			return (-1);
		else if (res * sym < -2147483648)
			return (0);
		else
			res = res * 10 + (i[str] - '0');
		i++;
	}
	return (sym * res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (*s == 0)
		return (0);
	while (i[s])
		i++;
	return (i);
}
