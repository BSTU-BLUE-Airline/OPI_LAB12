#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

struct CurrencyPair {
    double buyRate;
    double sellRate;
};

int main() {
    setlocale(LC_ALL, "rus");

    map<string, CurrencyPair> currencyPairs;

    ifstream file("D:/lab12opi/OPI_LAB12/parser/text.txt");
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string currencyPair;
        getline(iss, currencyPair, '|');
        double buyRate, sellRate;
        iss >> buyRate >> sellRate;
        currencyPairs[currencyPair] = { buyRate, sellRate };
    }

    string from, to;
    double amount;
    cout << "Введите исходную валюту, целевую валюту и сумму: ";
    cin >> from >> to >> amount;

    string key = from + " / " + to;
    if (currencyPairs.count(key) == 0) {
        cout << "Курс валют не найден.\n";
        return 1;
    }

    double result = amount * currencyPairs[key].sellRate;
    cout << "Результат конвертации: " << result << ' ' << to << '\n';

    return 0;
}

