#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <functional>

using namespace std;

// 抽象产品
struct HotDrink {
    virtual void prepare(int volume) = 0;
    virtual ~HotDrink() = default;
};

// 具体产品 Tea
struct Tea : HotDrink {
    void prepare(int volume) override {
        cout << "Take tea bag, boil water, pour " << volume
             << "ml, add some lemon" << endl;
    }
};

// 具体产品 Coffee
struct Coffee : HotDrink {
    void prepare(int volume) override {
        cout << "Grind beans, boil water, pour " << volume
             << "ml, add sugar and milk" << endl;
    }
};

// 用 std::function 存储工厂逻辑（现代工厂方法）
class DrinkWithVolumeFactory {
    map<string, function<unique_ptr<HotDrink>()>> factories;

public:
    DrinkWithVolumeFactory() {
        factories["tea"] = [] {
            auto tea = make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };

        factories["coffee"] = [] {
            auto coffee = make_unique<Coffee>();
            coffee->prepare(150);
            return coffee;
        };
    }

    unique_ptr<HotDrink> make_drink(const string& name) {
        return factories[name]();
    }
};

int main() {
    DrinkWithVolumeFactory factory;

    cout << "[Making Tea]\n";
    auto tea = factory.make_drink("tea");

    cout << "[Making Coffee]\n";
    auto coffee = factory.make_drink("coffee");

    return 0;
}
