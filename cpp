// C++知识大全——千行代码入门C++
// 编译环境：C++17及以上

/* 数据类型与运算 -----------------------------------------------------------*/

// 基本数据类型
#include <iostream>
#include <typeinfo>
using namespace std;

// 数值类型
void numeric_types() {
    // 整数类型
    char c = 'A';          // 8位，-128~127或0~255（无符号）
    short s = 100;        // 16位
    int i = 10000;        // 32位
    long l = 100000L;     // 至少32位
    long long ll = 1e18;  // 64位
    unsigned int ui = 42; // 无符号整数
    
    // 浮点类型
    float f = 3.14f;      // 32位，6~7位有效数字
    double d = 3.1415926; // 64位，15~17位有效数字
    long double ld = 3.141592653589793238L; // 80/128位
    
    // 布尔类型
    bool b1 = true;       // 1
    bool b2 = false;      // 0
    cout << "sizeof(bool): " << sizeof(b2) << endl; // 1字节
}

// 复合数据类型
struct Point {          // 结构体
    int x, y;
};

class Vector {          // 类（引用类型）
public:
    double x, y;
};

enum Color { RED, GREEN, BLUE }; // 枚举类型

// 类型转换
void type_conversion() {
    int a = 10;
    double b = (double)a;       // C风格转换
    float c = static_cast<float>(a); // 静态转换
    int* ptr = &a;
    int val = reinterpret_cast<int>(ptr); // 重解释转换
    const int& ref = a;
    int& non_const_ref = const_cast<int&>(ref); // 常量转换
}

// 运算符
void operators() {
    int a = 5, b = 3;
    cout << "算术运算: " << a + b << " " << a * b << " " << a / b << endl; // 1 2 1
    cout << "逻辑运算: " << (a > b) << " " << (a && b) << endl; // 1 1
    cout << "位运算: " << (a & b) << " " << (a | b) << endl; // 1 7
    
    int c = 5;
    cout << "自增自减: " << c++ << " " << ++c << endl; // 5 7
    
    int d = (a > b) ? a : b; // 三元运算符
}

/* 流程控制 -----------------------------------------------------------*/

// 条件语句
void if_statement() {
    int score = 85;
    if (score >= 90) {
        cout << "A" << endl;
    } else if (score >= 80) {
        cout << "B" << endl;
    } else {
        cout << "C" << endl;
    }
}

// 循环语句
void loops() {
    // for循环
    for (int i = 0; i < 5; i++) {
        cout << i << " "; // 0 1 2 3 4
    }
    
    // while循环
    int j = 0;
    while (j < 3) {
        cout << j << " "; // 0 1 2
        j++;
    }
    
    // do-while循环
    int k = 0;
    do {
        cout << k << " "; // 0 1 2 3 4
        k++;
    } while (k < 5);
    
    // C++11范围for
    int arr[] = {1, 2, 3, 4, 5};
    for (int num : arr) {
        cout << num << " "; // 1 2 3 4 5
    }
}

// 跳转语句
void jumps() {
    for (int i = 0; i < 5; i++) {
        if (i == 3) break; // 跳出循环
        if (i == 2) continue; // 跳过当前迭代
        cout << i << " "; // 0 1 3 4（注意：i=2时跳过）
    }
    
    // goto（谨慎使用）
    int flag = 0;
    start:
    if (flag < 2) {
        cout << flag << " "; // 0 1
        flag++;
        goto start;
    }
}

/* 函数与lambda -----------------------------------------------------------*/

// 函数定义
int add(int a, int b = 10) { // 默认参数
    return a + b;
}

// 函数重载
double add(double a, double b) {
    return a + b;
}

// 可变参数（C++11）
#include <initializer_list>
double average(initializer_list<double> nums) {
    double sum = 0;
    for (auto num : nums) sum += num;
    return sum / nums.size();
}

