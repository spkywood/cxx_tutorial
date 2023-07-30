#ifndef _CONST_KEYWORDS_H_
#define _CONST_KEYWORDS_H_

class ConstKeyWords
{
public:
	ConstKeyWords(int a, int b, int c);
	~ConstKeyWords();

	int getA() const;
	int getB() const;
	int getC() const;

private:
	mutable int a;
	int b;
	int c;
};

ConstKeyWords::ConstKeyWords(int a, int b, int c) : a(a), b(b), c(c) {}

ConstKeyWords::~ConstKeyWords() {}

int	ConstKeyWords::getA() const {
	return ++a;
}

int	ConstKeyWords::getB() const {
	return b;
}

int	ConstKeyWords::getC() const {
	return c;
}

#endif // !_CONST_KEYWORDS_H_
