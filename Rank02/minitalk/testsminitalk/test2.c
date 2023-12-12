#define _XOPEN_SOURCE 700

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int pid_other = 0;
int pid = 0;

void handler( int num)
{
	write(STDOUT_FILENO, "\nNOOOO\n", 7);
	kill(pid_other, SIGUSR1);
	kill(pid, SIGTERM);
}
int main (int ac, char **av)
{
	struct sigaction sa;

	pid_other = atoi(av[1]);
	pid = getpid(); 
	sa.sa_handler = handler;
	sigaction(SIGINT, &sa, NULL);

	while(1)
	{
		write(STDOUT_FILENO, "Bora bora\n", 10);
		sleep(1);
	}

}