// lambda表达式
void lambda() {
    auto square = [](int x) { return x * x; }; // 无捕获
    cout << square(5) << endl; // 25
    
    int factor = 2;
    auto multiply = [factor](int x) { return x * factor; }; // 值捕获
    cout << multiply(3) << endl; // 6
    
    auto add = [&factor](int x) { factor += x; return factor; }; // 引用捕获
    cout << add(5) << endl; // factor=7
}

/* 数组与指针 -----------------------------------------------------------*/

// 数组
void arrays() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "数组大小: " << sizeof(arr) << endl; // 20（4*5）
    
    // 二维数组
    int matrix[3][2] = {{1,2}, {3,4}, {5,6}};
    cout << matrix[1][1] << endl; // 4
}

// 指针
void pointers() {
    int a = 42;
    int* ptr = &a;
    cout << "*ptr: " << *ptr << endl; // 42
    
    // 指针运算
    int arr[3] = {10, 20, 30};
    cout << *(ptr + 1) << endl; // 20（注意：需指向数组）
    
    // 空指针
    int* null_ptr = nullptr; // C++11 nullptr
}

// 引用
void references() {
    int a = 10;
    int& ref = a; // 引用必须初始化
    ref = 20;
    cout << a << endl; // 20
    
    // 常量引用
    const int& cref = a; // 不能通过cref修改a
}

/* 类与对象 -----------------------------------------------------------*/

// 类定义
class Circle {
private:
    double radius;
public:
    // 构造函数
    Circle(double r = 1.0) : radius(r) {}
    
    // 成员函数
    double area() const { // 常量成员函数
        return 3.14159 * radius * radius;
    }
    
    // 运算符重载
    Circle operator+(const Circle& other) {
        return Circle(radius + other.radius);
    }
};

// 继承
class Shape {
public:
    virtual void draw() { // 虚函数（多态）
        cout << "Drawing shape" << endl;
    }
};

class Rectangle : public Shape { // 公有继承
public:
    void draw() override { // C++11 override关键字
        cout << "Drawing rectangle" << endl;
    }
};

// 模板类
template <typename T>
class Container {
private:
    T data;
public:
    Container(T d) : data(d) {}
    T get() { return data; }
};

/* 内存管理 -----------------------------------------------------------*/

// 动态内存
void dynamic_memory() {
    int* ptr = new int(42); // 分配单个对象
    delete ptr;
    
    int* arr_ptr = new int[5]{1,2,3,4,5}; // 分配数组
    delete[] arr_ptr;
    
    // 智能指针（C++11）
    #include <memory>
    unique_ptr<int> u_ptr(new int(10)); // 独占所有权
    shared_ptr<Circle> s_ptr(new Circle(2.0)); // 共享所有权（引用计数）
}

/* STL容器与算法 -----------------------------------------------------------*/

// vector
void vector_demo() {
    #include <vector>
    vector<int> nums = {1, 2, 3, 4, 5};
    nums.push_back(6); // 尾部添加
    cout << nums.front() << " " << nums.back() << endl; // 1 6
    
    // 迭代器
    for (auto it = nums.begin(); it != nums.end(); it++) {
        cout << *it << " "; // 1 2 3 4 5 6
    }
}

