#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;

int main() {
    ifstream file("text.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    map<string, pair<double, double>> exchangeRates;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string key;
        double buyRate, sellRate;
        ss >> key >> buyRate >> sellRate;
        exchangeRates[key] = make_pair(buyRate, sellRate);
    }
    file.close();

    cout << "Доступные валюты:" << endl;
    for (const auto& pair : exchangeRates) {
        cout << pair.first << endl;
    }

    string fromCurrency, toCurrency;
    double amount;

    cout << "Введите исходную валюту (код валюты): ";
    cin >> fromCurrency;
    cout << "Введите желаемую валюту (код валюты): ";
    cin >> toCurrency;
    cout << "Введите сумму для конвертации: ";
    cin >> amount;

    string pairName = fromCurrency + " / " + toCurrency;
    if (exchangeRates.find(pairName) == exchangeRates.end()) {
        cout << "Ошибка: Такая пара валют не найдена." << endl;
        return 1;
    }

    double buyRate = exchangeRates[pairName].first;
    double sellRate = exchangeRates[pairName].second;
    double result = amount * (buyRate + sellRate) / 2;

    cout << fixed << setprecision(2);
    cout << amount << " " << fromCurrency << " = " << result << " " << toCurrency << endl;

    return 0;
}
