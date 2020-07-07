#pragma once
#include <iostream>
using namespace std;
template <typename T>
class MyVector
{
public:
	friend ostream & operator<<( ostream & os,const MyVector<T> & t);
	MyVector(int size=0);
	MyVector(const MyVector &obj);
	~MyVector();
	T& operator [](int index);
	MyVector& operator=(const MyVector &obj);
	int getLen()
	{
		return m_len;
	}
protected:
	T *m_space;
	int m_len;
};

