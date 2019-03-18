#include <stdio.h>
#include <easyx.h>
#include <graphics.h> // 图形库文件
#include <time.h>
#include <conio.h>  // getch()

#define ROW  5    // 砖块的行数
#define COL  10	  // 砖块的列数

/* 全局变量 */
extern int arr[ROW][COL];  // 初始化砖块数组  值为1表示被打掉  0表示未被打掉

extern int boardx, boardy;  // 木板坐标
extern int ballx, bally;    // 小球坐标

extern int addx;   // 小球坐标的增量
extern int addy;  // 纵坐标的增量是减少的

extern bool starting;  // 判断小球是否正在运动
extern bool iscatch;   // 判断木板是否捕捉到小球

// 函数声明
void initGame();
void drawRectangle();
void ballMove();
void muban();
void play();


// 木板运动
void muban()
{
	setfillcolor(BLACK);
	solidrectangle(boardx, boardy, boardx + 60, boardy + 10);
	char c = getch();  // 从控制台读取一个字符，但不显示在屏幕上,会等待你按下任意键，再继续执行下面的语句
	switch (c) {
			// 向左
		case 'a':
		case 'A':
		case 75: // 向← 键码值
			if (iscatch) {
				setfillcolor(LIGHTRED);
				solidcircle(ballx, bally, 10);
			}
			boardx -= 15; // 木板移动幅度
			break;
		case 'd':
		case 'D':
		case 77: // 向→ 键码值
			if (iscatch) {
				setfillcolor(LIGHTRED);
				solidcircle(ballx, bally, 10);
			}
			boardx += 15; // 木板移动幅度
			break;
	}
	// 给木板设置边界
	if (boardx <= 0) {
		boardx = 0;
	}
	if (boardx >= 340) {
		boardx = 340;
	}
	setfillcolor(LIGHTBLUE);
	solidrectangle(boardx, boardy, boardx + 60, boardy + 10);
}