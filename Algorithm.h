#pragma once
#include <string>
#include <iostream>
using namespace std;

class Algorithm
{
public:
	Algorithm(void);
	~Algorithm(void);
	static void Yanghuisanjiao(int row);
	static void SortString(string &s);
	 
private:
	 static void Swap(string &s,int a,int b);
};

