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

// int bally;

// ��������
void initGame();
void drawRectangle();
void ballMove();
void muban();
void play();


// ��ʼ��Ϸ
void play()
{
	while (1) {
		// ����ש��
		drawRectangle();
		// �ж��Ƿ��°����� ���·���1�� û������0
		// ���°����ƶ�ľ��
		if (_kbhit()) {
			muban();
		}
		// С���ƶ�
		ballMove();

		// ľ��û�ӵ��� ��Ϸ������
		if (bally > 590) {
			MessageBox(NULL, "oo~�군", "��ʾ", MB_OK);  // ��ʾ����
			break;
		}
	}
}