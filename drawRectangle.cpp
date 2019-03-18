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

extern int addx ;   // 小球坐标的增量
extern int addy ;  // 纵坐标的增量是减少的

extern bool starting ;  // 判断小球是否正在运动
extern bool iscatch ;   // 判断木板是否捕捉到小球

// 函数声明
void initGame();
void drawRectangle();
void ballMove();
void muban();
void play();



// 绘制砖块
void drawRectangle()
{
	// 砖块的设定,长度为40，宽度为20
	// i代表行，即宽度变化； j代表列，即长度变化
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			// 二维数组值为0，表示砖块还没被打掉，就绘制砖块
			if (arr[i][j] == 0) {
				// 交叉填充颜色
				if ((i + j) % 2 == 0) {
					setfillcolor(LIGHTCYAN);  // 青色
					// 绘制砖块
					solidrectangle(j * 40, i * 20, j * 40 + 40, i * 20 + 20);
				}
				else {
					// 填充颜色
					setfillcolor(LIGHTGRAY); // 灰色
					// 绘制砖块
					solidrectangle(j * 40, i * 20, j * 40 + 40, i * 20 + 20);
				}
			}
		}
	}
}