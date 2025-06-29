#include <iostream>

struct Foo;
struct Bar;
void func(Foo* foo);
void func(Bar* bar);

struct Stuff {
    virtual void call() = 0;
};

struct Foo : Stuff {
    void call() override {
        func(this);
    }
};

struct Bar : Stuff {
    void call() override {
        func(this);
    }
};

void func(Foo* foo) {
    std::cout << "calling func with Foo\n";
}

void func(Bar* bar) {
    std::cout << "calling func with Bar\n";
}

int main() {
    Stuff* s = new Foo;
    // dispatch: find the right object-> Foo
    // then find the right func
    s->call();

    return 0;
}