#pragma once

#include "Account.hpp"
class Checking :public Account {
	float m_MinimumBalance = 50;
public:
	using Account::Account;
	//Checking(const std::string& name, float balance);
	~Checking();
	void Withdraw(float amount);
	float GetMinimumBalance() const;
};

