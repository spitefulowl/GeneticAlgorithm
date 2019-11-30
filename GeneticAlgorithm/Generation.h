#pragma once
#include "utils.h"
class BaseGeneration {
public:
	BaseGeneration();
	void init(std::vector<std::vector<double>>* matrix, int size);
	virtual std::vector<std::vector<int>>* exec() = 0;
	virtual std::string name() = 0;
protected:
	std::vector<std::vector<double>>* matrix;
	int individ_size;
};

class RandomGeneration : public BaseGeneration {
public:
	using BaseGeneration::BaseGeneration;
	std::string name();
	std::vector<std::vector<int>>* exec();
};

class GreedyGeneration : public BaseGeneration {
public:
	using BaseGeneration::BaseGeneration;
	std::string name();
	std::vector<std::vector<int>>* exec();
};