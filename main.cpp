/*
	��ש����Ϸ
*/
#include <stdio.h>
#include <easyx.h>
#include <graphics.h> // ͼ�ο��ļ�
#include <time.h>    // sleep()������ ��λ����ms
#include <conio.h>  // getch()����

#define ROW  5    // ש�������
#define COL  10	  // ש�������

//���ݵ����
/* ȫ�ֱ��� */
int arr[ROW][COL] = { 0 };  // ��ʼ��ש������, ֵΪ1��ʾ�����, ֵΪ0��ʾδ�����

int boardx, boardy;  // ľ������
int ballx, bally;    // С������

int addx = 1;   // С�����������
int addy = -1;  // ������������Ǽ��ٵ�

bool starting = false;  // �ж�С���Ƿ������˶�
bool iscatch = false;   // �ж�ľ���Ƿ�׽��С��

// ��������
void initGame();	// ��ʼ����Ϸ
void drawRectangle();	// ����ש��
void ballMove();	// С���˶�
void muban();		// ľ���˶�
void play();		// ��ʼ��Ϸ


int main()
{
	// ����һ������
	initgraph(400, 600);
	initGame();
	play();
	// getch(); // ��ͣ
	// printf("GAME OVER!\n");
	return 0;
}