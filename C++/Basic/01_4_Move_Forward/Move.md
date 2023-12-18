#### Move Semantic

先说结论：
    1. 拷贝构造函数实现的是深拷贝，传入的source是左值，该source可能在后续的代码中被使用，因此需要利用深拷贝避免数据分享造成的问题。
    2. 移动构造函数直接将资源的指针交给新的对象接管，并将右值引用的指针变量设置为0，以此实现资源的移动。 

通过一个例子来理解move语义。
先写一个简单的string类，这个类只有一个指针成员，该指针指向堆内存。
```c++
#include <cstring>
#include <algorithm>

class string
{
    char* data;

public:
    string(const char* p)
    {
        size_t size = std::strlen(p) + 1;
        data = new char[size];
        std::memcpy(data, p, size);
    }

    ~string()
    {
        delete[] data;
    }

    string(const string& source)
    {
        size_t size = std::strlen(that.data) + 1;
        data = new char[size];
        std::memcpy(data, source.data, size);
    }
}
```

目前这个类包含构造函数，析构函数和拷贝构造函数。在拷贝构造函数中，参数 `const string& source` 可以绑定所有字符串表达式。
```c++
string a(x);                            // EG1
string b(x + y);                        // EG2
string c(function_return_string());     // EG3
```

分析上年三个例子，我们发现，只有在第一个例子中我们需要深拷贝，因为变量x可能在后续的代码中还会被用到。但是在第二和第三格例子中，我们传给拷贝构造函数的不是Lvaule，而是Rvalue，换句话说，我们传入的是一个临时变量，这个变量实际上是没法取址观察的，因此，对于这样的Rvalue参数，我们可以按照需求随意修改，也不会破坏后续代码对资源的访问。

处于这种考虑，C++引入了右值引用机制，通过函数重载我们可以让代码自动识别参数是否是右值，所以拷贝构造函数也可以写成如下的形式。
```c++
string(string&& source)
{
    data = source.data;
    source.data = nullptr;
}
```
在上面的代码中，我们没有使用深度拷贝，我们只是将指针拷贝给data，然后将原来储存指针的变量设置为空，这样可以避免在调用临时变量的析构函数的时候把刚得到的数据删除掉。这样的构造函数又被成为移动构造函数，它的工作就是将一个对象的资源移动到另一个对象上。

回到我们的sting类，我们还缺少一个赋值运算符重载，该函数可以写成如下的形式。
```c++
string& operator=(string source)
{
    std::swap(data, source.data);
    return *this
}
```
关于copy and swap idiom可以参考另一篇笔记，这里重点分析为什么这样些能满足需求。
我们注意到，参数source是传值方式的，所以source是如何被初始化的呢？在新的C++标准中：
1. 如果我们传入的是一个左值，比如`a = b`，那么source会通过拷贝构造函数，通过深拷贝来初始化，在函数体中完成资源交换，离开函数体的时候被销毁。
2. 如果我们传入的是一个右值，比如`a = b + c`，那么source会通过移动构造函数被初始化，这个时候不会有任何深度拷贝发生，在函数体内部交换资源后，离开函数体的时候source被销毁。