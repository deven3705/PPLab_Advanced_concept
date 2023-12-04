// ************************************************************ Inheritance *************************************************************
#include <iostream>

using namespace std;

class BaseException : public exception {
public:
    BaseException(const string& message) : message(message) {}

    virtual const string& what() const override {
        return message;
    }

private:
    string message;
};

class DerivedException : public BaseException {
public:
    DerivedException(const string& message) : BaseException(message) {}
};

class Person {
public:
    void validateAge(int age) {
        if (age < 0 || age > 120) {
            throw DerivedException("Invalid age: " + to_string(age));
        }
    }
};

class Employee : public Person {
public:
    void validateEmployee(int age, const string& title) {
        Person::validateAge(age);
        if (title.empty()) {
            throw BaseException("Employee must have a title");
        }
    }
};

int main() {
    try {
        Employee employee;
        employee.validateEmployee(-1, "");
    } catch (const BaseException& e) {
        cout << "Base exception: " << e.what() << endl;
    } catch (const DerivedException& e) {
        cout << "Derived exception: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Unexpected exception: " << e.what() << endl;
    }

    return 0;
}


// ************************************************************ Exception Handling *************************************************************
#include<iostream>
using namespace std;

class Exp_handling
{
private:
    int age, vehicle;
    long double income;
    string city;

public:
    void getdata()
    {
        cout << "Enter the age :" << endl;
        cin >> age;
        cout << "Enter total no. of vehicle wheels :" << endl;
        cin >> vehicle;
        cout << "Enter the income :" << endl;
        cin >> income;
        cout << "Enter the city :" << endl;
        cin >> city;
    }

    void check()
    {
        try
        {
            if (age < 18 || age > 55)
            {
                throw "Age should be between 18-55";
            }
        }
        catch (const char *res)
        {
            cerr << res << endl;
        }

        try
        {
            if (income < 50000 || income > 100000)
            {
                throw "Income should be between 50,000 and 1,00,000";
            }
        }
        catch (const char *res)
        {
            cerr << res << endl;
        }

        try
        {
            if (!(city == "Pune" || city == "pune" || city == "Mumbai" || city == "mumbai" || city == "chennai" ||
                  city == "Chennai" || city == "delhi" || city == "Delhi"))
            {
                throw "City should be delhi/pune/mumbai/chennai";
            }
        }
        catch (const char *res)
        {
            cerr << res << endl;
        }

        try
        {
            if (vehicle != 4)
            {
                throw "User must have 4 wheeler";
            }
        }
        catch (const char *res)
        {
            cerr << res << endl;
        }
    }
};

int main()
{
    Exp_handling a;
    a.getdata();
    a.check();
    return 0;
}


// ************************************************************ Friend Function *************************************************************
#include <iostream>

using namespace std;

class Data {
private:
    int value;

public:
    Data(int value) : value(value) {}

    friend void validateData(Data& data) {
        if (data.value < 0) {
            throw invalid_argument("Data value cannot be negative");
        }
    }

    void print() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    try {
        Data data(-10); // Data value is negative
        validateData(data);
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}


// ************************************************************ Virtual Function *************************************************************
#include <iostream>

using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getArea() const override {
        if (radius <= 0) {
            throw invalid_argument("Radius must be positive");
        }

        return radius * radius * 3.14159;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double getArea() const override {
        if (length <= 0 || width <= 0) {
            throw invalid_argument("Length and width must be positive");
        }

        return length * width;
    }
};

int main() {
    try {
        Shape* shapes[] = {new Circle(-1), new Rectangle(-2, 3)};

        for (Shape* shape : shapes) {
            cout << "Area: " << shape->getArea() << endl;
            delete shape;
        }
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
