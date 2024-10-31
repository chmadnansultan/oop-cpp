#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Forward declaration
template<typename T>
class Matrix;

// Custom exception class
class MatrixException : public std::runtime_error {
public:
    explicit MatrixException(const std::string& message) 
        : std::runtime_error(message) {}
};

// Smart Resource Handler using RAII
class ResourceHandler {
private:
    std::string resource_name;
public:
    explicit ResourceHandler(const std::string& name) 
        : resource_name(name) {
        std::cout << "Resource acquired: " << resource_name << std::endl;
    }
    
    ~ResourceHandler() {
        std::cout << "Resource released: " << resource_name << std::endl;
    }
    
    // Delete copy constructor and assignment operator
    ResourceHandler(const ResourceHandler&) = delete;
    ResourceHandler& operator=(const ResourceHandler&) = delete;
};

// Template Matrix class with operator overloading
template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;
    std::shared_ptr<ResourceHandler> resource;  // Shared resource

public:
    // Constructor
    Matrix(size_t r, size_t c, const T& default_value = T())
        : rows(r), cols(c), 
          resource(std::make_shared<ResourceHandler>("Matrix_Resource")) {
        if (r == 0 || c == 0) {
            throw MatrixException("Invalid matrix dimensions");
        }
        data.resize(r, std::vector<T>(c, default_value));
    }

    // Copy constructor with deep copy
    Matrix(const Matrix& other)
        : rows(other.rows), cols(other.cols), 
          resource(other.resource) {
        data = other.data;
    }

    // Move constructor
    Matrix(Matrix&& other) noexcept
        : rows(other.rows), cols(other.cols),
          data(std::move(other.data)),
          resource(std::move(other.resource)) {
        other.rows = 0;
        other.cols = 0;
    }

    // Operator overloading for matrix addition
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw MatrixException("Matrix dimensions don't match for addition");
        }

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Operator overloading for matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw MatrixException("Matrix dimensions don't match for multiplication");
        }

        Matrix result(rows, other.cols, T());
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Stream insertion operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

    // Element access with bounds checking
    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols) {
            throw MatrixException("Index out of bounds");
        }
        return data[r][c];
    }

    // Const version of element access
    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols) {
            throw MatrixException("Index out of bounds");
        }
        return data[r][c];
    }

    // Transform operation using templates and callbacks
    template<typename Func>
    Matrix& transform(Func operation) {
        for (auto& row : data) {
            for (auto& element : row) {
                element = operation(element);
            }
        }
        return *this;
    }
};

// Observer Pattern implementation
class Subject;

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const Subject* subject) = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;
    int state;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void setState(int s) {
        state = s;
        notify();
    }

    int getState() const { return state; }

protected:
    void notify() {
        for (Observer* observer : observers) {
            observer->update(this);
        }
    }
};

class ConcreteObserver : public Observer {
private:
    std::string name;

public:
    explicit ConcreteObserver(const std::string& n) : name(n) {}

    void update(const Subject* subject) override {
        std::cout << name << " observed state change to: " 
                 << subject->getState() << std::endl;
    }
};

// Main function demonstrating usage
int main() {
    try {
        // Matrix operations
        Matrix<double> m1(2, 2, 1.0);
        Matrix<double> m2(2, 2, 2.0);

        std::cout << "Matrix 1:\n" << m1 << "\n";
        std::cout << "Matrix 2:\n" << m2 << "\n";

        // Matrix addition
        auto m3 = m1 + m2;
        std::cout << "Matrix Addition Result:\n" << m3 << "\n";

        // Matrix multiplication
        auto m4 = m1 * m2;
        std::cout << "Matrix Multiplication Result:\n" << m4 << "\n";

        // Transform operation with lambda
        m3.transform([](double x) { return x * 2; });
        std::cout << "Transformed Matrix:\n" << m3 << "\n";

        // Observer pattern demonstration
        Subject subject;
        ConcreteObserver observer1("Observer 1");
        ConcreteObserver observer2("Observer 2");

        subject.attach(&observer1);
        subject.attach(&observer2);
        subject.setState(42);

    } catch (const MatrixException& e) {
        std::cerr << "Matrix error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}