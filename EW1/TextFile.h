#pragma once
#include "Header.h"
#include "FileType.h"


class TextFile : public FileType {
public:
    TextFile() : FileType(), _name("new text"), char_count(0), file_size(0.0), _extension(".txt") {
        _name += _extension;
    }
    TextFile(const std::string& _name) : _name(_name + ".txt"), char_count(58) {
        file_size = (char_count + rand() % ((char_count * 10) - (char_count + 1)));
    }

    virtual void display_text() const {
        //FileType::display();
        std::cout << "\n> Name: " << _name << "\n";
        std::cout << "  Type: " << _extension << "\n";
        std::cout << "  size: " << std::fixed << std::setprecision(1) << file_size << " kB" << std::endl;
    }

private:
    std::string _name;
    int char_count;
    std::string _extension;
    double file_size;



};
