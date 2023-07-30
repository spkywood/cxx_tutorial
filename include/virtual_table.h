/**
* C++��������������ԣ���װ�����˼�룬һ�нԶ��󣩡��̳У����븴�ã�����̬
* 1. ����ʱ��̬������
* 2. ����ʱ��̬���麯��ʵ��
*/

#include <iostream>

class ISpeaker
{
protected:
	size_t b;
public:
	ISpeaker(size_t _b) : b(_b) {}
	virtual void speak() = 0;		// �麯��
	
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
