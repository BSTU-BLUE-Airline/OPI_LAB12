#include <iostream>
#include <fstream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");

    // Пользователь вводит город с клавиатуры
    std::cout << "Введите название города: ";
    std::string userCity;
    std::cin >> userCity;

    // Открываем файл для чтения
    std::ifstream inputFile("text.txt");

    // Проверяем, успешно ли открыт файл
    if (inputFile.is_open()) {
        std::string city, temperature;

        // Читаем файл построчно и ищем город
        while (inputFile >> city >> temperature) {
            // Если город найден, выводим информацию
            if (city == userCity) {
                std::cout << "Текущая температура в городе " << city << ": " << temperature << std::endl;
                return 0;  // Завершаем программу после вывода информации
            }
        }

        // Если город не найден, выводим сообщение
        std::cout << "Информация о погоде в городе " << userCity << " не найдена." << std::endl;

        // Закрываем файл после завершения чтения
        inputFile.close();
    }
    else {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
    }

    return 0;
}
