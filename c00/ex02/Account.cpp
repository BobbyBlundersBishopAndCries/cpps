#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::getNbAccounts(){ return Account::_nbAccounts;}
int Account::getTotalAmount(){ return Account::_totalAmount;}
int Account::getNbDeposits(){ return Account::_totalNbDeposits;}
int	Account::getNbWithdrawals(){ return Account::_totalNbWithdrawals;}
void	Account::_displayTimestamp( void )
{
    std::time_t t = std::time(0);        // use 0 instead of nullptr
    std::tm* now = std::localtime(&t);

    std::cout << "["
              << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
}
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}
Account::Account(int initial_deposit)
: _accountIndex(_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
	_nbAccounts++;
    _totalAmount += _amount;
	
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";created" << std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
    std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed" << std::endl;
}


void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;
	_amount+= deposit;
	_totalAmount+= deposit;
	_totalNbDeposits+= 1;
	_nbDeposits+= 1;
	std::cout << ";deposit:" << deposit
		      << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;
	if(withdrawal <= _amount)
	{
		_nbWithdrawals+=1;
		_totalNbWithdrawals+=1;
		_amount -= withdrawal;
		std::cout <<";withdrawal:"<< withdrawal
				  << ";amount:" << _amount
				  <<":nb_withdrawals:" << _nbWithdrawals
				  << std::endl;
		return true;
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;;
		return false;
	}

}

int Account::checkAmount(void) const
{
    return _amount;
}\

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
		std::cout << "index:" << _accountIndex 
				  << ";amount:" << _amount
				  << ";deposits:" << _nbDeposits
				  << ";withdrawals:" << _nbWithdrawals
				  << std::endl;
}
