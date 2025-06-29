`
### Type

#### decltype
`decltype(expr)` 可以在编译器根据表达式 `expr` 的 **精确类型** 和 **值类别** 推导出一个类型。不管 `expr` 是左值，右值，xvalue，`decltype` 都能区分并且保留。

decltype 推导类型时有三条核心规则：

    1. 如果表达式恰好是“未被括号包裹的标识符（id‐expression），且指向一个命名变量，decltype(e) 就是该变量的声明类型（不添加 &）。
    2. 否则，如果 e 是一个左值表达式，decltype(e) 就是 “T&”——也就是指向该表达式类型的左值引用。
    3. 如果 e 是一个纯右值（prvalue），decltype(e) 就是 “T”（不带引用）

```c++
int  x = 0;
int& y = x;
int&& z = 5;

decltype(x) a;        // int
decltype((x)) b = x;  // int&，注意双括号让 expr 成为“lvalue expr”
decltype(y) c = x;    // int&
decltype(z) d = 6;    // int&&
decltype(x + 1) d;     // x+1 是 prvalue → decltype(x+1) = int
```

#### using
`using` 除了在命名空间导入上的用法外，还在类型别名的定义方面取代了之前的 `typedef`.

```c++
// C++98 的写法
typedef std::map<std::string, std::vector<int>> MapType;
// C++11 起更直观的写法
using MapType = std::map<std::string, std::vector<int>>;

template<typename T>
using Vec = std::vector<T>;
Vec<int> v;  // 等价于 std::vector<int> v;

// 传统 typedef 写法
typedef int (*FuncPtr1)(char, double);
// using 别名写法
using FuncPtr2 = int (*)(char, double);
int foo(char c, double d) { return int(c) + int(d); }
FuncPtr2 p = &foo;     // 或直接 p = foo;
int  r = p('A', 3.14);
```

#### typename
`typename` 是c++保留的 **关键字**，在模板上下文中主要有两种用法：

1. 等价于 `class`，在模板参数列表中声明参数类型。
2. 在嵌套类型中用来指示某个成员是一个类型，而不是静态成员。

```c++
template<typename T>
struct Wrapper {
  // 1. 在这里，T::value_type 是依赖于 T 的嵌套名，
  //    编译期无法确定它是类型还是静态成员，需要 typename 指示
  typename T::value_type member;

  // 2. 下面两者等价：
  template<typename U> void foo(U);
  template<class U>    void bar(U);
};
```

### Tailing Return Type
```c++
// 普通写法：C++98/03
int add(int a, int b) {
  return a + b;
}

// C++11 后置返回类型
auto add(int a, int b) -> int {
  return a + b;
}
```
auto 在这里不是指“编译器自动推导返回类型”，而是占位符，真正的返回类型写在箭头 -> 后面。
这种写法在简单函数里并没太大必要，但在模板或依赖于模板参数的返回类型时，非常有用。

### Nested Type
嵌套类型，也叫做类型成员，是指一个类或结构体内部用 `typedef` 或 `using` 定义出来的类型别名，它和普通的数据成员或函数成员一样，是类定义的一部分，值是这个成员是一个类型而不是一个值。

```c++
struct MyContainer {
    using value_type = int;    
}
MyContainer::value_type x = 42;  // x 的类型就是 int

template<typename Container>
void func() {
    typename Container::value_type x;  
    // typename 强调“这是个类型”，否则编译器当它可能是个静态成员变量，会报错
    x = /* … */;
}

```