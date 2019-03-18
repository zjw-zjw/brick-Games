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

extern int addx ;   // С�����������
extern int addy ;  // ������������Ǽ��ٵ�

extern bool starting ;  // �ж�С���Ƿ������˶�
extern bool iscatch ;   // �ж�ľ���Ƿ�׽��С��

// ��������
void initGame();
void drawRectangle();
void ballMove();
void muban();
void play();



// ����ש��
void drawRectangle()
{
	// ש����趨,����Ϊ40�����Ϊ20
	// i�����У�����ȱ仯�� j�����У������ȱ仯
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			// ��ά����ֵΪ0����ʾש�黹û��������ͻ���ש��
			if (arr[i][j] == 0) {
				// ���������ɫ
				if ((i + j) % 2 == 0) {
					setfillcolor(LIGHTCYAN);  // ��ɫ
					// ����ש��
					solidrectangle(j * 40, i * 20, j * 40 + 40, i * 20 + 20);
				}
				else {
					// �����ɫ
					setfillcolor(LIGHTGRAY); // ��ɫ
					// ����ש��
					solidrectangle(j * 40, i * 20, j * 40 + 40, i * 20 + 20);
				}
			}
		}
	}
}