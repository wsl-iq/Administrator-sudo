#include <iostream>
#include <cstdlib>
#include <unistd.h>

void RunAsAdministrator() {
    std::cout << "Program requires Administrator privileges. Restarting...\n";
    execlp("sudo", "sudo", "/proc/self/exe", NULL);
}

int main() {
    if (geteuid() != 0) {
        RunAsAdministrator();
        return 0;
    }

    std::cout << "Welcome, I'm Mohammed Al-Baqer\n";

    try {
    } catch (const std::exception& e) {
        std::cerr << "Failed to execute the program: " << e.what() << std::endl;
        system("read -p 'Press Enter to exit...' var");
    }

    return 0;
}
