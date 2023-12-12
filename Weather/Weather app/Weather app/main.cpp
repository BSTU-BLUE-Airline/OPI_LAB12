#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

const std::string API_KEY = "32224305775a97c08b5cf6b912bcbc39";  // Замените на свой API-ключ OpenWeatherMap
const std::string API_URL = "http://api.openweathermap.org/data/2.5/weather";

// Функция обратного вызова для библиотеки libcurl
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// Функция для выполнения HTTP-запроса и получения данных о погоде
std::string GetWeatherData(const std::string& city) {
    CURL* curl = curl_easy_init();

    if (curl) {
        std::string url = API_URL + "?q=" + city + "&appid=" + API_KEY + "&units=metric";
        std::string response;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        return response;
    }

    return "";
}

int main() {
    std::string city;
    std::cout << "Enter the city name: ";
    std::cin >> city;

    std::string weatherData = GetWeatherData(city);

    if (!weatherData.empty()) {
        auto root = nlohmann::json::parse(weatherData);

        if (root.contains("main") && root.contains("weather")) {
            std::string description = root["weather"][0]["description"];
            double temperature = root["main"]["temp"];

            std::cout << "Weather in " << city << ": " << description << std::endl;
            std::cout << "Temperature: " << temperature << "°C" << std::endl;
        }
        else {
            std::cerr << "Failed to retrieve weather data." << std::endl;
        }
    }
    else {
        std::cerr << "Failed to fetch weather data." << std::endl;
    }

    return 0;
}
