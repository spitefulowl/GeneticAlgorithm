#include "GenAlg.h"

Eval::Eval(std::vector<std::vector<double>>* matrix) : matrix(matrix) {}

std::vector<std::pair<std::vector<int>, double>>& Eval::Evaluate(std::vector<std::vector<int>>* generation) {
	std::vector<std::pair<std::vector<int>, double>>* result = new std::vector<std::pair<std::vector<int>, double>>;
	for (auto elem : *generation) {
		elem.push_back(elem[0]);
		double path = utils::path_length(*matrix, elem);
		elem.pop_back();
		result->push_back({ elem, path });
	}
	return *result;
}

GenAlg::GenAlg(BaseGeneration* generation, BaseCrossover* crossover, 
	BaseMutation* mutation, BaseSelection* selection, std::string filename, int iterations, int population_size, int probability, int betta) :
		generation(generation), crossover(crossover), mutation(mutation), selection(selection), 
		filename(filename), my_population(nullptr), status(false), iterations(iterations), population_size(population_size) , probability(probability), betta(betta) {
	my_population_log = new std::vector<std::pair<std::vector<std::vector<int>>, std::vector<double>>>;
}

bool GenAlg::get_status() {
	return status;
}

std::vector<std::pair<std::vector<std::vector<int>>, std::vector<double>>>* GenAlg::execute() {
	if (filename == "") {
		return nullptr;
	}
	auto* matrix = utils::FileHandler<double>(filename.c_str()).GetMatrix();
	generation->init(matrix, population_size);
	my_population = generation->exec();
	for (int iter = 0; iter < iterations; ++iter) {
		std::vector<double> lengths;
		for (int idx = 0; idx < my_population->size(); ++idx) {
			(*my_population)[idx].push_back((*my_population)[idx][0]);
			lengths.push_back(utils::path_length(*matrix, (*my_population)[idx]));
			(*my_population)[idx].pop_back();
		}
		my_population_log->push_back(std::make_pair(*my_population, lengths));
		crossover->init(my_population, matrix->size());
		crossover->exec();
		auto* descendants = crossover->get_descendants();
		mutation->init(descendants, probability);
		mutation->exec();
		selection->init(matrix, my_population, descendants, betta);
		auto* my_population_tmp = selection->exec();
		delete my_population;
		my_population = my_population_tmp;
	}
	status = true;
	delete matrix;
	return my_population_log;
}