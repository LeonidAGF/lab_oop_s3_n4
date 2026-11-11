#pragma once
#include <climits>
#include <iostream>

class shape {
public:
	virtual ~shape() = default;
	virtual double metric() const =0;
	virtual void print(std::ostream& os) const = 0;
	virtual bool fitsInBox(double V) const = 0;
	friend std::ostream& operator<<(std::ostream&, const shape&);
};

class Sphere final :public shape {
private:
	double rad;
public:
	explicit Sphere(double r);
	double radius() const;
	double metric() const override;
	void print(std::ostream& os) const override;
	bool fitsInBox(double V) const override;
};

class Cube final :public shape {
private:
	double ed;
public:
	explicit Cube(double a);
	double edge() const;
	double metric() const override;
	void print(std::ostream& os) const override;
	bool fitsInBox(double V) const override;
};

//конус
class Cone final  :public shape  {
private:
	double radius, height;
public:
	explicit Cone(double r,double h);
	double slantHeight() const;
	double metric() const override;
	void print(std::ostream& os) const override;
	bool fitsInBox(double V) const override;
};