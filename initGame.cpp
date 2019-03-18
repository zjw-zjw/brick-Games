#include <stdio.h>
#include <easyx.h>
#include <graphics.h> // 图形库文件
#include <time.h>
#include <conio.h>  // getch()

#define ROW  5    // 砖块的行数
#define COL  10	  // 砖块的列数
//
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



// 初始化游戏
void initGame()
{
	// 初始化木板位置（中间）设木板长度为60，宽度为10
	boardx = 200 - 30;  // 左上角横坐标
	boardy = 600 - 10;   // 左上角纵坐标
	// 设小球的半径为10
	ballx = 200;		   // 小球的横坐标
	bally = 600 - 10 - 10; // 小球的纵坐标这里以为是在木板的上面，所以减去一个木板的宽度

	// 设置小球图形颜色以及填充
	setfillcolor(LIGHTRED);
	solidcircle(ballx, bally, 10);

	// 设置木板颜色以及填充
	setfillcolor(LIGHTBLUE);
	solidrectangle(boardx, boardy, boardx + 60, boardy + 10);  // 分别是木板的左上角与右下角的坐标

}