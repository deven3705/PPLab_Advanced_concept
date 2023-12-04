//uisng inheriantance

#include <iostream>

using namespace std;

class Shape {
public:
    virtual double getVolume() = 0;
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    double getVolume() override {
        return 3.14159 * radius * radius * height;
    }
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) : sideLength(sideLength) {}

    double getVolume() override {
        return sideLength * sideLength * sideLength;
    }
};

class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double length, double width, double height) : length(length), width(width), height(height) {}

    double getVolume() override {
        return length * width * height;
    }
};

int main() {
    Cylinder cylinder(5.0, 10.0);
    Cube cube(6.0);
    Cuboid cuboid(8.0, 4.0, 3.0);

    cout << "Volume of cylinder: " << cylinder.getVolume() << endl;
    cout << "Volume of cube: " << cube.getVolume() << endl;
    cout << "Volume of cuboid: " << cuboid.getVolume() << endl;

    return 0;
}

//uisng exception handling
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

class Shape {
public:
    virtual double getVolume() = 0;
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) {
        if (radius <= 0) {
            throw InvalidInputException("Invalid input: Radius must be positive");
        }

        if (height <= 0) {
            throw InvalidInputException("Invalid input: Height must be positive");
        }

        this->radius = radius;
        this->height = height;
    }

    double getVolume() override {
        return 3.14159 * radius * radius * height;
    }
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) {
        if (sideLength <= 0) {
            throw InvalidInputException("Invalid input: Side length must be positive");
        }

        this->sideLength = sideLength;
    }

    double getVolume() override {
        return sideLength * sideLength * sideLength;
    }
};

class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double length, double width, double height) {
        if (length <= 0) {
            throw InvalidInputException("Invalid input: Length must be positive");
        }

        if (width <= 0) {
            throw InvalidInputException("Invalid input: Width must be positive");
        }

        if (height <= 0) {
            throw InvalidInputException("Invalid input: Height must be positive");
        }

        this->length = length;
        this->width = width;
        this->height = height;
    }

    double getVolume() override {
        return length * width * height;
    }
};

int main() {
    try {
        Cylinder cylinder(5.0, 10.0);
        Cube cube(6.0);
        Cuboid cuboid(8.0, 4.0, 3.0);

        cout << "Volume of cylinder: " << cylinder.getVolume() << endl;
        cout << "Volume of cube: " << cube.getVolume() << endl;
        cout << "Volume of cuboid: " << cuboid.getVolume() << endl;
    } catch (InvalidInputException& e) {
        cerr << "Error: " << e.getMessage() << endl;
    }

    return 0;
}

//uisng friend function#include <iostream>

using namespace std;

class Shape {
public:
    virtual double calculateVolume() = 0;
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) {
        this->radius = radius;
        this->height = height;
    }

    double calculateVolume() override {
        return 3.14159 * radius * radius * height;
    }
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) {
        this->sideLength = sideLength;
    }

    double calculateVolume() override {
        return sideLength * sideLength * sideLength;
    }
};

class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double length, double width, double height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    double calculateVolume() override {
        return length * width * height;
    }
};

int main() {
    Cylinder cylinder(5.0, 10.0);
    Cube cube(6.0);
    Cuboid cuboid(8.0, 4.0, 3.0);

    cout << "Volume of cylinder: " << cylinder.calculateVolume() << endl;
    cout << "Volume of cube: " << cube.calculateVolume() << endl;
    cout << "Volume of cuboid: " << cuboid.calculateVolume() << endl;

    return 0;
}

//uisng virtual friend
#include <iostream>

using namespace std;

class Shape {
public:
    virtual double calculateVolume() = 0;
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) {
        this->radius = radius;
        this->height = height;
    }

    double calculateVolume() override {
        return 3.14159 * radius * radius * height;
    }
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) {
        this->sideLength = sideLength;
    }

    double calculateVolume() override {
        return sideLength * sideLength * sideLength;
    }
};

class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double length, double width, double height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    double calculateVolume() override {
        return length * width * height;
    }
};

int main() {
    Cylinder cylinder(5.0, 10.0);
    Cube cube(6.0);
    Cuboid cuboid(8.0, 4.0, 3.0);

    cout << "Volume of cylinder: " << cylinder.calculateVolume() << endl;
    cout << "Volume of cube: " << cube.calculateVolume() << endl;
    cout << "Volume of cuboid: " << cuboid.calculateVolume() << endl;

    return 0;
}

//using friend function

#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    friend double calculateVolume(const Shape& shape);
};

class Cylinder : public Shape {
private:
    double radius;
    double height;

public:
    Cylinder(double radius, double height) : radius(radius), height(height) {}
};

class Cube : public Shape {
private:
    double sideLength;

public:
    Cube(double sideLength) : sideLength(sideLength) {}
};

class Cuboid : public Shape {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double length, double width, double height) : length(length), width(width), height(height) {}
};

double calculateVolume(const Shape& shape) {
    if (dynamic_cast<const Cylinder*>(&shape)) {
        const Cylinder& cylinder = dynamic_cast<const Cylinder&>(shape);
        return 3.14159 * cylinder.radius * cylinder.radius * cylinder.height;
    } else if (dynamic_cast<const Cube*>(&shape)) {
        const Cube& cube = dynamic_cast<const Cube&>(shape);
        return cube.sideLength * cube.sideLength * cube.sideLength;
    } else if (dynamic_cast<const Cuboid*>(&shape)) {
        const Cuboid& cuboid = dynamic_cast<const Cuboid&>(shape);
        return cuboid.length * cuboid.width * cuboid.height;
    } else {
        return 0.0;
    }
}

int main() {
    Cylinder cylinder(5.0, 10.0);
    Cube cube(6.0);
    Cuboid cuboid(8.0, 4.0, 3.0);

    cout << "Volume of cylinder: " << calculateVolume(cylinder) << endl;
    cout << "Volume of cube: " << calculateVolume(cube) << endl;
    cout << "Volume of cuboid: " << calculateVolume(cuboid) << endl;

    return 0;
}





