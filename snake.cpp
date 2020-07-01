#include"snake.h"
#include"wall.h"
#include<Windows.h>


void gotoxy1(HANDLE hOut1, int x, int y)
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������

Snake::Snake(Wall &tempWall,Food& tempFood) : wall(tempWall), food(tempFood)
{
	pHead = NULL;
	isRool = false;
}
void Snake::destroyPoint()
{
	Point * pCur = pHead;
	while (pHead!=NULL)
	{
		pCur = pHead->next;
		delete pHead;

		pHead = pCur;
	}
}

void Snake::addPoint(int x, int y)
{
	//�����½��
	Point * newpoint = new Point;
	newpoint->x = x;
	newpoint->y = y;
	newpoint->next = NULL;

	//���ԭ��ͷ��Ϊ�գ���Ϊ����
	if (pHead != NULL)
	{
		wall.setWall(pHead->x, pHead->y, '=');

		gotoxy1(hOut1, pHead->y * 2, pHead->x);
		cout << "=";
	}

	newpoint->next = pHead;
	pHead = newpoint;//����ͷ��
	wall.setWall(pHead->x, pHead->y, '@');
	gotoxy1(hOut1, pHead->y * 2, pHead->x);
	cout << "@";

}

void Snake::InitSnake()
{
	destroyPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

//�ƶ�ʱɾ�����
void Snake::delPoint()
{
	//�������Ͻ�� ��ȥ��ɾ������
	if (pHead == NULL || pHead->next == NULL)
	{
		return;
	}
	//��ǰ���
	Point *pCur = pHead->next;
	//��һ�����
	Point *pPre = pHead;

	while (pCur->next!=NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//ɾ��β���
	wall.setWall(pCur->x, pCur->y, ' ');
	gotoxy1(hOut1, pCur->y * 2, pCur->x);
	cout << " ";
	delete pCur;

	pCur = NULL;
	pPre->next = NULL;
}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;


	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}

	//�ж� �����һ����������β�ͣ���Ӧ������
	Point *pCur = pHead->next;
	//��һ�����
	Point *pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (pCur->x == x&&pCur->y == y)
	{
		//����β�͵�ѭ��
		isRool = true;
	}
	else
	{
		//�ж��û�Ҫ�����λ���Ƿ�ɹ�
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
		{
			addPoint(x, y);
			delPoint();
			system("cls");
			wall.drawWall();
			cout << "�÷֣�" << getScore() << "��" << endl;
			cout << "GAME OVER" << endl;
			return false;
		}
	}

	

	//�ƶ��ɹ� ������
	//�Ե�ʳ�δ�Ե�ʳ��
	if (wall.getWall(x, y) == '#')
	{
		addPoint(x, y);

		//��������ʳ��
		food.setFood();
	}
	else
	{
		addPoint(x, y);
		delPoint();

		if (isRool == true)
		{
			wall.setWall(x, y, '@');
			gotoxy1(hOut1, y * 2, x);
			cout << "@";
		}
		
	}

	return true;
}


int Snake::getSleepTime()
{
	int sleepTime=0;
	int size = countList();
	if (size < 5)
	{
		sleepTime = 300;
	}
	else if (size >= 5 && size <= 10)
	{
		sleepTime = 200;
	}
	else
	{
		sleepTime = 100;
	}
	return sleepTime;
}

int Snake::countList()
{
	int size = 0;
	Point * curPoint = pHead;
	while (curPoint!=NULL)
	{
		size++;
		curPoint = curPoint->next;
	}
	return size;
}

int Snake::getScore()
{
	int size = countList();
	int score = (size-3) * 100;
	return score;
}
