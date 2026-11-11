#include "3D.hpp"
#include <math.h>

explicit Sphere::Sphere(double r):rad(r) {}
double Sphere::radius() const {
	return this->rad;
}
double Sphere::metric() const {
	return (4 / 3) * 3.14 * std::pow(radius(), 3);
}
void Sphere::print(std::ostream& os) const {
	os << "Sphere: r=" << radius() << std::endl;
}
bool Sphere::fitsInBox(double V) const {
	return std::pow(V, 1.0 / 3)-(2 * radius()) >= 0.0001 ;
}

explicit Cube::Cube(double a): ed(a) {}
double Cube::edge() const {
	return ed;
}
double Cube::metric() const {
	return std::pow(ed, 3);
}
void Cube::print(std::ostream& os) const {
	os << "Cube: a=" << edge() << std::endl;
}
bool Cube::fitsInBox(double V) const {
	return  std::pow(V, 1.0 / 3) - edge() >= 0.0001;
}

explicit Cone::Cone(double r, double h): radius(r), height(h){}
double Cone::slantHeight() const {
	return std::sqrt((radius * radius) + (height * height));
}
double Cone::metric() const {
	return (1.0 / 3) * 3.14 * radius * radius * height;
}
void Cone::print(std::ostream& os) const {
	os << "Cone: r=" << radius << " h=" << height << std::endl;
}
bool Cone::fitsInBox(double V) const {
	return  std::pow(V, 1.0 / 3) - std::max(2*radius,height) >= 0.0001;
}