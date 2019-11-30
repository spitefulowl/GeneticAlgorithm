#include "Selection.h"
#include <QMessageBox>
#include <qdebug.h>
#define OVERLAP_COEF 0.5

BaseSelection::BaseSelection() : population(nullptr), descendants(nullptr), matrix(nullptr) {}

void BaseSelection::init(std::vector<std::vector<double>>* matrix, 
	std::vector<std::vector<int>>* population, std::vector<std::vector<int>>* descendants, int betta) {
	this->matrix = matrix;
	this->population = population;
	this->descendants = descendants;
	this->betta = betta;
}

std::vector<std::vector<int>>* BaseSelection::exec() {
	std::vector<std::vector<int>>* new_population = new std::vector<std::vector<int>>;
	int base_population_count = OVERLAP_COEF * (double)population->size();
	int descendants_count = population->size() - base_population_count;
	std::random_shuffle(population->begin(), population->end());
	std::copy(population->begin(), population->begin() + base_population_count, std::back_inserter(*new_population));
	auto* new_descendants = internal_selection(descendants_count);
	std::copy(new_descendants->begin(), new_descendants->end(), std::back_inserter(*new_population));
	QMessageBox msg_box;
	msg_box.setWindowTitle("ASSERT");
	msg_box.setText("INCORRECT WORK OF SELECTION ALGORITHM");
	if (new_population->size() != population->size()) {
		msg_box.exec();
	}
	return new_population;
}

std::string BettaTournament::name() {
	return "betta";
}

std::string ProportionalSelection::name() {
	return "proportional";
}

std::vector<std::vector<int>>* BettaTournament::internal_selection(int size) {
	std::vector<std::vector<int>>* result = new std::vector<std::vector<int>>;
	for (int iter = 0; iter < size; ++iter) {
		std::vector<int> criterium;
		std::vector<std::vector<int>>* betta_tour = new std::vector<std::vector<int>>;
		for (int betta_idx = 0; betta_idx < betta; ++betta_idx) {
			betta_tour->push_back((*descendants)[utils::random(descendants->size())]);
		}
		for (auto iter = betta_tour->begin(); iter != betta_tour->end(); ++iter) {
			iter->push_back((*iter)[0]);
			criterium.push_back(utils::path_length(*matrix, *iter));
			iter->pop_back();
		}
		result->push_back((*betta_tour)[std::min_element(criterium.begin(), criterium.end()) - criterium.begin()]);
		delete betta_tour;
	}
	return result;
}

std::vector<std::vector<int>>* ProportionalSelection::internal_selection(int size) {
	std::vector<std::vector<int>>* result = new std::vector<std::vector<int>>;
	std::vector<int> criterium;
	for (auto iter = descendants->begin(); iter != descendants->end(); ++iter) {
		iter->push_back((*iter)[0]);
		criterium.push_back(utils::path_length(*matrix, *iter));
		iter->pop_back();
	}
	//double criterium_avg = std::accumulate(criterium.begin(), criterium.end(), 0.) / (double)(criterium.end() - criterium.begin());
	//for (int idx = 0; idx < descendants->size(); ++idx) {
	//	for (int counter = 0; counter < criterium_avg / criterium[idx]; ++counter) {
	//		if (result->size() < size) {
	//			result->push_back((*descendants)[idx]);
	//		}
	//	}
	//}


	//custom
	double criterium_sum = std::accumulate(criterium.begin(), criterium.end(), 0.);
	std::vector<double> partial_sum;
	std::partial_sum(criterium.begin(), criterium.end(), std::back_inserter(partial_sum));
	while (result->size() < size) {
		int selected_value = utils::random((*partial_sum.rbegin()) + 1., std::ceil(partial_sum[0]));
		int selected_idx = std::find_if(partial_sum.rbegin(), partial_sum.rend(), [&selected_value](double& value) {
			return value <= selected_value;
		}) - partial_sum.rbegin();
		result->push_back((*descendants)[partial_sum.size() - selected_idx - 1]);
	}
	return result;

	//double criterium_sum = std::accumulate(criterium.begin(), criterium.end(), 0.);
	//double max = *std::max_element(criterium.begin(), criterium.end());
	//double upper = max / criterium_sum;
	//double internal_probability = upper;
	//int multiplier = 1;
	//while (internal_probability < 10) {
	//	internal_probability *= 10.;
	//	multiplier *= 10;
	//}
	//while (result->size() < size) {
	//	for (int idx = 0; idx < descendants->size(); ++idx) {
	//		double probability = (upper - criterium[idx] / criterium_sum) * multiplier;
	//		if (((double)utils::random(upper * multiplier)) <= probability && result->size() < size) {
	//			result->push_back((*descendants)[idx]);
	//		}
	//	}
	//}


	return result;
}