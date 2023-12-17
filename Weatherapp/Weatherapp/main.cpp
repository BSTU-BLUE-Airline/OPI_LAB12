#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <algorithm>
#include <windows.h>

std::wstring toLowerCase(const std::wstring& wstr) {
    std::wstring lowerStr = wstr;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::towlower);
    return lowerStr;
}
  
int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    std::wifstream inputFile("text.txt");

    if (!inputFile.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
        return 1;
    }

    std::wcout << L"������� �������� ������: ";
    std::wstring userInput;
    std::getline(std::wcin, userInput);

    std::wstring userInputLower = toLowerCase(userInput);

    std::wstring line;
    bool cityFound = false;

    while (std::getline(inputFile, line)) {
        size_t pos = line.find(L':');
        if (pos != std::wstring::npos) {
            std::wstring city = line.substr(0, pos);
            std::wstring temperature = line.substr(pos + 1);

            std::wstring cityLower = toLowerCase(city);

            // ������� ��������� ��� �������
            std::wcout << L"�� �����: ����� - " << city << L", ����������� - " << temperature << std::endl;

            if (cityLower == userInputLower) {
                std::wcout << L"����������� � ������ " << city << L": " << temperature << std::endl;
                cityFound = true;
                break;
            }
        }
    }

    if (!cityFound) {
        std::wcout << L"����� �� ������." << std::endl;
    }

    inputFile.close();

    return 0;
}