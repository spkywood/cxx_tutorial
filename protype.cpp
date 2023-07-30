#include <cstdio>
#include <cstdlib>
#include <cstdint>


extern "C" {
	struct SpeakTable
	{
		void(*speak)(void* ptr);
	};

	void __dog_speak(void* ptr) {
		uint8_t* p = (uint8_t*)ptr;
		p += sizeof(SpeakTable*);
		size_t b = *(size_t*)p;
		printf("woof, woof ... %llu \n", b);
	}

	void __human_speak(void* ptr) {
		uint8_t* p = (uint8_t*)ptr;
		p += sizeof(SpeakTable*);
		size_t b = *(size_t*)p;
		p += sizeof(size_t);
		size_t c = *(size_t*)p;
		printf("woof, woof ... %llu - %llu \n", b, c);
	}

	// 内存模型。
	struct __ispeak
	{
		const SpeakTable* vt;
		size_t b;
	};

	struct __dog
	{
		const SpeakTable* vt;
		size_t b;
	};

	struct __human
	{
		const SpeakTable* vt;
		size_t b;
		size_t c;
	};

	const static SpeakTable __dogSpeakTable = { __dog_speak };
	const static SpeakTable __humanSpeakTable = { __human_speak };

	__dog* createDog() {
		__dog* ptr = (__dog*)malloc(sizeof(__dog));
		/*
		* 动态内存分配函数malloc分配内存时，
		* 经常会出现"取消对NULL指针的'...'的引用"的警告，这是因为在写代码时，没有加判断内存分配是否分配成功的语句造成的。
		*/
		
		if (ptr == NULL) {
			return NULL;
		}
		else {
			ptr->vt = &__dogSpeakTable;
			ptr->b = 0;
			return ptr;
		}
	}

	__human* createHuman() {
		__human* ptr = (__human*)malloc(sizeof(__human));

		if (ptr == NULL) {
			return NULL;
		}
		else {
			ptr->vt = &__humanSpeakTable;
			ptr->b = 1;
			ptr->c = 2;
			return ptr;
		}
	}
};

int main() {
	__dog* p_dog = createDog();
	__human* p_human = createHuman();


	__ispeak* p_s1 = (__ispeak*)p_dog;
	__ispeak* p_s2 = (__ispeak*)p_human;

	p_s1->vt->speak(p_s1);
	p_s2->vt->speak(p_s2);
}