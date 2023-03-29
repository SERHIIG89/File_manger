#pragma once
#include "Header.h"
#include "FileType.h"


class ImageFile : public FileType {
public:
    ImageFile() : FileType(),
        _name(" Image"), _width(0.0), _height(0.0), file_size(8.0), _extension(".jpeg") {
        _name += _extension;
    }
    ImageFile(const std::string& _name) : _name(_name + ".xlsx"), _width(1024), _height(860) {
        file_size = (_width + rand() % ((_height * 10) - (_width + 1)));
    }

    virtual void display_image() const
    {
        //FileType::display();
        std::cout << "\n> Name: " << _name << "\n";
        std::cout << "  Type: "<<_extension<<"\n";
        std::cout << "  size: " << std::fixed << std::setprecision(1) << file_size << " kB" << std::endl;
    }

private:
    std::string _name; //Назва файла
    int _width;  //Ширина
    int _height; //Висота
    std::string _extension;  //Розширення
    double file_size;  //Розмір файла

};
