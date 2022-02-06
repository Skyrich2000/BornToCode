#include "Account.hpp"

#include <time.h>

#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}
int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}
int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}
int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}
void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl;
}

Account::Account(int initial_deposit) {
    this->_accountIndex = Account::getNbAccounts();
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account(void) {
    Account::_totalAmount -= this->_amount;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
    const int _p_amount = this->_amount;

    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << _p_amount << ";";
    std::cout << "deposits:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << ";";
    std::cout << std::endl;
}
bool Account::makeWithdrawal(int withdrawal) {
    const int _p_amount = this->_amount;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << _p_amount << ";";

    if (this->_amount - withdrawal < 0) {
        std::cout << "withdrawal:"
                  << "refused"
                  << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;

    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";";
    std::cout << std::endl;
    return true;
}
int Account::checkAmount(void) const {
    return this->_amount;
}
void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}

void Account::_displayTimestamp(void) {
    time_t time_now = time(NULL);
    struct tm *tm = localtime(&time_now);

    std::cout << '['
              << tm->tm_year + 1900
              << std::setfill('0') << std::setw(2)
              << tm->tm_mon + 1
              << std::setfill('0') << std::setw(2)
              << tm->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2)
              << tm->tm_hour
              << std::setfill('0') << std::setw(2)
              << tm->tm_min
              << std::setfill('0') << std::setw(2)
              << tm->tm_sec
              << "] ";
}

Account::Account(void) {
    this->_accountIndex = Account::getNbAccounts();
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_nbAccounts++;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}
