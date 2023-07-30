/**
* C++面向对象三大特性：封装（类的思想，一切皆对象）、继承（代码复用）、多态
* 1. 编译时多态：重载
* 2. 运行时多态：虚函数实现
*/

#include <iostream>

class ISpeaker
{
protected:
	size_t b;
public:
	ISpeaker(size_t _b) : b(_b) {}
	virtual void speak() = 0;		// 虚函数
	
	~ISpeaker() {}
};

class Dog : public ISpeaker
{
public:
	Dog() : ISpeaker(0) {}

	virtual void speak() override {
		std::cout << "woof, woof ... " << b << std::endl;
	}

	~Dog() {}
};

class Human : public ISpeaker
{
public:
	Human() : ISpeaker(1), c(2) {}

	virtual void speak() override {
		std::cout << "hello, hello ... " << b << " - "  << c << std::endl;
	}

	~Human() {}

private:
	size_t c;
};
