#pragma once
#include "Generation.h"
#include "Crossover.h"
#include "Mutation.h"
#include "Selection.h"
#include <fstream>

class Eval {
public:
	Eval(std::vector<std::vector<double>>* matrix);
	std::vector<std::pair<std::vector<int>, double>>& Evaluate(std::vector<std::vector<int>>* generation);
private:
	std::vector<std::vector<double>>* matrix;
};

class GenAlg {
public:
	GenAlg(BaseGeneration* generation, BaseCrossover* crossover, BaseMutation* mutation, BaseSelection* selection, std::string filename, int iterations, int population_size, int probability, int betta);
	std::vector<std::pair<std::vector<std::vector<int>>, std::vector<double>>>* execute();
	bool get_status();
private:
	bool status;
	std::string filename;
	BaseGeneration* generation;
	BaseCrossover* crossover;
	BaseMutation* mutation;
	BaseSelection* selection;
	std::vector<std::vector<int>>* my_population;
	std::vector<std::pair<std::vector<std::vector<int>>, std::vector<double>>>* my_population_log;
	int iterations;
	int population_size;
	int probability;
	int betta;
};
