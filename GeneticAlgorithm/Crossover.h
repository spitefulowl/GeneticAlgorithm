#pragma once
#include "utils.h"
#include <iterator>
#include <map>
class BaseCrossover {
public:
	BaseCrossover();
	void init(std::vector<std::vector<int>>* population, int length);
	void exec();
	std::vector<std::vector<int>>* get_descendants();
	virtual std::string name() = 0;
protected:
	std::vector<std::vector<int>>* population;
	std::vector<std::vector<int>>* descendants;
	int length;
	template<typename Vector>
	bool contains(Vector& vector, int value) {
		return std::find(vector.begin(), vector.end(), value) != vector.end();
	}
	void internal_exec();
	virtual std::vector<int> internal_generator(std::vector<int>& first_parent, std::vector<int>& second_parent, int first_cut, int second_cut) = 0;
};

class OrdinalCrossover : public BaseCrossover {
public:
	using BaseCrossover::BaseCrossover;
	std::string name();
private:
	std::vector<int> internal_generator(std::vector<int>& first_parent, std::vector<int>& second_parent, int first_cut, int second_cut);
};

class PartialCrossover : public BaseCrossover {
public:
	using BaseCrossover::BaseCrossover;
	std::string name();
private:
	std::vector<int> internal_generator(std::vector<int>& first_parent, std::vector<int>& second_parent, int first_cut, int second_cut);
};