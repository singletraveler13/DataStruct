#include "Algorithm.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Algorithm::Algorithm(void)
{
}


Algorithm::~Algorithm(void)
{
}
//Ñî»ÔÈý½Ç

void Algorithm::Yanghuisanjiao(int row)
{
	vector <vector<int>>  Vt;
	vector <int> tempVt;
	int g_a;
	for(int i=0;i<row;i++)
	{
		tempVt.clear();
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i)
				g_a=1;
			else
				g_a=Vt[i-1][j-1]+Vt[i-1][j];
			tempVt.push_back(g_a);
			cout<<g_a<<"\t";
		}
		Vt.push_back(tempVt);
		cout<<endl;
	}
	
	
}

void Algorithm::SortString(string &s)
{
	for(int i=s.length()-1;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(s[j]>s[j+1])
				Swap(s,j,j+1);
		}
	}
}

void Algorithm::Swap(string &s,int a,int b)
{
	char temp=s[a];
	s[a]=s[b];
	s[b]=temp;
}
