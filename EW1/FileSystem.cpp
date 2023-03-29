#include "Header.h"
#include "FileSystem.h"
#include "utility.h"

FileSystem::FileSystem() : m_current_directory("D:\\") {
    this->show_command_usage();
}

void FileSystem::make_command(std::string _command) {
    std::vector<std::string> command_list = string_split(_command, " ");

    if (command_list.size() > 4) {
        std::cout << u8"- Перевищена кількість аргументів." << "\n";
    }
    //-------------------------------------------------------------------

    if (command_list[0] == "mkdir") {
        this->make_folder(command_list[1]);
    }
    
    //---------------------------------------------------------------------

    if (command_list[0] == "mk") {
        this->make_file(command_list[1]);
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "find") {
        //TODO: operator<<
        this->find_folder(command_list[1]);
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "renfolder") {
        this->rename_folder(command_list[1], command_list[2]);
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "renfile") {
        this->rename_file(command_list[1], command_list[2]);
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "rmfolder") {
        this->remove_folder(command_list[1]);
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "rmfile") {
        this->remove_file(command_list[1]);
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "dir") {
        this->display();
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "help") {
        this->show_command_usage();
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "cd") {
        change_directory(command_list[1]);
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "cd:file") {
        this->display_image();
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "clean") {
        this->clean();
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "copy") {
        this->copy_folder(command_list[1]);
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "erase") {
        this->erase();
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "size") {
        this->size();
    }

    //---------------------------------------------------------------------

    if (command_list[0] == "exit") {
        std::cout << u8"\n- Ви завершили роботу з файловим менеджером!\n  До наступної зустрічі!)\n";
        m_isRunning = false;
    }
    // TODO add comand to change directory name
}

void FileSystem::show_command_usage() {

    std::cout << "\n"
        << "******************************\n"
        << std::setw(15) << std::left << "* COMMAND"     //Команда
        << std::setw(1) << std::left << "DESCRIPTION   *" //Опис
        << "\n******************************\n"
        << std::endl;

    //-> cd || cd f_name
    std::cout
        << std::setw(9) << " cd"
        << std::setw(5) << "->"
        << std::setw(50) << u8" Звернення до файлу або папки.\n";

    std::cout
        << std::setw(9) << " clean"
        << std::setw(5) << "->"
        << std::setw(50) << u8" Очистка консолі." << "\n";

    //-> copy f_name new_name || copy f_name.f new_name
    std::cout
        << std::setw(9) << " copy"
        << std::setw(5) << "->"
        << std::setw(60) << u8" Копіює папку або файл." << "\n";

    //-> dir || dir f_name
    std::cout
        << std::setw(9) << " dir"
        << std::setw(5) << "->"
        << std::setw(60) << u8" Виведення списку папок і файлів на диску." << "\n";

    std::cout
        << std::setw(9) << " erase"
        << std::setw(5) << "->"
        << std::setw(60) << u8" Форматирує весь вміст." << "\n";

    //-> find f_name || find f_name.f
    std::cout
        << std::setw(9) << " find"
        << std::setw(5) << "->"
        << std::setw(60) << u8" Пошук вказанного файла або папки." << "\n";

    std::cout
        << std::setw(9) << " move"
        << std::setw(5) << "->"
        << std::setw(60) << u8" Переміщує папку або файл." << "\n";

    //-> mk f_name || mk f_name.f
    std::cout
        << std::setw(9) << " mk"
        << std::setw(5) << "->"
        << std::setw(50) << u8" Створює файл." << "\n";

    std::cout
        << std::setw(9) << " mkdir"
        << std::setw(5) << "->"
        << std::setw(50) << u8" Створює папку." << "\n";

    //-> rm f_name || rm f_name.f
    std::cout
        << std::setw(9) << " rmfolder"
        << std::setw(5) << "->"
        << std::setw(50) << u8" Видаляє папку." << "\n";

    std::cout
        << std::setw(9) << " rmfile"
        << std::setw(5) << "->"
        << std::setw(50) << u8" Видаляє файл." << "\n";

    //-> ren f_name new_name || ren f_name.f new_name.f
    std::cout
        << std::setw(9) << " renfolder"
        << std::setw(5) << "->"
        << std::setw(50) << u8" Перейменовує папку." << "\n";

    std::cout
        << std::setw(9) << " renfile"
        << std::setw(5) << "->"
        << std::setw(50) << u8" Перейменовує файл." << "\n";

    std::cout
        << std::setw(9) << " size"
        << std::setw(5) << "->"
        << std::setw(50) << u8" Загальний вміст папок та файлів." << "\n";

    std::cout
        << std::setw(9) << " exit"
        << std::setw(5) << "->"
        << std::setw(60) << u8" Завершує роботу програми." << "\n";

    std::cout << u8"\n> Для повторного ввиклику команд, наберіть \"help\"." << std::endl;
}

