#include <iostream>
#include <vector>
#include "Algorithm.h"
#include "list"
#include "TypeClass.h"
using namespace std;
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>
int main1();
int main2();
int main()
{
	while(1)
	{
		system("cls");
	    main2();
		system("pause");
	}
	
	return 0;

}
///���Ͳ���
int main1()
{
	int a,b;
	cin>>a;
	cin>>b;
	TypeClass<int> typeClass;
	int result= typeClass.Subtract(a,b);
	cout<<result<<endl;
	return 0;
}

//����������
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������


int main2()
{
	//����������
	srand((unsigned int)time(NULL));

	//�Ƿ������ı�ʶ
	bool isDead = false;

	char preKey = NULL;
	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall,food);
	snake.InitSnake();


	
	gotoxy(hOut, 0, Wall::ROW);
	cout << "�÷֣�" << snake.getScore() << "��" << endl;
	//gotoxy(hOut, 10, 5);//y*2 x 
	//�����û�������

	while (!isDead)
	{
		char key = _getch();

		//�ж�����ǵ�һ�ΰ��ˣ�������Ų��ܼ�����Ϸ
		//�ж���һ���ƶ�����
		if (preKey == NULL&&key == snake.LEFT)
		{
			continue;
		}


		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//�жϱ��ΰ����Ƿ����ϴγ�ͻ
				if ((key == snake.LEFT&&preKey == snake.RIGHT )||
					(key == snake.RIGHT&&preKey == snake.LEFT )||
					(key == snake.UP&&preKey == snake.DOWN) ||
					(key == snake.DOWN&&preKey == snake.UP) 
					)
				{
					key = preKey;
				}
				else
				{
					preKey = key;//���ǳ�ͻ���������Ը��°���
				}
				
				if (snake.move(key) == true)
				{
					//�ƶ��ɹ�
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0,Wall::ROW);
	
					cout << "�÷֣�" << snake.getScore() << "��" << endl;
					Sleep(snake.getSleepTime());
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey;//ǿ�ƽ����󰴼���Ϊ��һ���ƶ��ķ���
			}
		
		} while (!_kbhit());//��û�м��������ʱ�򷵻�0
		
	}
	

	

	system("pause");
	return 0;
}