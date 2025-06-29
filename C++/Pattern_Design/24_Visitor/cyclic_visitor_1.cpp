#include <iostream>

class IVisitor {
public:
    virtual void visit(class Circle* c) = 0;
    virtual void visit(class Rectangle* c) = 0;
};

class IShap {
public:
    virtual void accept(IVisitor* v) = 0;
};

class Circle: public IShap {
public:
    void accept(IVisitor* v) override {
        v->visit(this);
    }
};

class Rectangle: public IShap {
public:
    void accept(IVisitor* v) override {
        v->visit(this);
    }
};

class DrawVisitor: public IVisitor {
public:
    void visit(Circle* c) {
        std::cout << "Drawing a Circle\n";
    }
    void visit(Rectangle* c) {
        std::cout << "Drawing a Rectangle\n";
    }
};

int main(void) {
    auto shape = new Circle();
    DrawVisitor visitor;

    visitor.visit(shape);

    return 0;
}