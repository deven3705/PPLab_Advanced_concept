//using inheriantance

#include <iostream>

using namespace std;

class Person {
protected:
  string name;
  int age;

public:
  void setName(string name) {
    this->name = name;
  }

  string getName() {
    return name;
  }

  void setAge(int age) {
    this->age = age;
  }

  int getAge() {
    return age;
  }
};

class Employee : public Person {
private:
  float salary;

public:
  void setSalary(float salary) {
    this->salary = salary;
  }

  float getSalary() {
    return salary;
  }

  void display() {
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Salary: " << getSalary() << endl;
  }
};

int main() {
  Employee employees[5];

  for (int i = 0; i < 5; i++) {
    string name;
    int age;
    float salary;

    cout << "Enter name for employee " << i + 1 << ": ";
    cin >> name;

    cout << "Enter age for employee " << i + 1 << ": ";
    cin >> age;

    cout << "Enter salary for employee " << i + 1 << ": ";
    cin >> salary;

    employees[i].setName(name);
    employees[i].setAge(age);
    employees[i].setSalary(salary);
  }

  cout << endl << "Employee Information:" << endl;

  for (int i = 0; i < 5; i++) {
    employees[i].display();
    cout << endl;
  }

  return 0;
}

//using exception handling

#include <iostream>
#include <exception>

using namespace std;

class InvalidInputException : public exception {
public:
    InvalidInputException(const string& message) : message(message) {}

    const string& getMessage() const {
        return message;
    }

private:
    string message;
};

class Employee {
private:
    string name;
    int age;
    float salary;

public:
    Employee(string name, int age, float salary) {
        if (name.empty()) {
            throw InvalidInputException("Invalid input: Name cannot be empty");
        }

        if (age <= 0) {
            throw InvalidInputException("Invalid input: Age must be positive");
        }

        if (salary < 0.0f) {
            throw InvalidInputException("Invalid input: Salary must be non-negative");
        }

        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    try {
        Employee employees[5];

        for (int i = 0; i < 5; i++) {
            string name;
            int age;
            float salary;

            cout << "Enter name for employee " << i + 1 << ": ";
            getline(cin, name);

            cout << "Enter age for employee " << i + 1 << ": ";
            cin >> age;

            cout << "Enter salary for employee " << i + 1 << ": ";
            cin >> salary;

            employees[i] = Employee(name, age, salary);
        }

        cout << endl << "Employee Information:" << endl;

        for (int i = 0; i < 5; i++) {
            employees[i].display();
            cout << endl;
        }
    } catch (InvalidInputException& e) {
        cerr << "Error: " << e.getMessage() << endl;
    }

    return 0;
}

//using virtual function 
#include <iostream>

class Person {
protected:
    string name;
    int age;

public:
    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return age;
    }

    virtual void display() = 0;
};

class Employee : public Person {
private:
    float salary;

public:
    void setSalary(float salary) {
        this->salary = salary;
    }

    float getSalary() {
        return salary;
    }

    virtual void display() override {
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Salary: " << getSalary() << endl;
    }
};

int main() {
    Employee employees[5];

    for (int i = 0; i < 5; i++) {
        string name;
        int age;
        float salary;

        cout << "Enter name for employee " << i + 1 << ": ";
        cin >> name;

        cout << "Enter age for employee " << i + 1 << ": ";
        cin >> age;

        cout << "Enter salary for employee " << i + 1 << ": ";
        cin >> salary;

        employees[i] = Employee();
        employees[i].setName(name);
        employees[i].setAge(age);
        employees[i].setSalary(salary);
    }

    cout << endl << "Employee Information:" << endl;

    for (int i = 0; i < 5; i++) {
        employees[i].display();
        cout << endl;
    }

    return 0;
}

//using friend function
#include <iostream>

class Employee {
private:
    string name;
    int age;
    float salary;

friend void enterEmployeeDetails(Employee& employee);
friend void displayEmployeeDetails(const Employee& employee);

public:
    Employee() {}
};

void enterEmployeeDetails(Employee& employee) {
    cout << "Enter name: ";
    cin >> employee.name;

    cout << "Enter age: ";
    cin >> employee.age;

    cout << "Enter salary: ";
    cin >> employee.salary;
}

void displayEmployeeDetails(const Employee& employee) {
    cout << "Name: " << employee.name << endl;
    cout << "Age: " << employee.age << endl;
    cout << "Salary: " << employee.salary << endl;
}

int main() {
    Employee employees[5];

    for (int i = 0; i < 5; i++) {
        enterEmployeeDetails(employees[i]);
    }

    cout << endl << "Employee Information:" << endl;

    for (int i = 0; i < 5; i++) {
        displayEmployeeDetails(employees[i]);
        cout << endl;
    }

    return 0;
}



