#include <utility>
#include <iostream>
#include <string>

struct Widget {
    Widget() { std::cout << "Widget()\n"; }
    Widget(const Widget&) { std::cout << "copy-ctor\n"; }
    Widget(Widget&&) noexcept { std::cout << "move-ctor\n"; }
};

void process(Widget w) {
    std::cout << "process(Widget)\n";
}

template<typename F, typename... Args>
auto invoke_with_log(F&& f, Args&&... args) {
    std::cout << "[LOG] before call\n";

    if constexpr (std::is_void_v<std::invoke_result_t<F, Args...>>) {
        std::forward<F>(f)(std::forward<Args>(args)...);
        std::cout << "[LOG] after call\n";
        // implicit return for void
    }
    else {
        auto result = std::forward<F>(f)(std::forward<Args>(args)...);
        std::cout << "[LOG] after call\n";
        return result;  // deduced return type
    }
}

int main() {
    Widget w;
    
    std::cout << "\n-- pass lvalue --\n";
    invoke_with_log(process, w);

    std::cout << "\n-- pass rvalue --\n";
    invoke_with_log(process, Widget{}); 
}
