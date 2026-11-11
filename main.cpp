#include "src/set.hpp"

int main()
{

	Set se;
	for (size_t i = 0; i < 5; ++i) {
		shape* s = dynamic_cast<shape*>(new Sphere(20+i));
		std::cout << *s << std::endl;
		se.add(s);
	}

	shape* s = dynamic_cast<shape*>(new Cube(21));
	se.add(s);

	std::cout << se << std::endl;

	std::cout << se.sum_metrics();

	return 0;
}
