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

// int bally;

// 函数声明
void initGame();
void drawRectangle();
void ballMove();
void muban();
void play();


// 开始游戏
void play()
{
	while (1) {
		// 绘制砖块
		drawRectangle();
		// 判断是否按下按键， 按下返回1， 没按返回0
		// 按下按键移动木板
		if (_kbhit()) {
			muban();
		}
		// 小球移动
		ballMove();

		// 木板没接到， 游戏结束。
		if (bally > 590) {
			MessageBox(NULL, "oo~完蛋", "提示", MB_OK);  // 提示窗口
			break;
		}
	}
}