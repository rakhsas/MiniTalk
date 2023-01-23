/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:38:03 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/23 13:45:25 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "stdio.h"

void	ft_putstr(char *c);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

static void	action(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;

	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
			return ;
		ft_putchar(c);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
		pause();
	return (0);
}
