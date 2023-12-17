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
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return 1;
    }

    std::wcout << L"Введите название города: ";
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

            // Добавим сообщение для отладки
            std::wcout << L"Из файла: Город - " << city << L", Температура - " << temperature << std::endl;

            if (cityLower == userInputLower) {
                std::wcout << L"Температура в городе " << city << L": " << temperature << std::endl;
                cityFound = true;
                break;
            }
        }
    }

    if (!cityFound) {
        std::wcout << L"Город не найден." << std::endl;
    }

    inputFile.close();

    return 0;
}