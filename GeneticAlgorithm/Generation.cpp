#include "Generation.h"

BaseGeneration::BaseGeneration() : matrix(nullptr), individ_size(0) {}

void BaseGeneration::init(std::vector<std::vector<double>>* matrix, int size) {
	this->matrix = matrix;
	individ_size = size;
}

std::string GreedyGeneration::name() {
	return "greedy";
}

std::string RandomGeneration::name() {
	return "random";
}

std::vector<std::vector<int>>* GreedyGeneration::exec() {
	std::vector<std::vector<int>>* my_generation = new std::vector<std::vector<int>>;
	std::vector<bool> visited(matrix->size());
	std::fill(visited.begin(), visited.end(), false);
	for (int individ = 0; individ < individ_size; ++individ) {
		std::vector<int> result;
		double path_length = 0;
		int start_idx = utils::random(matrix->size());
		auto selected_city = (*matrix)[start_idx];
		std::vector<bool> unvisited_cities(matrix->size());
		std::fill(unvisited_cities.begin(), unvisited_cities.end(), true);
		unvisited_cities[start_idx].flip();
		result.push_back(start_idx);
		for (int i = 0; i < matrix->size() - 1; ++i) {
			bool state = true;
			auto internal_unvisited = unvisited_cities;
			int max_idx = utils::find_max(selected_city, unvisited_cities);
			int min_idx = 0;
			while (state && (internal_unvisited != visited)) {
				min_idx = utils::find_min(selected_city, internal_unvisited);
				double probability = (1 - selected_city[min_idx] / selected_city[max_idx]) * 100;
				internal_unvisited[min_idx].flip();
				if (utils::random(101, 1) <= probability) {
					state = false;
				}
			}
			unvisited_cities[min_idx].flip();
			path_length += selected_city[min_idx];
			result.push_back(min_idx);
			selected_city = (*matrix)[min_idx];
		}
		path_length += selected_city[start_idx];
		my_generation->push_back(result);
	}
	return my_generation;
}

std::vector<std::vector<int>>* RandomGeneration::exec() {
	std::vector<std::vector<int>>* my_generation = new std::vector<std::vector<int>>;
	for (int individ = 0; individ < individ_size; ++individ) {
		std::vector<int> result;
		double path_length = 0;
		result.resize((*matrix)[0].size());
		std::iota(result.begin(), result.end(), 0);
		std::random_shuffle(result.begin(), result.end());
		result.push_back(result[0]);
		path_length = utils::path_length(*matrix, result);
		result.pop_back();
		my_generation->push_back(result);
	}
	return my_generation;
}
