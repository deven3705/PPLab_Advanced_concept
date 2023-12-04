//using inheriantance

#include <iostream>

class PowerCalculator {
public:
    virtual double calculatePower(double n, int p) = 0;
};

class RecursivePowerCalculator : public PowerCalculator {
public:
    double calculatePower(double n, int p) override {
        if (p == 0) {
            return 1.0;
        } else if (p == 1) {
            return n;
        } else {
            return n * calculatePower(n, p - 1);
        }
    }
};

class IterativePowerCalculator : public PowerCalculator {
public:
    double calculatePower(double n, int p) override {
        double result = 1.0;
        for (int i = 0; i < p; i++) {
            result *= n;
        }
        return result;
    }
};

int main() {
    double n;
    int p;

    std::cout << "Enter the base value: ";
    std::cin >> n;

    std::cout << "Enter the power value: ";
    std::cin >> p;

    // Create an instance of RecursivePowerCalculator
    RecursivePowerCalculator recursiveCalculator;
    double recursiveResult = recursiveCalculator.calculatePower(n, p);

    // Create an instance of IterativePowerCalculator
    IterativePowerCalculator iterativeCalculator;
    double iterativeResult = iterativeCalculator.calculatePower(n, p);

    std::cout << "Recursive power: " << recursiveResult << std::endl;
    std::cout << "Iterative power: " << iterativeResult << std::endl;

    return 0;
}

//using exception handling
#include <iostream>

using namespace std;

class PowerException : public exception {
public:
    PowerException(const string& message) : message(message) {}

    const string& getMessage() const {
        return message;
    }

private:
    string message;
};

double power(double n, int p) {
    if (n == 0 && p == 0) {
        throw PowerException("Invalid input: n cannot be 0 when p is 0");
    }

    if (n < 0) {
        throw PowerException("Invalid input: n cannot be negative");
    }

    if (p < 0) {
        throw PowerException("Invalid input: p cannot be negative");
    }

    if (p == 0) {
        return 1.0;
    } else if (p == 1) {
        return n;
    } else {
        return n * power(n, p - 1);
    }
}

int main() {
    double n;
    int p;

    cout << "Enter the base value: ";
    cin >> n;

    cout << "Enter the power value: ";
    cin >> p;

    try {
        double result = power(n, p);
        cout << "The power of " << n << " raised to " << p << " is: " << result << endl;
    } catch (PowerException& e) {
        cerr << "Error: " << e.getMessage() << endl;
    }

    return 0;
}

//using virtual function

#include <iostream>

class PowerCalculator {
public:
    virtual double calculatePower(double n, int p) = 0;
};

class RecursivePowerCalculator : public PowerCalculator {
public:
    double calculatePower(double n, int p) override {
        if (p == 0) {
            return 1.0;
        } else if (p == 1) {
            return n;
        } else {
            return n * calculatePower(n, p - 1);
        }
    }
};

class IterativePowerCalculator : public PowerCalculator {
public:
    double calculatePower(double n, int p) override {
        double result = 1.0;
        for (int i = 0; i < p; i++) {
            result *= n;
        }
        return result;
    }
};

int main() {
    double n;
    int p;

    std::cout << "Enter the base value: ";
    std::cin >> n;

    std::cout << "Enter the power value: ";
    std::cin >> p;

    // Create an instance of RecursivePowerCalculator
    RecursivePowerCalculator recursiveCalculator;
    double recursiveResult = recursiveCalculator.calculatePower(n, p);

    // Create an instance of IterativePowerCalculator
    IterativePowerCalculator iterativeCalculator;
    double iterativeResult = iterativeCalculator.calculatePower(n, p);

    std::cout << "Recursive power: " << recursiveResult << std::endl;
    std::cout << "Iterative power: " << iterativeResult << std::endl;

    return 0;
}
//using friend function
#include <iostream>

using namespace std;

class PowerCalculator {
private:
    double n;

public:
    PowerCalculator(double n) : n(n) {}

    friend double power(PowerCalculator& calculator, int p);
};

double power(PowerCalculator& calculator, int p) {
    if (calculator.n == 0 && p == 0) {
        throw exception(); // Handle invalid input: n cannot be 0 when p is 0
    }

    if (p < 0) {
        throw exception(); // Handle invalid input: p cannot be negative
    }

    if (p == 0) {
        return 1.0;
    } else if (p == 1) {
        return calculator.n;
    } else {
        return calculator.n * power(calculator, p - 1);
    }
}

int main() {
    double n;
    int p;

    cout << "Enter the base value: ";
    cin >> n;

    cout << "Enter the power value: ";
    cin >> p;

    PowerCalculator calculator(n);

    try {
        double result = power(calculator, p);
        cout << "The power of " << n << " raised to " << p << " is: " << result << endl;
    } catch (exception& e) {
        cerr << "Error: Invalid input" << endl;
    }

    return 0;
}
