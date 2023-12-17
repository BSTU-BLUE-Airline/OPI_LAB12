#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    setlocale(LC_ALL, "English");

    // Запрашиваем у пользователя название города
    std::cout << "Enter the city name: ";
    std::string cityName;
    std::getline(std::cin, cityName);

    // Открываем файл для чтения
    std::ifstream inputFile("text.txt");

    // Проверяем, успешно ли открыт файл
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file for reading." << std::endl;
        return 1; // Возвращаем код ошибки
    }

    std::string line;

    bool cityFound = false;

    // Читаем файл построчно
    while (std::getline(inputFile, line)) {
        // Разбиваем строку на слова
        std::istringstream iss(line);
        std::string city;
        int temperature;

        // Считываем первое слово (название города)
        iss >> city;

        // Если название города совпадает с введенным пользователем
        if (city == cityName) {
            cityFound = true;

            // Считываем оставшуюся часть строки (температуру)
            if (iss >> temperature) {
                // Выводим информацию
                std::cout << "Temperature in the city " << city << ": " << temperature << " degrees" << std::endl;
            }
            else {
                // Если не удалось считать температуру, выводим сообщение об ошибке
                std::cerr << "Error reading temperature for the city " << city << std::endl;
            }

            // Завершаем цикл, так как нашли нужный город
            break;
        }
    }

    // Проверяем, был ли найден город
    if (!cityFound) {
        std::cerr << "Weather information for the city " << cityName << " not found." << std::endl;
    }

    // Закрываем файл после завершения чтения
    inputFile.close();

    return 0;
}
