#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <random>
#include <sstream>
#include <type_traits>

namespace std {
template<typename T>
class hash<std::vector<std::vector<T>>> { //so bad
public:
	size_t operator()(const std::vector<std::vector<T>>& matrix) const
	{
		size_t res = 0;
		std::for_each(matrix.begin(), matrix.end(), [&res](auto& elem) {
			std::for_each(elem.begin(), elem.end(), [&res](auto& elem2) { res ^= std::hash<T>()(elem2) << 1; });
		});
		return res;
	}
};

} //namespace std

namespace utils {

int
random(int last, int start = 0);

template<typename T>
std::string
random_matrix_generator(int size, T max_element) {
	std::vector<std::vector<T>> matrix(size);
	for (int row = 0; row < size; ++row) {
		matrix[row].resize(size);
		for (int col = 0; col < size; ++col)
			if (col == row)
				matrix[row][col] = 0;
			else
				matrix[row][col] = random(max_element, 1);
	}
	std::stringstream stream;
	stream << std::hex << std::hash<std::vector<std::vector<T>>>()(matrix);
	stream << ".txt";
	matrix_print(matrix, stream.str());
	return stream.str();
}


template<typename Matrix>
void
matrix_print(Matrix& matrix, std::string filename) {
	std::fstream stream(filename, std::ios::out);
	for (int row = 0; row < matrix.size(); ++row) {
		for (int col = 0; col < matrix.size(); ++col)
			if (col != matrix.size() - 1)
				stream << matrix[row][col] << " ";
			else
				stream << matrix[row][col];
		if (row != matrix.size() - 1)
			stream << std::endl;
	}
	stream.close();
}

template<typename Vector>
int
find_min(const Vector& vec, const std::vector<bool>& unvisited) {
	int min = INT_MAX;
	int idx = -1;
	for (int i = 0; i < vec.size(); ++i)
		if (unvisited[i] && vec[i] < min) {
			min = vec[i];
			idx = i;
		}
		else if (unvisited[i] && vec[i] == min) {
			if (random(2, 0) == 1) {
				min = vec[i];
				idx = i;
			}
		}
	return idx;
}

template<typename Vector>
int
find_max(const Vector& vec, const std::vector<bool>& unvisited) {
	int max = 0;
	int idx = -1;
	for (int i = 0; i < vec.size(); ++i)
		if (unvisited[i] && vec[i] > max) {
			max = vec[i];
			idx = i;
		}
		else if (unvisited[i] && vec[i] == max) {
			if (random(2, 0) == 1) {
				max = vec[i];
				idx = i;
			}
		}
	return idx;
}

template<typename Vector, typename Matrix>
double
path_length(const Matrix& matrix, const Vector& result) {
	double res = 0;
	for (int idx = 1; idx < result.size(); ++idx)
		res += matrix[result[idx - 1]][result[idx]];
	return res;
}

template<typename T>
class FileHandler {
public:
	std::vector<std::vector<T>>*
		GetMatrix() {
		file = std::fstream(filename, std::ios::in);
		while (!file.eof()) {
			T value = 0;
			matrix->push_back(std::vector<T>{});
			std::string str;
			std::getline(file, str);
			std::stringstream sstream(str);
			while (!sstream.eof()) {
				sstream >> value;
				(matrix->rbegin())->push_back(value);
			}
		}
		return matrix;
	}

	FileHandler(const char* filename) {
		this->filename = filename;
		matrix = new std::vector<std::vector<T>>;
	}

	~FileHandler() {
		file.close();
	}

private:
	std::string filename;
	std::vector<std::vector<T>>* matrix;
	std::fstream file;

};

}