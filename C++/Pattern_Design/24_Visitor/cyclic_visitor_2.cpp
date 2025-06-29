#include <iostream>
#include <sstream>

using namespace std;

struct DoubleExpression;
struct AdditionExpression;

struct ExpressionVisitor {
    virtual void visit(DoubleExpression* de) = 0;
    virtual void visit(AdditionExpression* ae) = 0;
};

struct Expression {
    virtual void accept(ExpressionVisitor* visitor) = 0;
};

struct DoubleExpression: Expression {
    double value;
    explicit DoubleExpression(const double value)
        : value(value) {}

    void accept(ExpressionVisitor* visitor) override {
        visitor->visit(this);
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

    void accept(ExpressionVisitor* visitor) override {
        visitor->visit(this);
    }
};

struct ExpressionPrinter: ExpressionVisitor {

    void visit(DoubleExpression* de) override {
        oss << de->value;
    }

    void visit(AdditionExpression* ae) override {
        oss << "(";
        ae->left->accept(this);
        oss << "+";
        ae->right->accept(this);
        oss << ")";
    }

    string str() const { return oss.str(); }
private:
    ostringstream oss;
};

struct ExpressionEvaluator: ExpressionVisitor {

    void visit(DoubleExpression* de) override {
        result = de->value;
    }

    void visit(AdditionExpression* ae) override {
        ae->left->accept(this);
        auto tmp = result;
        ae->right->accept(this);
        result += tmp;
    }

    double result;
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
    ExpressionEvaluator ee;
    ep.visit(e);
    ee.visit(e);
    cout << ep.str() << "=" << ee.result << endl;

    return 0;
}