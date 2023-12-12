#define _XOPEN_SOURCE 700

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>



int pid = 0;

void handler( int num)
{
        write(STDOUT_FILENO, "\nAAHHH\n", 7);
        kill(pid, SIGTERM);

}
int main ()
{
        struct sigaction sa;
        int pid;

        pid = getpid();
        sa.sa_handler = handler;
        sigaction(SIGUSR1, &sa, NULL);

        while(1)
        {
                printf("Bora bora %d\n", pid);
                pause();
        }
}