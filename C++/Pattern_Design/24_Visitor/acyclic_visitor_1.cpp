#include <iostream>

class VisitorBase {
public:
    virtual ~VisitorBase() = default;
};

class Circle;
class Rectangle;

// 针对每种元素定义一个独立的访问接口
class CircleVisitor {
public:
    virtual void visit(Circle* c) = 0;
};

class RectangleVisitor {
public:
    virtual void visit(Rectangle* r) = 0;
};

class Shape {
public:
    virtual void accept(VisitorBase* v) = 0;
};

class Circle : public Shape {
public:
    void accept(VisitorBase* v) override {
        if (auto cv = dynamic_cast<CircleVisitor*>(v)) {
            cv->visit(this);
        }
    }
};

class Rectangle : public Shape {
public:
    void accept(VisitorBase* v) override {
        if (auto rv = dynamic_cast<RectangleVisitor*>(v)) {
            rv->visit(this);
        }
    }
};

class DrawVisitor : public VisitorBase, public CircleVisitor {
public:
    void visit(Circle* c) override {
        std::cout << "Drawing a circle\n";
    }
    // 不实现 RectangleVisitor，则不处理 Rectangle
};

int main() {
    auto s =  new Circle();
    DrawVisitor dv;
    dv.visit(s);
}
    
    