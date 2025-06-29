#include <iostream>
#include <string>

// Prototype interface
class Resume {
public:
    virtual Resume* clone() const = 0;  // interface
    virtual void show() const = 0;
    virtual ~Resume() {}
};
    
class PersonalResume : public Resume {
private:
    std::string name;
    std::string gender;
    int age;

public:
    PersonalResume(const std::string& n, const std::string& g, int a)
        : name(n), gender(g), age(a) {}

    // copy constructor
    PersonalResume(const PersonalResume& other)
        : name(other.name), gender(other.gender), age(other.age) {}

    Resume* clone() const override {
        return new PersonalResume(*this);  // use the copy constructor
    }

    void show() const override {
        std::cout << "Name: " << name << ", Gender: " << gender << ", Age: " << age << std::endl;
    }
};

int main() {
    PersonalResume* original = new PersonalResume("Alice", "Female", 30);

    Resume* copy1 = original->clone();
    Resume* copy2 = original->clone();

    std::cout << "Original: ";
    original->show();

    std::cout << "Copy 1: ";
    copy1->show();

    std::cout << "Copy 2: ";
    copy2->show();

    delete original;
    delete copy1;
    delete copy2;

    return 0;
}
