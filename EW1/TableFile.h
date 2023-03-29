#pragma once
#include "Header.h"
#include "FileType.h"



class TableFIle : public FileType {
public:
    TableFIle() : FileType(), _name(" Table"), _row(0), _column(0), file_size(0.0), _extension(".xlsx") {
        _name += _extension;
    }
    TableFIle(const std::string& _name) : _name(_name + ".xlsx"), _row(6), _column(8) {
        file_size = ((_row * 10) + rand() % ((_column * 10) - ((_row * 10) + 1)));
    }

    virtual void display_table() const {
        //FileType::display();
        std::cout << "\n> Name: " << _name << "\n";
        std::cout << "  Type: " << _extension << "\n";
        std::cout << "  size: " << std::fixed << std::setprecision(1) << file_size << " kB" << std::endl;
    }

private:
    std::string _name;
    int _row;
    int _column;
    std::string _extension;
    double file_size;
};