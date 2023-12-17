#include <iostream>
#include <fstream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");

    // ������������ ������ ����� � ����������
    std::cout << "������� �������� ������: ";
    std::string userCity;
    std::cin >> userCity;

    // ��������� ���� ��� ������
    std::ifstream inputFile("text.txt");

    // ���������, ������� �� ������ ����
    if (inputFile.is_open()) {
        std::string city, temperature;

        // ������ ���� ��������� � ���� �����
        while (inputFile >> city >> temperature) {
            // ���� ����� ������, ������� ����������
            if (city == userCity) {
                std::cout << "������� ����������� � ������ " << city << ": " << temperature << std::endl;
                return 0;  // ��������� ��������� ����� ������ ����������
            }
        }

        // ���� ����� �� ������, ������� ���������
        std::cout << "���������� � ������ � ������ " << userCity << " �� �������." << std::endl;

        // ��������� ���� ����� ���������� ������
        inputFile.close();
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
    }

    return 0;
}
