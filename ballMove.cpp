
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
extern int addy;   // �����������

extern bool starting;  // �ж�С���Ƿ������˶�
extern bool iscatch;   // �ж�ľ���Ƿ�׽��С��

// ��������
void initGame();
void drawRectangle();
void ballMove();
void muban();
void play();


// С����˶�(����ĸı�)
void ballMove()
{
	iscatch = false;
	// ����ı�֮ǰ������
	setfillcolor(BLACK);
	solidcircle(ballx, bally, 10);
	BeginBatchDraw(); 
	//BeginBatchDraw()����������ڿ�ʼ������ͼ��
	//ִ�к��κλ�ͼ����������ʱ���������Ļ�ϣ�ֱ��ִ�� FlushBatchDraw �� EndBatchDraw �Ž�֮ǰ�Ļ�ͼ�����
	//����ѭ������

	// �жϱ߽磬ײ�����ߺ������棬Ȼ�󷴵�(���ڴ�СΪ400��600����İ뾶��10)
	if (ballx >= 390 || ballx <= 10) {
		addx = -1 * addx; // �����䷴��ʵ�ַ����Ĺ���
	}
	if (bally <= 10) {
		addy = -1 * addy; // �����䷴��ʵ�ַ����Ĺ���
	}

	// С���ש��
	int flag = 0; // ���С���Ƿ��ש��
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			// �����±�i��jת����ש������Ͻ�����
			int x = j * 40;
			int y = i * 20;
			// С���ש�飨�������Χ�ڣ�
			if (arr[i][j] == 0 && x - ballx <= 10 && ballx - x <= 10 + 40 && bally - y <= 20 + 10 && bally >= y + 10) {
				addy = -1 * addy;	// ���෴����
				addx = -1 * addx;	// ���෴����
				arr[i][j] = 1;      // ש���Ӧ��ֵ��Ϊ1����ʾ�Ѿ�������ˡ�
				flag = 1;			// flag��1����ʾ���ľ�塣
				// ��֮��ש����ʧ(ʵ���ǰ�ש���Ϊ������ɫ)
				setfillcolor(BLACK);
				solidrectangle(x, y, x + 40, y + 20);
				break; 
			}
		}
		if (flag) { // �ж�falg��δ1�����ʾ���ľ�壬���������ѭ��
			break;
		}
	}

	// С���ľ������
	if (starting && boardx - ballx <= 10 && ballx - boardx <= 70 && bally == 580) {
		// ��ľ�壬iscatch���Ϊtrue
		iscatch = true;
		addy = -1 * addy;
		// addx = -1 * addx;
	}

	starting = true;
	ballx += addx;
	bally += addy;
	setfillcolor(LIGHTRED);
	solidcircle(ballx, bally, 10);
	FlushBatchDraw(); // ��ʾ֮ǰ���Ƶ�ͼƬ
	Sleep(3); // ����һ����ʱ��3��ʾ3����(ms)
}