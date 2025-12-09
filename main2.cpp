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
bool readInputData(double& depositAmount, double& loanAmount){
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "oshibka otkritiya faila!" << std::endl;
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
        std::cerr << "oshibka output.txt!" << std::endl;
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

    CasinoBank bank(999999999); // начальный капитал банка

    // Запись результатов работы
    writeResults(bank, depositAmount, loanAmount);

    return 0;
}
