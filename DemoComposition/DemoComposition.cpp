#include <iostream>
#include <vector>
#include <memory>
#include <format>

class Point {
private: 
    int _x;
    int _y;
public:
    Point() {}
    Point(int x, int y) : _x(x), _y(y) {}
};

class Line {
private:
    Point _start;
    Point _end;
private:
    Line() {}
public:
    Line(Point start, Point end) : _start(start), _end(end) {
    }
};

class Fraction {
private:
    int _numerator;
	int _denominator;
public:
    typedef std::shared_ptr<Fraction> Pointer;

    Fraction() {
    	_numerator = 0;
    	_denominator = 1;
    }

    Fraction(int numerator, int denominator) {
        if (denominator == 0) {
			throw std::invalid_argument("Denominator cannot be zero");
		}
        _numerator = numerator;
        _denominator = denominator;
    }

    std::string toString() {
    }
    ~Fraction() {
        std::cout << "Destructor";
    }
};

class Vehicle {
protected:
    std::string _brand;
public:
    Vehicle() { }
public:
    Vehicle(std::string brand) : _brand(brand) {
    }
    virtual void start() { std::cout << "A vehicle is starting...\n"; }
    void run() { std::cout << "A vehicle is rolling...\n"; }
    
    virtual ~Vehicle() {
        std::cout << "Vehicle's destructor\n"; 
    }
};

class Car : public Vehicle {
public:
    Car() {
	}
    Car(std::string brandName):Vehicle(brandName) {    
    }
    std::string toString() {
    }
    ~Car() {
        std::cout << "Car's destructor\n";
    }
public:
    void start() override {
        std::cout << "\nTo the new way:";
    }
};

class Shape {
public:
    virtual float area() { return 0; }
};

class Circle : public Shape {
private:
    float _radius;
public:
    Circle() {}
    Circle(float radius) { _radius = radius; }
    float area() override  {
		return 3.14 * _radius * _radius;
	}
};

int main()
{
    Vehicle* ford = new Car("Ford");
    delete ford;
}