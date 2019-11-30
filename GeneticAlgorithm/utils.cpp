#include "utils.h"
std::random_device rd;
std::mt19937 generator(rd());


namespace std {

} //namespace std

namespace utils {
int
random(int last, int start) {
	std::uniform_int_distribution<> range(start, last - 1);
	return range(generator);
}
} //namespace utils