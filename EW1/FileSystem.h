#pragma once
#include "FolderNode.h"
#include "ImageFile.h"
#include "TableFile.h"
#include "TextFile.h"



class FileSystem : public ImageFile, public TableFIle, public TextFile {
public:
    FileSystem();
    void make_command(std::string command); //Зробити команду
    void show_command_usage();  //Показати використання команди
    // make folder/directory -> mk
    void make_folder(std::string& name);  //Створити папку
    // make file, write type after dot // touch
    void make_file(std::string& name);
    // find folder/directory -> find
    FolderNode& find_folder(std::string& name);
    // remove folder/directory -> rm
    void remove_folder(std::string& name);
    // rename folder/directory -> ren
    void remove_file(std::string& name);

    void rename_folder(std::string& _name, std::string& _new_name);
    // go to next folder/directory cd update m_current_directory += folder_name

    void rename_file(std::string& _name, std::string& _new_name);

    void copy_folder(std::string& _name);

    void change_directory(std::string& _folder);

    // show all content in current directory ls
    void display() const;
    void display_image() const override;
    void display_table() const override;
    void display_text() const override;

    void clean();

    void erase();

    void size();

    // call display method of file info
    void display_file_content(std::string file_name);

    // cdn
    void change_directory_name(std::string name, std::string new_name);
    // cfn
    bool m_isRunning = true;
    [[nodiscard]] const std::string& getMCurrentDirectory() const;
    void setMCurrentDirectory(const std::string& mCurrentDirectory);

    //    friend std::ostream& operator<<(std::ostream& out, const FolderNode& f_node);

private:
    std::string m_current_directory;  //Поточний каталог
    std::map<std::string, FolderNode> m_disk;

};
