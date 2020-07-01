#include<iostream>
#include"wall.h"
using namespace std;


void Wall::initWall() //��ʼ��ǽ�ڣ��ö�ά����
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//��ǽ�ڵĵط�
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
			{
				gameArray[i][j] = '*';
			}
			else
			{
				gameArray[i][j] = ' ';
			}
		}
	}
}

void Wall::drawWall()
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			//����ʱ����һ���ո񣬿������ÿ�һЩ
			cout << gameArray[i][j] << " ";
		}
		if (i == 4)
		{
			cout << "�汾��1.0";
		}
		if (i == 5)
		{
			cout << "�����ˣ�yy";
		}
		if (i == 6)
		{
			cout << "a:����";
		}
		if (i == 7)
		{
			cout << "d:����";
		}
		if (i == 8)
		{
			cout << "w:����";
		}
		if (i == 9)
		{
			cout << "s:����";
		}
		cout << endl;
	}
}

void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}
