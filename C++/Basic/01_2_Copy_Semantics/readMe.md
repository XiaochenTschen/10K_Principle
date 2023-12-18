### Copy Semantics
拷贝语义(copy semantics)，从实现上来说可以分为两种，浅拷贝(shallow copy)和深拷贝(deep copy)。
就目前的理解而言，深拷贝和浅拷贝的区别在于，堆区的成员变量在不同的对象之间是否是独立的。

#### Shallow Copy
简而言之，浅拷贝就是将所有地对象进行一比一地拷贝。对于栈区地对象来说，浅拷贝不会有什么问题，因为源对象和拷贝对象是互相独立的。但是对于堆区，比如指针类型的类成员，浅拷贝是将指针进行了一比一赋值，其作用效果如下图所示。
![BoatGauges Display](.\Build\Shallow_Copy_Shared_Heap.JPG)
图片来源: [https://www.udacity.com/blog/2022/12/master-c-copy-semantics.html](https://www.udacity.com/blog/2022/12/master-c-copy-semantics.html)

显而易见，进行浅拷贝的时候会有数据访问冲突的问题。如果在设计程序的时候，浅拷贝需要避免的话，就需要使用深拷贝。

#### Deep Copy
相对于浅拷贝，深拷贝会在拷贝过程中在堆区预留一份拷贝空间，用来储存堆区变量的副本，这样就和原式的数据区分开来，避免访问冲突。
![BoatGauges Display](.\Build\Deep_Copy_Shared_Heap.JPG)
图片来源: [https://www.udacity.com/blog/2022/12/master-c-copy-semantics.html](https://www.udacity.com/blog/2022/12/master-c-copy-semantics.html)

#### Rule of Three
当实现一个类的时候，如果不明确指定拷贝类型的话，编译器会默认使用浅拷贝。如果我们需要使用深拷贝，那么有三个成员函数需要用户自己实现。

1. 析构函数 destructor
```c++ 
~MyClass()
```
在析构函数里需要实现，当类实例被销毁的时候，堆成员变量需要进行什么样的操作，同样被销毁还是保存在堆中。

2. 拷贝构造函数 copy constructor
```c++ 
MyClass(const MyClass &source)
```
当对一个对象进行拷贝的时候，对象不能被修改，因此这里使用了const引用。

3. 拷贝赋值函数 copy assignment operator
```c++ 
MyClass &operator=(const MyClass &source)
```