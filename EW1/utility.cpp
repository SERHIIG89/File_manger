#include "Header.h"
#include "utility.h"


//*string_split - ��������� �����                                     //���������
std::vector<std::string> string_split(std::string& s, const std::string& delimiter) {
    

    std::vector<std::string> tokens;
    std::string token;

    size_t pos = 0;  //* size_t - ����������� ��'���� � �����
    while ((pos = s.find(delimiter)) != std::string::npos) //std::string::npos -  � ��������� 
                                                           //�������� ��������� ����� � ���������
                                                           //�������� ��������� ��� �������� 
                                                           //���� size_t 
    {
        token = s.substr(0, pos); //substr - ������� ������� �����
        tokens.push_back(token); //���������� � ������ �����
        s.erase(0, pos + 1); //��������� �������� � ����������
    }
    tokens.push_back(s);

    return tokens;
}

