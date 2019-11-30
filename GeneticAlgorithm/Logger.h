#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "GenAlg.h"

class logger {
public:
	logger();
	logger(const logger&) = delete;
	~logger();
	void log(std::vector<std::pair<std::vector<std::vector<int>>, std::vector<double>>>* solution, double iter);
	void set_conf(BaseGeneration* generation, BaseCrossover* crossover,
		BaseMutation* mutation, BaseSelection* selection);
	std::string get_name() const;
private:
	std::string my_name;
	std::fstream* my_stream;
	BaseGeneration* generation;
	BaseCrossover* crossover;
	BaseMutation* mutation;
	BaseSelection* selection;
};
