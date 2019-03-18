
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
extern int addy;   // 纵坐标的增量

extern bool starting;  // 判断小球是否正在运动
extern bool iscatch;   // 判断木板是否捕捉到小球

// 函数声明
void initGame();
void drawRectangle();
void ballMove();
void muban();
void play();


// 小球的运动(坐标的改变)
void ballMove()
{
	iscatch = false;
	// 坐标改变之前，擦除
	setfillcolor(BLACK);
	solidcircle(ballx, bally, 10);
	BeginBatchDraw(); 
	//BeginBatchDraw()这个函数用于开始批量绘图。
	//执行后，任何绘图操作都将暂时不输出到屏幕上，直到执行 FlushBatchDraw 或 EndBatchDraw 才将之前的绘图输出。
	//用在循环外面

	// 判断边界，撞到两边和最上面，然后反弹(窗口大小为400，600，球的半径是10)
	if (ballx >= 390 || ballx <= 10) {
		addx = -1 * addx; // 增量变反，实现反弹的功能
	}
	if (bally <= 10) {
		addy = -1 * addy; // 增量变反，实现反弹的功能
	}

	// 小球打到砖块
	int flag = 0; // 标记小球是否打到砖块
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			// 数组下标i和j转换成砖块的左上角坐标
			int x = j * 40;
			int y = i * 20;
			// 小球打到砖块（在这个范围内）
			if (arr[i][j] == 0 && x - ballx <= 10 && ballx - x <= 10 + 40 && bally - y <= 20 + 10 && bally >= y + 10) {
				addy = -1 * addy;	// 往相反方向
				addx = -1 * addx;	// 往相反方向
				arr[i][j] = 1;      // 砖块对应的值置为1，表示已经被打掉了。
				flag = 1;			// flag置1，表示球打到木板。
				// 打到之后砖块消失(实质是把砖块变为背景颜色)
				setfillcolor(BLACK);
				solidrectangle(x, y, x + 40, y + 20);
				break; 
			}
		}
		if (flag) { // 判断falg若未1，则表示球打到木板，跳出最外层循环
			break;
		}
	}

	// 小球打到木板的情况
	if (starting && boardx - ballx <= 10 && ballx - boardx <= 70 && bally == 580) {
		// 打到木板，iscatch标记为true
		iscatch = true;
		addy = -1 * addy;
		// addx = -1 * addx;
	}

	starting = true;
	ballx += addx;
	bally += addy;
	setfillcolor(LIGHTRED);
	solidcircle(ballx, bally, 10);
	FlushBatchDraw(); // 显示之前绘制的图片
	Sleep(3); // 增加一点延时，3表示3毫秒(ms)
}