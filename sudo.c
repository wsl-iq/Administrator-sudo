#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void RunAsAdministrator() {
    printf("Program requires Administrator privileges. Restarting...\n");
    execlp("sudo", "sudo", "/proc/self/exe", NULL);
}

int main() {
    if (geteuid() != 0) {
        RunAsAdministrator();
        return 0;
    }

    printf("Welcome, I'm Mohammed Al-Baqer\n");

    try {
    } catch (...) {
        printf("Failed to execute the program.\n");
        system("read -p 'Press Enter to exit...' var");
    }

    return 0;
}
