#include <iostream>
#include <sstream>

using namespace std;

template <typename Visitable>
struct Visitor {
    virtual void visit(Visitable& obj) = 0;
};

struct VisitorBase {
    virtual ~VisitorBase() = default;
};

struct Expression {
    virtual ~Expression() = default;

    // 非循环 Visitor：accept 只负责尝试 cast 到对应 Visitor
    virtual void accept(VisitorBase& obj) {
        using EV = Visitor<Expression>;
        if(auto ev = dynamic_cast<EV*>(&obj)) {
            ev->visit(*this);
        }
    }
};

struct DoubleExpression: Expression {
    double value;
    explicit DoubleExpression(const double value)
        : value(value) {}

    void accept(VisitorBase& obj) override {
        using DE = Visitor<DoubleExpression>;
        if(auto dv = dynamic_cast<DE*>(&obj)) {
            dv->visit(*this);
        }
    }
};

struct AdditionExpression : Expression {
    Expression *left, *right;

    AdditionExpression(Expression* const left, Expression* const right)
        : left(left), right(right) {}

    ~AdditionExpression() {
        delete left;
        delete right;
    }

    void accept(VisitorBase& obj) override {
        using AE = Visitor<AdditionExpression>;
        if(auto av = dynamic_cast<AE*>(&obj)) {
            av->visit(*this);
        }
    }
};

struct ExpressionPrinter: VisitorBase, Visitor<DoubleExpression>, Visitor<AdditionExpression> {
    void visit(DoubleExpression &obj) override {
        oss << obj.value;
    }
    void visit(AdditionExpression &obj) override {
        oss << "(";
        obj.left->accept(*this);
        oss << "+";
        obj.right->accept(*this);
        oss << ")\n";
    }

    string str() const {return oss.str();}
private:
    ostringstream oss;
};

int main(void) {
    auto e = new AdditionExpression(
        new DoubleExpression{1},
        new AdditionExpression(
            new DoubleExpression{2},
            new DoubleExpression{3}
        )
    );

    ExpressionPrinter ep;
    ep.visit(*e);
    e->accept(ep);
    cout << ep.str() << endl;

    return 0;
}