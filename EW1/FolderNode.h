#pragma once
#include "Header.h"
#include "FileType.h"

class FolderNode {
public:
    FolderNode() {};

    [[nodiscard]] const std::string& getName() const {
        return this->_name;
    }
    void setName(const std::string& name) {
        this->_name = name;
    }

    void display() const {
        std::cout << _name << "\n";
    }


private:
    FileType file_type;
    std::string _name;

};
