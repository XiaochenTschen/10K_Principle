#### getline(file, line)
`getline(file, line)` 是C++标准库中的一个函数，用于从输入流中读取一行文本。这里的 `file` 是一个 `std::ifstream` 对象，`line` 是一个 `std::string` 对象，用于存储从文件中读取到的每一行。

当你调用 `getline(file, line)` 时，它从 `file` 指定的文件中读取字符，直到遇到换行符 `\n`，然后将这些字符（不包括换行符）存储到 `line` 中。如果文件到达末尾（EOF）或发生错误，`getline` 将设置相应的流状态标志。

#### file stream
标准库`<fstream>`提供了三个主要的文件流类：
1. `std::ifstream`: read data from file
2. `std::ofstream`: write data to file
3. `std::fstream`: read/write data from/to file

**打开文件**
使用文件流就需要打开一个文件，这个可以通过文件流对象构造函数中指定文件名来完成，或者使用`open()`成员函数。
```c++
std::ifstream inputFile("input.txt");   // open input file
std::ofstream outputFile("output.txt"); // open output file

std::fstream file;
file.open("file.txt", std::ios::in | std::ios::out); // open read/write file
```

**读取文件**
从`std::ifstream`对象或者`std::fstream`对象中读取内容，常用的方法是`>>` 或 `getline()` 函数。
```c++
std::ifstream inputFile("input.txt");
std::string line;

// 读取文件的每一行
while (getline(inputFile, line)) {
    std::cout << line << std::endl;
}

// 或者读取单个词或数值
std::string word;
inputFile >> word;
```

**写入文件**
通过`std::ofstream`对象或者`std::fstream`对象写入文件，可以通过`>>` 运算符。
```c++
std::ofstream outputFile("output.txt");

outputFile << "Hello, world!" << std::endl;
outputFile << 123 << std::endl;
```

**关闭文件**
文件流会在对象销毁时自动关闭，也可以通过显式调用`.close()`方法。

**检查文件流状态**
```c++
if (!inputFile) {
    std::cerr << "Error opening input file." << std::endl;
}

if (!outputFile) {
    std::cerr << "Error opening output file." << std::endl;
}
```