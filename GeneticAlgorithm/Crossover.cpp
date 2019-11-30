#include "Crossover.h"

BaseCrossover::BaseCrossover() : population(nullptr), descendants(nullptr) {}

void BaseCrossover::init(std::vector<std::vector<int>>* population, int length) {
	this->population = population;
	this->length = length;
	descendants = new std::vector<std::vector<int>>;
}

std::vector<std::vector<int>>* BaseCrossover::get_descendants() {
	return descendants;
}

void BaseCrossover::internal_exec() {
	int first_parent_idx = utils::random(population->size());
	int second_parent_idx = first_parent_idx;
	while (first_parent_idx == second_parent_idx) {
		second_parent_idx = utils::random(population->size());
	}
	std::vector<int> first_parent = (*population)[first_parent_idx];
	std::vector<int> second_parent = (*population)[second_parent_idx];
	int first_cut = utils::random(length);
	int second_cut = utils::random(length + 1, first_cut + 1);
	auto individ1 = internal_generator(first_parent, second_parent, first_cut, second_cut);
	auto individ2 = internal_generator(second_parent, first_parent, first_cut, second_cut);
	descendants->push_back(individ1);
	descendants->push_back(individ2);
}


void BaseCrossover::exec() {
	int size = population->size();
	for (int iter = 0; iter < size; ++iter) {
		internal_exec();
	}
}

std::string OrdinalCrossover::name() {
	return "ordinal";
}

std::string PartialCrossover::name() {
	return "partial";
}
std::vector<int>
OrdinalCrossover::internal_generator(std::vector<int>& first_parent, std::vector<int>& second_parent,
		int first_cut, int second_cut) {
	std::vector<int> individ(length);
	std::fill(individ.begin(), individ.end(), -1);
	std::copy(first_parent.begin() + first_cut, first_parent.begin() + second_cut, individ.begin() + first_cut);
	auto individ_iterator = individ.begin() + second_cut;
	auto second_parent_iterator = second_parent.begin() + second_cut == second_parent.end() ? second_parent.begin() : second_parent.begin() + second_cut;
	while (second_parent_iterator != second_parent.end() && contains(individ, -1)) {
		if (individ_iterator != individ.end()) {
			if (!contains(individ, *second_parent_iterator)) {
				(*individ_iterator++) = *second_parent_iterator;
			}
			second_parent_iterator++;
		}
		else {
			individ_iterator = individ.begin();
		}
		if (second_parent_iterator == second_parent.end()) {
			second_parent_iterator = second_parent.begin();
		}
	}
	return individ;
}

std::vector<int>
PartialCrossover::internal_generator(std::vector<int>& first_parent, std::vector<int>& second_parent, int first_cut, int second_cut)
{
	std::vector<int> individ(length);
	std::fill(individ.begin(), individ.end(), -1);
	std::copy(first_parent.begin() + first_cut, first_parent.begin() + second_cut, individ.begin() + first_cut);
	auto individ_iterator = individ.begin() + second_cut;
	auto second_parent_iterator = second_parent.begin() + second_cut == second_parent.end() ? second_parent.begin() : second_parent.begin() + second_cut;
	std::map<int, int> my_map;
	for (auto iter = first_parent.begin() + first_cut; iter != first_parent.begin() + second_cut; ++iter) {
		auto dist = iter - first_parent.begin();
		my_map[*iter] = second_parent[dist];
		auto internal_find = [&]() {
			return std::find(first_parent.begin() + first_cut, first_parent.begin() + second_cut, my_map[*iter]);
		};
		while (internal_find() != first_parent.begin() + second_cut) {
			my_map[*iter] = second_parent[internal_find() - first_parent.begin()];
			if (*iter == my_map[*iter]) {
				break;
			}
		}
	}
	while (second_parent_iterator != second_parent.end() && contains(individ, -1)) {
		if (individ_iterator != individ.end()) {
			if (my_map.find(*second_parent_iterator) == my_map.end()) {
				(*individ_iterator++) = *second_parent_iterator;
			}
			else {
				(*individ_iterator++) = my_map[*second_parent_iterator];
			}
			second_parent_iterator++;
		}
		else {
			individ_iterator = individ.begin();
		}
		if (second_parent_iterator == second_parent.end()) {
			second_parent_iterator = second_parent.begin();
		}
	}
	return individ;
}