// map
void map_demo() {
    #include <map>
    map<string, int> scores = {{"Alice", 90}, {"Bob", 85}};
    scores["Charlie"] = 80; // 添加元素
    cout << scores["Alice"] << endl; // 90
    
    // 范围for遍历
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// 算法
void stl_algorithms() {
    #include <algorithm>
    int arr[] = {3, 1, 4, 1, 5, 9};
    sort(arr, arr + 6); // 排序
    cout << "排序后: ";
    for (int num : arr) cout << num << " "; // 1 1 3 4 5 9
    
    bool exists = find(arr, arr + 6, 4) != end(arr); // 查找
    cout << "\n4存在: " << exists << endl; // 1
}

/* 输入输出流 -----------------------------------------------------------*/

// 标准IO
void io_demo() {
    // 输出
    cout << "Hello, C++!" << endl;
    cout << "十六进制: " << hex << 255 << endl; // ff
    
    // 输入
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "You entered: " << num << endl;
}

// 文件IO
void file_io() {
    #include <fstream>
    ofstream out_file("data.txt"); // 写文件
    if (out_file.is_open()) {
        out_file << "Line 1\nLine 2";
        out_file.close();
    }
    
    ifstream in_file("data.txt"); // 读文件
    string line;
    while (getline(in_file, line)) {
        cout << line << endl;
    }
    in_file.close();
}

/* 异常处理 -----------------------------------------------------------*/

// 自定义异常
class OutOfRange : public exception {
public:
    const char* what() const noexcept override {
        return "Out of range error";
    }
};

void exception_handling() {
    try {
        int age;
        cout << "Enter age: ";
        cin >> age;
        if (age < 0 || age > 150) {
            throw OutOfRange(); // 抛出异常
        }
    } catch (const OutOfRange& e) { // 捕获异常
        cout << "Error: " << e.what() << endl;
    } catch (...) { // 捕获所有异常
        cout << "Unknown error" << endl;
    }
}

/* C++11新特性 -----------------------------------------------------------*/

// auto类型推导
void auto_demo() {
    auto x = 42; // int
    auto y = 3.14; // double
    auto it = vector<int>().begin(); // 迭代器类型
}

// 右值引用与move语义
void rvalue_references() {
    string s1 = "Hello";
    string s2 = move(s1); // 转移所有权，s1变为空
    cout << s2 << endl; // Hello
}

// 范围for
void range_for() {
    vector<int> nums = {1, 2, 3, 4, 5};
    for (int& num : nums) { // 引用避免拷贝
        num *= 2;
    }
}

/* 综合示例 -----------------------------------------------------------*/

// 计算阶乘（递归+模板）
template <typename T>
T factorial(T n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

// 复数类
class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    Complex operator*(const Complex& other) {
        return Complex(real*other.real - imag*other.imag, real*other.imag + imag*other.real);
    }
    friend ostream& operator<<(ostream& os, const Complex& c) {
        return os << "(" << c.real << ", " << c.imag << ")";
    }
};

int main() {
    // 数据类型示例
    numeric_types();
    
    // 流程控制示例
    if_statement();
    loops();
    jumps();
    
    // 函数与lambda示例
    cout << add(5) << endl; // 15（使用默认参数）
    lambda();
    
    // 类与对象示例
    Circle c1(2.0), c2(3.0);
    cout << "Area: " << c1.area() << endl; // 12.5664
    Circle c3 = c1 + c2;
    cout << "Radius sum: " << c3.area() << endl; // 78.5398（半径5）
    
    // STL示例
    vector_demo();
    map_demo();
    stl_algorithms();
    
    // 异常处理示例
    exception_handling();
    
    // 模板示例
    cout << "Factorial of 5: " << factorial(5) << endl; // 120
    
    // 复数运算
    Complex c(3, 4), d(5, 12);
    cout << "Product: " << c * d << endl; // (-33, 56)
    
    return 0;
}


代码结构说明：
数据类型：涵盖基本类型（数值、布尔）、复合类型（结构体、类、枚举）、类型转换（4 种强制转换）
流程控制：条件语句（if-else）、循环（for/while/do-while/ 范围 for）、跳转语句（break/continue/goto）
函数：默认参数、函数重载、可变参数（initializer_list）、lambda 表达式（值捕获 / 引用捕获）
类与对象：封装（访问控制）、继承（公有继承）、多态（虚函数 /override）、模板类
内存管理：动态内存分配（new/delete）、智能指针（unique_ptr/shared_ptr）
STL：常用容器（vector/map）、迭代器、算法（sort/find）
输入输出：标准 IO（cout/cin）、文件 IO（ofstream/ifstream）
异常处理：自定义异常类、try-catch 捕获机制
C++11 特性：auto 类型推导、右值引用（move）、范围 for 循环
综合示例：模板函数（阶乘）、运算符重载（复数乘法）






-------------------------

/*C++知识大全：从基础到高级语法全涵盖*/
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

/*--------基础语法--------*/
void basicSyntax() {
    // 基本数据类型
    int num = 10;           // 32位整数
    double pi = 3.14159;    // 双精度浮点
    bool flag = true;       // 布尔类型
    char ch = 'A';          // 字符类型
    auto var = 3.14f;       // 自动类型推导（float）

    // 类型转换
    int i = static_cast<int>(pi); // 静态类型转换（推荐）
    void* p = &num;
    int* ip = reinterpret_cast<int*>(p); // 强制类型转换

    // 运算符
    int x = 10, y = 3;
    cout << "10 / 3 = " << x/y << endl;  // 整数除法
    cout << "10 % 3 = " << x%y << endl;  // 取模运算
}

/*--------控制结构--------*/
void controlFlow() {
    // 条件语句
    int score = 85;
    if (score > 90) {
        cout << "A" << endl;
    } else if (score > 75) {
        cout << "B" << endl;  // 输出B
    } else {
        cout << "C" << endl;
    }

    // 循环结构
    for(int i=0; i<5; ++i) { // 传统for循环
        cout << i << " ";
    }
    cout << endl;

    vector<int> vec{1,2,3,4,5};
    for(auto& n : vec) {     // 范围for循环（C++11）
        cout << n*2 << " ";
    }
    cout << endl;

    int j = 3;
    while(j-- > 0) {         // while循环
        cout << j << " ";
    }
}

/*--------函数--------*/
// 函数重载
void print(int a) { cout << "int: " << a << endl; }
void print(double a) { cout << "double: " << a << endl; }

// 默认参数（必须从右往左设置）
int sum(int a, int b=0, int c=0) {
    return a + b + c;
}

// 模板函数
template<typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

/*--------面向对象--------*/
class Animal {
protected:
    string name;
public:
    // 构造函数
    Animal(string n) : name(n) {}  // 初始化列表
    
    // 虚函数（多态基础）
    virtual void speak() { 
        cout << name << " makes sound" << endl;
    }
    
    // 纯虚函数（抽象类）
    virtual void move() = 0;
    
    // 析构函数
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    
    void speak() override {  // 重写虚函数
        cout << name << " says: Wang Wang!" << endl;
    }
    
    void move() override {
        cout << name << " running on four legs" << endl;
    }
};

/*--------模板编程--------*/
template<typename T>
class MyArray {
private:
    T* data;
    int size;
public:
    MyArray(int s) : size(s) {
        data = new T[size];
    }
    
    T& operator[](int index) {  // 运算符重载
        return data[index];
    }
    
    ~MyArray() {
        delete[] data;
    }
};

/*--------智能指针（C++11）--------*/
void smartPointerDemo() {
    unique_ptr<int> uptr(new int(10)); // 独占所有权
    shared_ptr<int> sptr = make_shared<int>(20); // 共享所有权
    weak_ptr<int> wptr = sptr; // 弱引用
}

/*--------STL容器--------*/
void stlDemo() {
    vector<string> fruits{"apple", "banana", "cherry"};
    fruits.push_back("orange");
    
    // 迭代器遍历
    for(auto it=fruits.begin(); it!=fruits.end(); ++it) {
        cout << *it << " ";
    }
    
    // Lambda表达式（C++11）
    sort(fruits.begin(), fruits.end(), 
        [](const string& a, const string& b) {
            return a.length() < b.length();
        });
}

/*--------异常处理--------*/
void exceptionDemo() {
    try {
        int* arr = new int[1000000000000]; // 可能抛出bad_alloc
    } catch (const bad_alloc& e) {
        cerr << "Memory allocation failed: " << e.what() << endl;
    }
}

int main() {
    basicSyntax();
    controlFlow();
    
    print(5);       // 调用int版本
    print(3.14);    // 调用double版本
    
    Dog mydog("Buddy");
    mydog.speak();  // 多态调用
    
    MyArray<double> arr(5);
    arr[0] = 3.1415;
    
    stlDemo();
    
    return 0;
}
