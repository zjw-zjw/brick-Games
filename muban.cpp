#include <stdio.h>
#include <easyx.h>
#include <graphics.h> // ͼ�ο��ļ�
#include <time.h>
#include <conio.h>  // getch()

#define ROW  5    // ש�������
#define COL  10	  // ש�������

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


// ľ���˶�
void muban()
{
	setfillcolor(BLACK);
	solidrectangle(boardx, boardy, boardx + 60, boardy + 10);
	char c = getch();  // �ӿ���̨��ȡһ���ַ���������ʾ����Ļ��,��ȴ��㰴����������ټ���ִ����������
	switch (c) {
			// ����
		case 'a':
		case 'A':
		case 75: // ��� ����ֵ
			if (iscatch) {
				setfillcolor(LIGHTRED);
				solidcircle(ballx, bally, 10);
			}
			boardx -= 15; // ľ���ƶ�����
			break;
		case 'd':
		case 'D':
		case 77: // ��� ����ֵ
			if (iscatch) {
				setfillcolor(LIGHTRED);
				solidcircle(ballx, bally, 10);
			}
			boardx += 15; // ľ���ƶ�����
			break;
	}
	// ��ľ�����ñ߽�
	if (boardx <= 0) {
		boardx = 0;
	}
	if (boardx >= 340) {
		boardx = 340;
	}
	setfillcolor(LIGHTBLUE);
	solidrectangle(boardx, boardy, boardx + 60, boardy + 10);
}