/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:36:20 by rakhsas           #+#    #+#             */
/*   Updated: 2023/01/23 13:45:06 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *c);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;
	int		error;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				error = kill(pid, SIGUSR2);
			else
				error = kill(pid, SIGUSR1);
			if (error == -1)
			{
				ft_putstr("\033[31m transmission invalid !!! \033[0m\n");
				exit(EXIT_FAILURE);
			}
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr("\x1B[03m\x1B[33m INVALID ARGUMENTS!!");
		exit(EXIT_FAILURE);
	}
	if (ft_atoi(argv[1]) > 0)
		mt_kill(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr("\033[31m INVALID PID!! \033[0m\n");
	return (0);
}
