#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Классы Deposit и Loan
class Deposit {
public:
    double amount;
    double interest_rate;
    Deposit(double amt, double rate):amount(amt), interest_rate(rate){};
};

class Loan {
public:
    double amount;
    double interest_rate;
    Loan(double amt, double rate):amount(amt), interest_rate(rate){};
};

// Класс CasinoBank
class CasinoBank {
private:
    double funds;
    std::vector<Deposit> deposits;
    std::vector<Loan> loans;
    
    double generateInterestRateCREDIT()
    {
        return 0.5 + static_cast<double>(rand()) / RAND_MAX * (1-0.5);
    }
    double generateInterestRateDEPOSIT()
    {
        return 0.1 + static_cast<double>(rand()) / RAND_MAX * (0.7-0.1);
    }

public:
    CasinoBank(double initial_funds):funds(initial_funds)
    {
        srand(time(0));
    }
    
    void makeDeposit(double amount, std::ofstream& outputFile)
    {
        funds += amount;
        double interest_rate=generateInterestRateDEPOSIT();
        deposits.emplace_back(amount, interest_rate);
        outputFile << "Вклад внесен:" << amount << "Руб, ставка:" << std::fixed << std::setprecision(2) << interest_rate * 100 << "%\n";
        std::cout << "Vklad vidan: " << amount << " RUB, stavka:" << std::fixed << std::setprecision(2) << interest_rate * 100 << "%\n" << std::endl;
    }
    void giveLoan(double amount, std::ofstream& outputFile)
    {
        double interest_rate = generateInterestRateCREDIT();
        funds -= amount;
        loans.emplace_back(amount, interest_rate);
        outputFile << "Кредит выдан: " << amount << " руб, ставка:" << std::fixed << std::setprecision(2) << interest_rate * 100 << "%\n";
        std::cout << "Kredit vidan: " << amount << " RUB, stavka:" << std::fixed << std::setprecision(2) << interest_rate * 100 << "%\n" << std::endl;
    }
    void showFunds(std::ofstream& outputFile)
    {
        outputFile << "Общий капитал банка: " << funds << " руб.\n";
    }
};

// Функция для чтения данных из файла
bool readInputData(double& depositAmount, double& loanAmount) {
    // TODO: реализовать чтение данных из файла input.txt
    // Первое число - сумма вклада, второе - сумма кредита
    // Возвращает true при успешном чтении, false при ошибке
    return false;
}

// Функция для записи результатов работы
void writeResults(CasinoBank& bank, double depositAmount, double loanAmount) {
    // TODO: открыть файл output.txt для записи
    // TODO: обработать вклад (если depositAmount > 0)
    // TODO: обработать кредит (если loanAmount > 0)
    // TODO: вывести итоговый капитал банка
    // TODO: закрыть файл
}

// Функция для обработки данных
void processData() {
    // TODO: объявить переменные для сумм вклада и кредита
    // TODO: вызвать readInputData для получения данных
    // TODO: создать объект CasinoBank с начальным капиталом
    // TODO: вызвать writeResults для обработки и записи результатов
}

int main() {
    setlocale(LC_ALL, "Russian");
    // TODO: вызвать функцию processData
    return 0;
}