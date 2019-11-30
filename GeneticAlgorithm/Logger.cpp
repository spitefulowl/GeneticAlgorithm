#include "Logger.h"
#include "qdebug.h"

void logger::set_conf(BaseGeneration* generation, BaseCrossover* crossover,
	BaseMutation* mutation, BaseSelection* selection) {
	this->generation = generation;
	this->crossover = crossover;
	this->mutation = mutation;
	this->selection = selection;
}
logger::logger(){
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::stringstream stream;
	stream << std::put_time(&tm, "result_%d-%m-%Y_%H-%M-%S.csv");
	my_name = stream.str();
	my_stream = new std::fstream(my_name, std::ios::out);
	(*my_stream) << "generation,crossover,mutation,selection,population_size,solution,value,iteration" << std::endl;
}

logger::~logger() {
	delete my_stream;
}

std::string logger::get_name() const {
	return my_name;
}

void logger::log(std::vector<std::pair<std::vector<std::vector<int>>, std::vector<double>>>* solution, double iter) {
	//for (int iter = 0; iter < solution->size(); ++iter) {
	//	(*my_stream) << generation->name() << "," << crossover->name() << "," << mutation->name() << "," << selection->name() << "," << (*solution)[iter].first.size() << ",";
	//	int better_idx = std::min_element((*solution)[iter].second.begin(), (*solution)[iter].second.end()) - (*solution)[iter].second.begin();
	//	std::copy((*solution)[iter].first[better_idx].begin(), (*solution)[iter].first[better_idx].end(), std::ostream_iterator<int>{*my_stream, " "});
	//	(*my_stream) << "," << (*solution)[iter].second[better_idx] << "," << iter << "," << 0 << std::endl;
	//}
	std::vector<std::pair<std::vector<int>, double>> better_solutions;
	(*my_stream) << generation->name() << "," << crossover->name() << "," << mutation->name() << "," << selection->name() << "," << (*solution)[iter].first.size() << ",";
	for (int iter = 0; iter < solution->size(); ++iter) {
		int better_idx = std::min_element((*solution)[iter].second.begin(), (*solution)[iter].second.end()) - (*solution)[iter].second.begin();
		better_solutions.push_back(std::make_pair((*solution)[iter].first[better_idx], (*solution)[iter].second[better_idx]));
	}
	auto result = std::min_element(better_solutions.begin(), better_solutions.end(), [](auto& first, auto& second) {
		return first.second < second.second;
	});
	std::copy((*result).first.begin(), (*result).first.end(), std::ostream_iterator<int>{*my_stream, " "});
	(*my_stream) << "," << (*result).second << "," << iter << std::endl;
}