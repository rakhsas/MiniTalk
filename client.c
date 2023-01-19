
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

// This code is a program that sends a message in binary form to another process using the kill function. The message is passed as
//  the second argument to the program, and the process ID of the target process is passed as the first argument.

// The program first checks if there are enough arguments passed and if the message is not empty.
//  If the conditions are not met, the program exits with a status code of 1.

// Then, the program prints the length of the message and the text "Sent: " to the console.

// The program then sets up signal handlers for the SIGUSR1 and SIGUSR2 signals using the signal function. These signals will be used to send the message.

// The program then calls the mt_kill function, which takes the process ID and message as arguments. The function sends the message in binary form using the kill function,
//  sending a SIGUSR1 signal for a 0 and a SIGUSR2 signal for a 1. The function also sends 8 SIGUSR1 signals after the message to signal the end of the transmission.

// Finally, the program enters an infinite loop using the pause function, waiting for the target process to receive and process the message.
static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
