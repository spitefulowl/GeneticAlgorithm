#pragma once
#include "utils.h"

class BaseMutation {
public:
	BaseMutation();
	void init(std::vector<std::vector<int>>* descendants, int perc_probability);
	void exec();
	virtual std::string name() = 0;
protected:
	std::vector<std::vector<int>>* descendants;
	virtual void internal_mutation(std::vector<int>& mutant) = 0;
private:
	int perc_probability;
};

class PointMutation : public BaseMutation {
public:
	using BaseMutation::BaseMutation;
	std::string name();
private:
	void internal_mutation(std::vector<int>& mutant);
};

class InversionMutation : public BaseMutation {
public:
	using BaseMutation::BaseMutation;
	std::string name();
private:
	void internal_mutation(std::vector<int>& mutant);
};