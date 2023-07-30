#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_

namespace clay
{

	class noncopyable
	{
	public:
		// ¿½±´¹¹Ôìº¯Êý
		noncopyable(const noncopyable&) = delete;
		void operator=(const noncopyable&) = delete;

	protected:
		noncopyable() = default;
		~noncopyable() = default;
	};

}  // namespace clay

#endif