#pragma once
#include "utils.h"

class BaseSelection {
public:
	BaseSelection();
	void init(std::vector<std::vector<double>>* matrix, std::vector<std::vector<int>>* population, std::vector<std::vector<int>>* descendants, int betta = 0);
	std::vector<std::vector<int>>* exec();
	virtual std::string name() = 0;
protected:
	virtual std::vector<std::vector<int>>* internal_selection(int size) = 0;
	std::vector<std::vector<int>>* population;
	std::vector<std::vector<int>>* descendants;
	std::vector<std::vector<double>>* matrix;
	int betta;
private:
};

class BettaTournament : public BaseSelection {
public:
	using BaseSelection::BaseSelection;
	std::string name();
private:
	std::vector<std::vector<int>>* internal_selection(int size);
};

class ProportionalSelection : public BaseSelection {
public:
	using BaseSelection::BaseSelection;
	std::string name();
private:
	std::vector<std::vector<int>>* internal_selection(int size);
};