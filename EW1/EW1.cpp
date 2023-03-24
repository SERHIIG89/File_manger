#pragma once
#include "Header.h"
#include "FileSystem.h"
#include "utility.h"
#include "ImageFile.h"


int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));
       
    FileSystem file_manager;
    std::string command;

    file_manager.size();
    while (file_manager.m_isRunning) {
        std::cout << u8"\n>>> Введіть команду:";
        std::getline(std::cin, command);
        if (command == "cd -imfile") {
            file_manager.display_image();
        }
        else if (command == "cd -textfile") {
            file_manager.display_text();
        }
        else if (command == "cd -tablefile") {
            file_manager.display_table();
        }
        
        file_manager.make_command(command);
        
    }
    file_manager.size();
    return 0;
}