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
    Deposit(double amt, double rate);
};

class Loan {
public:
    double amount;
    double interest_rate;
    Loan(double amt, double rate);
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
bool readInputData(double& depositAmount, double& loanAmount){
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Ошибка открытия входного файла!" << std::endl;
        return false;
    }

    inputFile >> depositAmount >> loanAmount;
    inputFile.close();

    return true;
}

// Функция для записи результатов работы
void writeResults(CasinoBank& bank, double depositAmount, double loanAmount) {
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Ошибка открытия выходного файла!" << std::endl;
        return;
    }

    // Обработка вклада
    if (depositAmount > 0) {
        bank.makeDeposit(depositAmount, outputFile);
    }
    else {
        outputFile << "Некорректная сумма вклада.\n";
    }

    // Обработка кредита
    if (loanAmount > 0) {
        bank.giveLoan(loanAmount, outputFile);
    }
    else {
        outputFile << "Некорректная сумма кредита.\n";
    }

    // Отображение итогового капитала банка
    bank.showFunds(outputFile);
    outputFile.close();
}


int main() {
    double depositAmount = 0, loanAmount = 0;

    // Чтение данных из входного файла
    if (!readInputData(depositAmount, loanAmount)) {
        return 1;
    }

    CasinoBank bank(9999999999999); // начальный капитал банка

    // Запись результатов работы
    writeResults(bank, depositAmount, loanAmount);

    return 0;
}