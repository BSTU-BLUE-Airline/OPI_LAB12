#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    setlocale(LC_ALL, "English");

    while (true) {
       
        std::cout << "Enter the city name: ";
        std::string cityName;
        std::getline(std::cin, cityName);

        
        std::ifstream inputFile("text.txt");

       
        if (!inputFile.is_open()) {
            std::cerr << "Failed to open the file for reading." << std::endl;
            return 1; 
        }

        std::string line;

        bool cityFound = false;

       
        while (std::getline(inputFile, line)) {
            
            std::istringstream iss(line);
            std::string city;
            int temperature;

          
            iss >> city;

          
            if (city == cityName) {
                cityFound = true;

              
                if (iss >> temperature) {
                  
                    std::cout << "Temperature in the city " << city << ": " << temperature << " degrees" << std::endl;
                }
                else {
                   
                    std::cerr << "Error reading temperature for the city " << city << std::endl;
                }

               
                break;
            }
        }

        
        if (!cityFound) {
            std::cerr << "Weather information for the city " << cityName << " not found." << std::endl;
        }

       
        inputFile.close();

        
        std::cout << "Do you want to check another city? (yes/no): ";
        std::string answer;
        std::getline(std::cin, answer);

        if (answer != "yes") {
            break; 
        }
    }

    return 0;
}

