#include "Header.h"
#include "utility.h"


//*string_split - Розділення рядка                                     //розділювач
std::vector<std::string> string_split(std::string& s, const std::string& delimiter) {
    

    std::vector<std::string> tokens;
    std::string token;

    size_t pos = 0;  //* size_t - відображення об'єкта в бйтах
    while ((pos = s.find(delimiter)) != std::string::npos) //std::string::npos -  є статичним 
                                                           //постійним значенням члена з найбільшим
                                                           //можливим значенням для елемента 
                                                           //типу size_t 
    {
        token = s.substr(0, pos); //substr - повертає частину рядка
        tokens.push_back(token); //Добавляємо в вектор слово
        s.erase(0, pos + 1); //Видалення елемента з контейнера
    }
    tokens.push_back(s);

    return tokens;
}