void FileSystem::make_folder(std::string& _name) {
    auto result = m_disk.find(_name);
    if (result != m_disk.end()) {
        std::cout << u8"\n- Папка з назвою " << _name << u8" вже існує.\n";
    }
    else {
        FolderNode tmp;
        //        tmp.setName(m_current_directory + '\\' + _name);
        tmp.setName(_name);
        m_disk.insert(std::make_pair((this->getMCurrentDirectory() + _name), tmp));
        //        m_disk.insert(std::make_pair(tmp.getName(), tmp));
        //        m_disk.insert({tmp.getName(), tmp}); // элегантное решение через initial list
        std::cout << u8"\n- Папка " << _name << u8" була створена.\n";
    }
}

void FileSystem::make_file(std::string& _name)
{
    auto result = m_disk.find(_name);
    if (result != m_disk.end()) {
        std::cout << u8"\n- Файл з назвою " << _name << u8" вже існує.\n";
    }
    else {
        FolderNode tmp;
        std::string _choice;
        std::cout << u8"\n- Оберіть тип файлу який буде використаний для створення:\n1.Image\n2.Text\n3.Table\n";
        std::getline(std::cin, _choice);
        if (_choice == "Image") {
            tmp.setName(_name);
            m_disk.insert(std::make_pair((this->getMCurrentDirectory() + _name), tmp));
            std::cout << u8"\n- Файл з назвою " << _name <<u8" та типом даних " << _choice << u8" був створеий.\n";
        }
        else if (_choice == "Text") {
            tmp.setName(_name);
            m_disk.insert(std::make_pair((this->getMCurrentDirectory() + _name), tmp));
            std::cout << u8"\n- Файл з назвою " << _name << u8" та типом даних " << _choice << u8" був створеий.\n";
        }
        else if (_choice == "Table") {
            tmp.setName(_name);
            m_disk.insert(std::make_pair((this->getMCurrentDirectory() + _name), tmp));
            std::cout << u8"\n- Файл з назвою " << _name << u8" та типом даних " << _choice << u8" був створеий.\n";
        }
        
    }
}

//->last method
FolderNode& FileSystem::find_folder(std::string& _name) {
    auto result = m_disk.find(this->getMCurrentDirectory() + '\\' + _name);
    if (result != m_disk.end()) {

        return result->second;
        std::cout << u8"\n- TODO: Показати вміст та атрибути папки або файлу.\n";
    }
    else {
        std::cout << u8"\n- Папка/Файл з назвою " << _name << u8" не знайдена.\n";
    }
}

void FileSystem::remove_folder(std::string& _name) {
    auto result = m_disk.find(this->getMCurrentDirectory() + _name);
    if (result != m_disk.end()) {
        m_disk.erase(result);
        std::cout << u8"\n- Папка " << _name << u8" була видалена.\n";
    }
    else {
        std::cout << u8"\n- Папка з назвою " << _name << u8" не знайдена.\n";
    }
}

