#ifndef Iterator_H
#define Iteraror_H

class Iterator
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};

#endif // !Iterator_H
