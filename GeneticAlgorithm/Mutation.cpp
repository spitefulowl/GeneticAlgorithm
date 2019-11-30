#include "Mutation.h"

BaseMutation::BaseMutation() : descendants(nullptr), perc_probability(0) {}

void BaseMutation::init(std::vector<std::vector<int>>* descendants, int perc_probability) {
	this->descendants = descendants;
	this->perc_probability = perc_probability;
}

void BaseMutation::exec() {
	for (auto& mutant : *descendants) {
		if (utils::random(101, 0) <= perc_probability) {
			internal_mutation(mutant);
		}
	}
}

std::string PointMutation::name() {
	return "point";
}

std::string InversionMutation::name() {
	return "inversion";
}

void PointMutation::internal_mutation(std::vector<int>& mutant) {
	int mutating_gene = utils::random(mutant.size());
	if (mutating_gene == 0) {
		std::swap(mutant[0], mutant[1]);
		return;
	}
	if (mutating_gene == mutant.size() - 1) {
		std::swap(mutant[mutating_gene], mutant[mutating_gene - 1]);
		return;
	}
	if (utils::random(2)) {
		std::swap(mutant[mutating_gene], mutant[mutating_gene + 1]);
	}
	else {
		std::swap(mutant[mutating_gene], mutant[mutating_gene - 1]);
	}
}

void InversionMutation::internal_mutation(std::vector<int>& mutant) {
	int first_pos = utils::random(mutant.size() - 2);
	int second_pos = utils::random(mutant.size() + 1, first_pos + 1);
	std::reverse(mutant.begin() + first_pos, mutant.begin() + second_pos);
}
