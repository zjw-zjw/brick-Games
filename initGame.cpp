#include <stdio.h>
#include <easyx.h>
#include <graphics.h> // ͼ�ο��ļ�
#include <time.h>
#include <conio.h>  // getch()

#define ROW  5    // ש�������
#define COL  10	  // ש�������
//
/* ȫ�ֱ��� */
extern int arr[ROW][COL];  // ��ʼ��ש������  ֵΪ1��ʾ�����  0��ʾδ�����

extern int boardx, boardy;  // ľ������
extern int ballx, bally;    // С������

extern int addx;   // С�����������
extern int addy;  // ������������Ǽ��ٵ�

extern bool starting;  // �ж�С���Ƿ������˶�
extern bool iscatch;   // �ж�ľ���Ƿ�׽��С��

// ��������
void initGame();
void drawRectangle();
void ballMove();
void muban();
void play();



// ��ʼ����Ϸ
void initGame()
{
	// ��ʼ��ľ��λ�ã��м䣩��ľ�峤��Ϊ60�����Ϊ10
	boardx = 200 - 30;  // ���ϽǺ�����
	boardy = 600 - 10;   // ���Ͻ�������
	// ��С��İ뾶Ϊ10
	ballx = 200;		   // С��ĺ�����
	bally = 600 - 10 - 10; // С���������������Ϊ����ľ������棬���Լ�ȥһ��ľ��Ŀ��

	// ����С��ͼ����ɫ�Լ����
	setfillcolor(LIGHTRED);
	solidcircle(ballx, bally, 10);

	// ����ľ����ɫ�Լ����
	setfillcolor(LIGHTBLUE);
	solidrectangle(boardx, boardy, boardx + 60, boardy + 10);  // �ֱ���ľ������Ͻ������½ǵ�����

}