#include <utility>
#include <iostream>
#include <string>

// 1. 目标函数：一个可以区分拷贝 vs 移动的操作
struct Widget {
  Widget() { std::cout << "Widget()\n"; }
  Widget(const Widget&) { std::cout << "copy-ctor\n"; }
  Widget(Widget&&) noexcept { std::cout << "move-ctor\n"; }
};

void process(Widget w) {
  std::cout << "process(Widget)\n";
}

// 2. 完美转发包装器
template<typename F, typename... Args>
auto invoke_with_log(F&& f, Args&&... args)
  -> decltype(std::forward<F>(f)(std::forward<Args>(args)...))
{
  std::cout << "[LOG] before call\n";
  // 完美转发：保留 f 与 args 的左/右值属性
  auto result = std::forward<F>(f)(std::forward<Args>(args)...);
  std::cout << "[LOG] after call\n";
  return result;
}

int main() {
  Widget w;                    // 默认构造
 
  std::cout << "\n-- 传左值 --\n";
  invoke_with_log(process, w); // w 是左值，传给 process(Widget w) 会调用拷贝 ctor

  std::cout << "\n-- 传右值 --\n";
  invoke_with_log(process, Widget{}); 
  // Widget{} 是 prvalue，传给 process(Widget w) 会调用移动 ctor
}
