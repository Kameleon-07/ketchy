#include <iostream>
#include "os_info.h"

int main() {
    const int SECONDS_IN_DAY = 86400;
    const int SECONDS_IN_HOUR = 3600;
    const int SECONDS_IN_MINUTE = 60;
    
    const int uptime = get_uptime();

    const int days = uptime / SECONDS_IN_DAY;
    const int hours = uptime / SECONDS_IN_HOUR;
    const int minutes = uptime / SECONDS_IN_MINUTE;

    const std::string kernel = get_kernel();
    const std::string distro_name = get_distro_name();
    const std::string user = get_user();
    const std::string shell = get_shell();

    std::cout << "User -> " << user << "\nKernel -> " << kernel << "\nDistro -> " << distro_name << "\nUptime -> " << days << "D " << hours << "H " << minutes << "M" << "\nShell -> " << shell << std::endl;

    return 0;
}