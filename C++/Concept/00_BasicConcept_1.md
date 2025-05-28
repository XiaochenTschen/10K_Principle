`
#### List Initialization

C++11开始引入了列表初始化(list initialization)的概念，允许使用花括号直接给对象初始化。

```c 
T obj{arg1, arg2, ...};
T obj{ {...} } // 嵌套花括号，用于聚合类型(aggregates)

struct Point { double x, y };
Point p1{1.0, 2.0};

int arr[3]{10, 20, 30};

std::vector<int> v{1, 2, 3, 4, 5};
std::map<std::string, int> m{
    {"one", 1}, {"two", 2}, {"three", 3}
};
```

列表初始化禁止窄化转换(narrowing conversion)，比如把double赋值给int会报错。
窄化转换是指将一个数值类型转换为另一个更狭窄的类型时，会丢失信息或精度的情形。

拷贝列表初始化(copy list initialization)语法上就是在声明的时候带上等号。

```c 
T obj = {arg1, arg2, ...};
```

如果类型T有一个explicit的构造函数，直接初始化列表可以直接调用它，但是拷贝列表初始化不行。

#### Structured Binding
结构化绑定是C++17引入的语法糖，允许对一个聚合对象进行拆包到若干变量中，写法上也用花括号。

```c 
// 1. 拆解 std::pair
std::pair<int,std::string> pr{42, "hello"};
auto [id, text] = pr;   // id == 42, text == "hello"，拷贝
auto& [id, text] = pr;  // 可变引用
const auto& [id, text] = pr;  // 只读引用

// 2. 拆解 std::tuple
std::tuple<int,double,char> tp{1, 2.5, 'x'};
auto [n, d, ch] = tp;    // n==1, d==2.5, ch=='x'

// 3. 拆解原生数组
int arr[3] = {10, 20, 30};
auto [x0, x1, x2] = arr; // x0==10, x1==20, x2==30

// 4. 拆解自定义聚合
struct Point { double x, y; };
Point p{3.0, 4.0};
auto [px, py] = p;       // px==3.0, py==4.0
```