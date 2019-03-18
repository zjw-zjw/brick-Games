/*
	打砖块游戏
*/
#include <stdio.h>
#include <easyx.h>
#include <graphics.h> // 图形库文件
#include <time.h>    // sleep()函数， 单位毫秒ms
#include <conio.h>  // getch()函数

#define ROW  5    // 砖块的行数
#define COL  10	  // 砖块的列数

//数据的设计
/* 全局变量 */
int arr[ROW][COL] = { 0 };  // 初始化砖块数组, 值为1表示被打掉, 值为0表示未被打掉

int boardx, boardy;  // 木板坐标
int ballx, bally;    // 小球坐标

int addx = 1;   // 小球坐标的增量
int addy = -1;  // 纵坐标的增量是减少的

bool starting = false;  // 判断小球是否正在运动
bool iscatch = false;   // 判断木板是否捕捉到小球

// 函数声明
void initGame();	// 初始化游戏
void drawRectangle();	// 绘制砖块
void ballMove();	// 小球运动
void muban();		// 木板运动
void play();		// 开始游戏


int main()
{
	// 创建一个窗口
	initgraph(400, 600);
	initGame();
	play();
	// getch(); // 暂停
	// printf("GAME OVER!\n");
	return 0;
}