void FileSystem::remove_file(std::string& _name)
{
    auto result = m_disk.find(this->getMCurrentDirectory() + _name);
    if (result != m_disk.end()) {
        m_disk.erase(result);
        std::cout << u8"\n- Файл " << _name << u8" був видалений.\n";
    }
    else {
        std::cout << u8"\n- Файл з назвою " << _name << u8" не знайдений.\n";
    }
}

void FileSystem::rename_folder(std::string& _name, std::string& new_name) 
{
    FolderNode tmp;
    auto result = m_disk.find(this->getMCurrentDirectory() + _name);
    if (result!=m_disk.end()) {
        m_disk.erase(result);
       
        tmp.setName(new_name);
        m_disk.insert(std::make_pair((this->getMCurrentDirectory() + new_name), tmp));
        //m_disk.insert({ (this->getMCurrentDirectory() + new_name), tmp });
        std::cout << u8"\n- Папка з назвою " << _name << u8" перейменовано на "<<new_name<<"\n";
    }
    else {
        std::cout << u8"\n- Папка з назвою " << _name << u8" не знайдена.\n";
    }
}

void FileSystem::rename_file(std::string& _name, std::string& new_name)
{
    FolderNode tmp;
    auto result = m_disk.find(this->getMCurrentDirectory() + _name);
    if (result != m_disk.end()) {
        m_disk.erase(result);

        tmp.setName(new_name);
        //m_disk.insert(std::make_pair((this->getMCurrentDirectory() + new_name), tmp));
        m_disk.insert({ (this->getMCurrentDirectory() + new_name), tmp });
        std::cout << u8"\n- Файл з назвою " << _name << u8" перейменовано на " << new_name << "\n";
    }
    else {
        std::cout << u8"\n- Файл з назвою " << _name << u8" не знайдений.\n";
    }
}

void FileSystem::copy_folder(std::string& _name)
{
    /*std::map<std::string, FolderNode> m_disk1;
    m_disk1.insert(m_disk.begin(), m_disk.end());
    for (const auto copy : m_disk1) {
        std::cout<<copy.second;
    }*/
}

void FileSystem::change_directory(std::string& _folder) {
    std::string _file;
    std::string search_name = this->m_current_directory + _folder;
    std::string search_name1 = this->m_current_directory + _file;
    auto search = m_disk.find(search_name);
    auto search1 = m_disk.find(search_name1);
    if (search_name1=="") {
        this->display_image();

    }
    else {
        if (_folder == "..")
        {
            std::vector<std::string> vec_name = string_split(this->m_current_directory, "\\");
            std::string new_name;
            for (int i = 0; i < vec_name.size() - 1; i++)
            {
                new_name += vec_name[i] + "\\";
            }
        }
        else if (search == m_disk.end()) {
            std::cout << u8"\n- Сочатку створіть файл або папку!" << std::endl;
        }
        else {
            std::string new_name = this->m_current_directory + (_folder + "\\");
            setMCurrentDirectory(new_name);
        }
    }
}

void FileSystem::display() const {
    std::cout << u8"\n- Вміст папки " << this->getMCurrentDirectory() << "\n";
    for (const auto& iter : m_disk) {
        if (iter.first.find(getMCurrentDirectory()) != std::string::npos) {
            std::cout << iter.second.getName() << "\n";
        }
    }
}

void FileSystem::display_image() const
{
    ImageFile::display_image();
}

void FileSystem::display_table() const
{
    TableFIle::display_table();
}

void FileSystem::display_text() const
{
    TextFile::display_text();
}

void FileSystem::clean()
{
    std::system("cls");
}

void FileSystem::erase()
{
    m_disk.clear();
}

void FileSystem::size()
{
    std::cout<< u8"\n- Файловий менеджер містить "<<m_disk.size()<<u8" Папок та Файлів!\n";
}

const std::string& FileSystem::getMCurrentDirectory() const {
    return m_current_directory;
}

void FileSystem::setMCurrentDirectory(const std::string& mCurrentDirectory) {
    m_current_directory = mCurrentDirectory;
}