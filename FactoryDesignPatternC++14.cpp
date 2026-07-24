#include <iostream>
#include <memory>
#include <string>

// Base interface
class Shape {
public:
    virtual void draw() const = 0;   // pure virtual function
    virtual ~Shape() = default;      // virtual destructor
};

// Concrete classes
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle\n";
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Square\n";
    }
};

class Triangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Triangle\n";
    }
};

// Factory class
class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "circle") {
            return std::make_unique<Circle>();
        } else if (type == "square") {
            return std::make_unique<Square>();
        } else if (type == "triangle") {
            return std::make_unique<Triangle>();
        }
        return nullptr;
    }
};

// Client code
int main() {
    auto shape1 = ShapeFactory::createShape("circle");
    auto shape2 = ShapeFactory::createShape("square");
    auto shape3 = ShapeFactory::createShape("triangle");

    if (shape1) shape1->draw();
    if (shape2) shape2->draw();
    if (shape3) shape3->draw();

    return 0;
}
