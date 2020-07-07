#include "MyVector.h"
#include <iostream>
using namespace std;

template<typename T>
ostream & operator<<( ostream & os,const MyVector<T> & t)
{
	for(int i=0;i<t.m_len;i++)
	{
		ostream<<t[i];
	}
	return ostream;
}
template<typename T>
MyVector<T>::MyVector(int size)
{
	
	this->m_len=size;
	this->m_space=new T[size];
	
}
template<typename T>
MyVector<T>::MyVector(const MyVector &obj)
{
	this->m_len=obj.m_len;
	this->m_space=new T[obj.m_len];
	for(int i=0;i<obj.m_len;i++)
	{
		this->m_space[i]=obj.m_space[i];
	}
}

template<typename T>
MyVector<T>::~MyVector()
{
	if(this->m_space!=NULL)
	{
		delete [] this->m_space;
		this->m_space=NULL;
		this->m_len=0;
	}
	
}
template<typename T>
T& MyVector<T>::operator[](int index)
{
	return m_space[index];
}
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &obj)
{
	if(this->m_space!=NULL)
	{
		delete [] this->m_space;
		this->m_space=NULL;
		this->m_len=0;
	}
	this->m_len=obj.m_len;
	this->m_space=new T[obj.m_len];
	for(int i=0;i<obj.m_len;i++)
	{
		this->m_space[i]=obj.m_space[i];
	}
	return *this;
}