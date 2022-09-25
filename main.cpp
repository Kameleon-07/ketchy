#include <iostream>
#include "os_info.h"
#include "colors.h"

int main() {
    const int SECONDS_IN_DAY = 86400;
    const int SECONDS_IN_HOUR = 3600;
    const int SECONDS_IN_MINUTE = 60;
    
    int uptime = get_uptime();

    const int days = uptime / SECONDS_IN_DAY;
    uptime -= days * SECONDS_IN_DAY;
    const int hours = uptime / SECONDS_IN_HOUR;
    uptime -= hours * SECONDS_IN_HOUR;
    const int minutes = uptime / SECONDS_IN_MINUTE;

    const std::string kernel = get_kernel();
    const std::string distro_name = get_distro_name();
    const std::string user = get_user();
    const std::string shell = get_shell();

    std::cout << RED << "User " << GRAY << "-> " << RESET << user << YELLOW << "\nKernel " << GRAY << "-> " << RESET << kernel << BLUE << "\nDistro " << GRAY << "-> " << RESET << distro_name << GREEN << "\nUptime " << GRAY << "-> " << RESET << days << "D " << hours << "H " << minutes << "M" << MAGENTA << "\nShell " << GRAY << "-> " << RESET << shell << std::endl;

    return 0;
}