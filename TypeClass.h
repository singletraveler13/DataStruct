#pragma once
template <typename T>
class TypeClass
{
public:
	/*TypeClass(void);
	~TypeClass(void);*/
	T Add(T &t1,T &t2)
	{
		return t1+t2;
	}
	T Subtract(T &t1,T &t2)
	{
		return t1-t2;
	}
};

