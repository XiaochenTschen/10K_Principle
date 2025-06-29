#include <iostream>
#include <memory>
#include <string>
#include <map>

using namespace std;

// 抽象产品
struct HotDrink {
    virtual void prepare(int volume) = 0;
    virtual ~HotDrink() = default;
};

// 具体产品：Tea
struct Tea : HotDrink {
    void prepare(int volume) override {
        cout << "Take tea bag, boil water, pour " << volume
             << "ml, add some lemon" << endl;
    }
};

// 具体产品：Coffee
struct Coffee : HotDrink {
    void prepare(int volume) override {
        cout << "Grind beans, boil water, pour " << volume
             << "ml, add sugar and milk" << endl;
    }
};

// 简单工厂函数（不推荐长期使用）
unique_ptr<HotDrink> make_drink_simple(string type) {
    unique_ptr<HotDrink> drink;
    if (type == "tea") {
        drink = make_unique<Tea>();
        drink->prepare(200);
    } else {
        drink = make_unique<Coffee>();
        drink->prepare(50);
    }
    return drink;
}

// 工厂接口
struct HotDrinkFactory {
    virtual unique_ptr<HotDrink> make() const = 0;
    virtual ~HotDrinkFactory() = default;
};

// Coffee 工厂
struct CoffeeFactory : HotDrinkFactory {
    unique_ptr<HotDrink> make() const override {
        return make_unique<Coffee>();
    }
};

// Tea 工厂
struct TeaFactory : HotDrinkFactory {
    unique_ptr<HotDrink> make() const override {
        return make_unique<Tea>();
    }
};

// 工厂集合类
class DrinkFactory {
    map<string, unique_ptr<HotDrinkFactory>> hot_factories;

public:
    DrinkFactory() {
        hot_factories["coffee"] = make_unique<CoffeeFactory>();
        hot_factories["tea"] = make_unique<TeaFactory>();
    }

    unique_ptr<HotDrink> make_drink(const string& name, int volume) {
        auto drink = hot_factories[name]->make();
        drink->prepare(volume);
        return drink;
    }
};

int main() {
    // 用简单工厂方式创建
    auto d1 = make_drink_simple("tea");

    // 用抽象工厂方式创建
    DrinkFactory factory;
    auto d2 = factory.make_drink("coffee", 150);

    return 0;
}
