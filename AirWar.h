#pragma once

#include "graphics.h"
#include <iostream>
#include "AirPlane.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>   
using namespace std;
IMAGE img[5];//IMAGE是专门存放图片的数组

Node MyPlane;                   //我方飞机的节点创建
LL EnemyPlane;                  //敌方飞机的链表创建
LL Bullet;                      //子弹链表的创建



//用宏定义来规定图片的大小
#define BGWIDTH 400               //背景宽度
#define BGHEIGHT 600              //背景高度
#define MyPlaneWIDYH 60           //我方飞机宽度
#define MyPlaneHEIGHT 80		  //我方飞机高度
#define EnemyPlaneWIDYH 50        //敌方飞机宽度
#define EnemyPlaneHEIGHT 40       //敌方飞机高度
#define BulletWIDYH 16            //子弹宽度
#define BulletHEIGHT 25           //子弹高度


//上传图片
void init()
{
	srand((unsigned)time(NULL));   //生成随机种子
	//将图片上传
	loadimage(&img[0], "res\\背景.jpg", BGWIDTH, BGHEIGHT);          
	loadimage(&img[1], "res\\飞机.jpg", MyPlaneWIDYH, MyPlaneHEIGHT);
	loadimage(&img[2], "res\\敌机.jpg", EnemyPlaneWIDYH, EnemyPlaneHEIGHT);
	loadimage(&img[3], "res\\子弹.jpg", BulletWIDYH, BulletHEIGHT);

	MyPlane.x = BGWIDTH / 2 - MyPlaneWIDYH / 2;
	MyPlane.y = BGHEIGHT - MyPlaneHEIGHT - 30;
	MyPlane.speed = 10;
	MyPlane.next = NULL;
}

//初始化界面函数
void DrawMap()
{
	BeginBatchDraw();              //开始批量绘制图片

	putimage(0, 0, &img[0]);       //在窗口绘制图片
	putimage(MyPlane.x, MyPlane.y, &img[1]);
	putimage(300, 50, &img[2]);
	putimage(300, 250, &img[3]);


	EndBatchDraw();                 //结束批量绘制图片
}

//玩游戏函数
void playgame()
{
	if (_kbhit())                   //判断键盘是否按下
	{
		switch (_getch())           //获取一个字符，但是不用回车，也不会回显字符
		{
		case 'W':
		case 'w':
		case 72:
			if(MyPlane.y > 0)
				MyPlane.y -= MyPlane.speed;
			break;                  //判读输入的字符表示控制键，72是上的键码
		case 'S':
		case 's':
		case 80:
			if (MyPlane.y < BGHEIGHT - MyPlaneHEIGHT - 20)
				MyPlane.y += MyPlane.speed;
			break;                  //判读输入的字符表示控制键，72是上的键码
		case 'a':
		case 'A':
		case 77:
			if (MyPlane.x > 0)
				MyPlane.x += MyPlane.speed;
			break;                  //判读输入的字符表示控制键，72是上的键码
		case 'd':
		case 'D':
		case 75:
			if (MyPlane.x < BGWIDTH - MyPlaneWIDYH)
				MyPlane.x -= MyPlane.speed;
			break;                  //判读输入的字符表示控制键，72是上的键码

		}
	}
}




//开始游戏函数
void start()
{
	initgraph(BGWIDTH, BGHEIGHT);   //初始化窗口

	init();
	while (1)
	{
		
		DrawMap();
		playgame();
	}

//	getchar();                       //使窗口停下来
	closegraph();                    //关闭窗口
}