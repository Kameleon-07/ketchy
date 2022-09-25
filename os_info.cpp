#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

std::string get_distro_name() {
    std::ifstream os_release_file("/etc/os-release");

    if(!os_release_file.is_open()) {
        return "Some Linux System";
    } else {
        std::string first_line;
        getline(os_release_file, first_line);
        first_line.replace(0, 6, "");
        first_line.pop_back();
        return first_line;
    }
}

std::string get_kernel() {
    std::ifstream proc_version_file("/proc/version");

    if(!(proc_version_file.is_open())) {
        return "Unknown";
    } else {
        int space_counter = 0;
        const int KERNEL_NAME_SPACE_INDEX = 2;
        std::string kernel_name;

        std::string contents = std::string((std::istreambuf_iterator<char>(proc_version_file)), std::istreambuf_iterator<char>());

        for(int character_index = 0; character_index < contents.length(); character_index++) {
            if(contents[character_index] == ' ') {
                space_counter++;
            }

            if(space_counter == KERNEL_NAME_SPACE_INDEX) {
                for(int i = character_index + 1; i < contents.length(); i++) {
                    if(contents[i] == ' ') {
                        return kernel_name;
                    } else {
                        kernel_name += contents[i];
                    }
                }
            }
        }
    }
}

std::string get_user() {
    std::string user = getenv("USER");

    return user;
}

std::string get_shell() {
    std::string shell = getenv("SHELL");

    return shell;
}

int get_uptime() {
    std::ifstream proc_uptime_file("/proc/uptime");

    if(!(proc_uptime_file.is_open())) {
        return 0;
    } else {
        std::string uptime_str;
        
        std::string contents = std::string(std::istreambuf_iterator<char>(proc_uptime_file), std::istreambuf_iterator<char>());

        for(int char_idx = 0; char_idx < contents.length(); char_idx++) {
            if(contents[char_idx] == '.') {
                int uptime = stoi(uptime_str);

                return uptime;
            } else {
                uptime_str += contents[char_idx];
            }
        }
    }
}