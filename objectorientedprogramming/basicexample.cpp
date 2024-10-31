// 1. Basic Class Example
#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    int id;
    double salary;

public:
    // Constructor
    Employee(std::string n, int i, double s) : name(n), id(i), salary(s) {}

    // Getter methods
    std::string getName() const { return name; }
    int getId() const { return id; }
    double getSalary() const { return salary; }

    // Setter method with validation
    void setSalary(double s) {
        if (s > 0) {
            salary = s;
        }
    }

    // Member function
    void displayInfo() const {
        std::cout << "Name: " << name << "\nID: " << id 
                  << "\nSalary: $" << salary << std::endl;
    }
};

// 2. Inheritance Example
class Shape {
protected:
    std::string color;

public:
    Shape(std::string c) : color(c) {}
    virtual double getArea() = 0;  // Pure virtual function
    virtual ~Shape() {}  // Virtual destructor
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(std::string c, double r) : Shape(c), radius(r) {}

    double getArea() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(std::string c, double w, double h) 
        : Shape(c), width(w), height(h) {}

    double getArea() override {
        return width * height;
    }
};

// 3. Composition Example
class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}
    void start() {
        std::cout << "Engine started. HP: " << horsepower << std::endl;
    }
};

class Car {
private:
    Engine engine;
    std::string brand;

public:
    Car(std::string b, int hp) : engine(hp), brand(b) {}
    void startCar() {
        std::cout << brand << " ";
        engine.start();
    }
};

// Main function demonstrating usage
int main() {
    // Testing Employee class
    Employee emp1("John Doe", 1001, 50000);
    emp1.displayInfo();
    emp1.setSalary(55000);
    std::cout << "Updated salary: $" << emp1.getSalary() << "\n\n";

    // Testing inheritance and polymorphism
    Circle circle("Red", 5);
    Rectangle rect("Blue", 4, 6);

    Shape* shapes[] = {&circle, &rect};
    for (Shape* shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }

    // Testing composition
    Car myCar("Toyota", 180);
    myCar.startCar();

    return 0;
}