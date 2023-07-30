#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_

namespace clay
{

	class noncopyable
	{
	public:
		// �������캯��
		noncopyable(const noncopyable&) = delete;
		void operator=(const noncopyable&) = delete;

	protected:
		noncopyable() = default;
		~noncopyable() = default;
	};

}  // namespace clay

#endif