// Write a C program to implement sleep function using alarm and pause.
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for SIGALRM
void handle_alarm(int sig) {
    // Do nothing, just return to interrupt the pause()
}

// Custom sleep function
unsigned int my_sleep(unsigned int seconds) {
    struct sigaction sa, old_sa;
    unsigned int unslept;

    // Set up the new signal handler
    sa.sa_handler = handle_alarm;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, &old_sa);

    // Set the alarm and wait
    alarm(seconds);
    pause();

    // Cancel any remaining alarm and get the unslept time
    unslept = alarm(0);

    // Restore the old signal handler
    sigaction(SIGALRM, &old_sa, NULL);

    return unslept;
}

int main() {
    printf("Sleeping for 5 seconds...\n");
    my_sleep(5);
    printf("Awake!\n");
    return 0;
}