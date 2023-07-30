#ifndef _MYSINGLETON_H_
#define _MYSINGLETON_H_

// 单例模式

#include <assert.h>
//#include <pthread.h>
#include <stdlib.h> // atexit

#include "noncopyable.h"

namespace clay {
	
	template<typename T>
	class Singleton : noncopyable
	{
	public:
		Singleton() = delete;
		~Singleton() = delete;

		static T& instance()
		{
			pthread_once(&ponce_, &Singleton::init);
			assert(value_ != NULL);
			return *value_;
		}

	private:
		// 私有成员函数
		static void init()
		{
		}

		static void destroy()
		{
		}

	private:
		// 私有成员变量
	};

}
#endif