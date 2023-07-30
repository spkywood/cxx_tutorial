// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include <string>

#include "include/MySort.h"
#include "include/summary.h"

#include "include/ConstKeyWords.h"

#include "include/virtual_table.h"

using namespace std;

int* sum(int a, int b) {
	std::cout << "call (a + b) = ";
	int c = (a + b);
	return &c;
}

int* mul(int a, int b) {
	std::cout << "call (a * b) = ";
	int c = (a * b);
	return &c;
}

int* (*pf)(int, int);

int main()
{
	int&& a = 10;
	foo(static_cast<int&&>(a));
	foo(std::move(a));
	cout << "Hello CMake." << endl;

	std::vector<int> nums{10, 2, 81, 9, 16, 77, 3, 15, 43, 23, 61, 45, 51};

	// 排序算法

	MySort my_sort;
	my_sort.bubble(nums);
	//my_sort.insertion(nums);
	//my_sort.selection(nums);
	//my_sort.quick(nums, 0, nums.size()-1);
	//my_sort.heap(nums);

	int* p = &nums[0];

	std::cout << "<<< -----------------------------------" << std::endl;
	std::cout << "[";
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << *p << " ";
		++p;
	}
	std::cout << "]\n";

	std::cout << "<<< -----------------------------------" << std::endl;

	

	std::cout << "pointer sizeof = " << sizeof(p) << std::endl;

	std::cout << "[";
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "]\n";

	// const 
	std::cout << "<<< -----------------------------------" << std::endl;

	// 1. 修饰变量
	// 指针不允许改变数据
	int b = 500;
	int c = 4000;
	const int d = 1000;

	const int* p1 = &b;	// const 位于 *的左侧: 用来修饰指针所指向的变量，指针指向常量(一般为const 变量)。
	int* const p2 = &c;	// const 位于 *的右侧: 用来修饰指针本身，指针是常量(指向的地址固定)。
	const int* const p3 = &d;	// 两侧均出现：指向常量，指针也为常量

	p1 = &c;
	c = 4001;
	//p2 = &b;	// error
	// 可以通过变量本身去修改
	b = 600;
	std::cout << *p1 << std::endl; // 
	std::cout << *p2 << std::endl; // 600
	std::cout << *p3 << std::endl; // 600

	// 2. 修饰成员函数,在成员函数名之后。
	// 不改变类的数据成员的成员函数。readonly function。
	// 定义为const的成员函数，改变类的数据成员时，编译器会报错。
	// readonly function内部，只能调用readonly function。
	// >>> mutable 关键字：如果类的数据成语由mutable关键字修饰，则const成员函数也可以修改。
	std::cout << "<<< -----------------------------------" << std::endl;

	ConstKeyWords ckw(1, 2, 3);
	std::cout << ckw.getA() << std::endl; // 
	std::cout << ckw.getB() << std::endl; // 
	std::cout << ckw.getC() << std::endl; // 
	std::cout << "<<< -----------------------------------" << std::endl;

	// 3. 修饰函数，位于函数声明前，即返回值是常量
	// 4. 修饰函数的传参，防止被修改

	const char str1[13]{"hello world!"};
	const char* p_str1  = str1;
	const char* p2_str1 = &str1[0];


	// sizeof 是运算符，结果在编译时得到
	// sizeof参数可以是任何数据的类型或者数据（sizeof参数不退化）
	std::cout << "数组的长度 =" << sizeof(str1) / sizeof(str1[0]) << std::endl;

	for (size_t i = 0; i < 13; i++)
	{
		std::cout << *p_str1;
		++p_str1;
	}


	// 函数指针
	std::cout << "\n<<< -----------------------------------" << std::endl;
	pf = sum;

	std::cout << "pf address = " << pf << std::endl;
	std::cout << "pf -> sum " << *pf(3, 10) << std::endl;
	std::cout << "sum address = " << sum << std::endl;

	pf = &mul;

	std::cout << "pf address = " << pf << std::endl;
	std::cout << "pf -> mul " << *pf(3, 10) << std::endl;
	std::cout << "mul address = " << mul << std::endl;

	std::cout << "\n<<< -----------------------------------" << std::endl;

	const char* str3 = "name";
	std::string str4 = "name";

	std::cout << "str3 size = " << sizeof(*str3) << std::endl;	// 首字母n的长度，占一个字节
	std::cout << "str3 size = " << sizeof(str3) << std::endl;	// 指针str3的长度，64位下8个字节
	std::cout << "str3 size = " << *str3 << std::endl; // 指针指向 首字母 n
	std::cout << "str4 size = " << str4.size() << std::endl;

	// 变量类型的长度
	std::cout << "\n<<< -----------------------------------" << std::endl;
	std::cout << "char size = " << sizeof(char) << std::endl;			// char 1个字节：8位
	std::cout << "short size = " << sizeof(short) << std::endl;			// short 2个字节，16位
	std::cout << "int size = " << sizeof(int) << std::endl;				// int 4个字节，32位
	std::cout << "uint32_t size = " << sizeof(uint32_t) << std::endl;	// uint32_t 4个字节，32位
	std::cout << "uint64_t size = " << sizeof(uint64_t) << std::endl;	// uint64_t 8个字节，64位
	std::cout << "float size = " << sizeof(float) << std::endl;			// float 4个字节，32位
	std::cout << "long size = " << sizeof(long) << std::endl;			// long 4个字节，32位
	std::cout << "double size = " << sizeof(double) << std::endl;		// double 8个字节，64位


	// 虚函数，虚表，虚指针
	std::cout << "\n<<< -----------------------------------" << std::endl;

	Human* p_human = new Human();
	Dog* p_dog = new Dog();

	ISpeaker* is_p1 = static_cast<ISpeaker*>(p_human);  // (ISpeaker*)p_human;
	ISpeaker* is_p2 = static_cast<ISpeaker*>(p_dog);    // (ISpeaker*)p_dog;


	//ISpeaker* is_p1 = new Human();
	//ISpeaker* is_p2 = new Dog();

	// 多态
	// 1. 虚函数是在基类中被声明为virtual，并在派生类中重新定义的成员函数，可实现成员函数的动态覆盖（Override）
	// 
	// 虚函数表
	// 2. 编译器会为每个有虚函数的类创建一个虚函数表，该虚函数表将被该类的所有对象共享
	//    类的每个虚成员占据虚函数表中的一行。如果类中有N个虚函数，那么其虚函数表将有N4
	//    派生类的虚函数表存放重写的虚函数，当基类的指针指向派生类的对象时，调用虚函数时都会根据vptr（虚表指针）来选择虚函数
	// 虚表指针
	// 1. 虚表指针在类对象中，每个同类对象中都有个一个vptr，指向内存中的vtable，所有同类对象，共享一个vtable，
	//    但是每个对象都自带一个vptr指向这个vtable,否则调用虚函数的时候会找不到正确的函数入口，
	//   （后面将会讲明）虚表指针是对象的第一个数据成员。
	// 2. 虚表指针没有正确初始化之前，我们不能够去调用虚函数。那么虚表是怎么实现的？
	//    虚表存放在哪里？虚表中的数据是在什么时候确定的？对象中的虚表指针又在什么时候赋值的？
	//    ------------------------------------------------------------------------
	//    答案: 是在构造函数中进行虚表的创建和虚表指针的初始化。
	//    虚表和静态变量一样存在全局数据区，虚表可以理解成类的静态成员，虚表指针和构造函数的执行初始化列表是初始化。
	//
	// 1. 拥有虚函数的类会有一个虚表，而且这个虚表存放在类定义模块的数据段中。
	//     模块的数据段通常存放定义在该模块的全局数据和静态数据，这样我们可以把虚表看作是模块的全局数据或者静态数据
	// 2. 类的虚表会被这个类的所有对象所共享。类的对象可以有很多，但是他们的虚表指针都指向同一个虚表，从这个意义上说，
	//     我们可以把虚表简单理解为类的静态数据成员。值得注意的是，虽然虚表是共享的，但是虚表指针并不是，
	//     类的每一个对象有一个属于它自己的虚表指针。
	// 3. 虚表中存放的是虚函数的地址
	// 4. 虚表的地址被存放在对象的起始位置，即对象的第一个数据成员就是它的虚表指针。 同时我们还可以注意到，
	//     虚表指针的初始化确实发生在构造函数的调用过程中， 但是在执行构造函数体之前，即进入到构造函数的"{"和"}"之前。
	//	   我们可以把构造函数的调用过程细分为两个阶段:
	//		a. 进入到构造函数体之间。在这个阶段如果存在虚函数的话，虚表指针被初始化。如果存在构造函数的初始化列表的话，初始化列表也会被执行。
	//		b. 进入到构造函数体内。这一阶段是我们通常意义上说的构造函数
	//
	is_p1->speak();
	is_p2->speak();

	return 0;
}
