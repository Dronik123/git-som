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
    
    double generateInterestRateCREDIT();
    double generateInterestRateDEPOSIT();

public:
    CasinoBank(double initial_funds);
    
    void makeDeposit(double amount, std::ofstream& outputFile);
    void giveLoan(double amount, std::ofstream& outputFile);
    void showFunds(std::ofstream& outputFile);
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