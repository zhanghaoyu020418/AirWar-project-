#pragma once

#include "graphics.h"
#include <iostream>
#include "AirPlane.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>   
using namespace std;
IMAGE img[5];//IMAGE��ר�Ŵ��ͼƬ������

Node MyPlane;                   //�ҷ��ɻ��Ľڵ㴴��
LL EnemyPlane;                  //�з��ɻ���������
LL Bullet;                      //�ӵ�����Ĵ���



//�ú궨�����涨ͼƬ�Ĵ�С
#define BGWIDTH 400               //�������
#define BGHEIGHT 600              //�����߶�
#define MyPlaneWIDYH 60           //�ҷ��ɻ����
#define MyPlaneHEIGHT 80		  //�ҷ��ɻ��߶�
#define EnemyPlaneWIDYH 50        //�з��ɻ����
#define EnemyPlaneHEIGHT 40       //�з��ɻ��߶�
#define BulletWIDYH 16            //�ӵ����
#define BulletHEIGHT 25           //�ӵ��߶�


//�ϴ�ͼƬ
void init()
{
	srand((unsigned)time(NULL));   //�����������
	//��ͼƬ�ϴ�
	loadimage(&img[0], "res\\����.jpg", BGWIDTH, BGHEIGHT);          
	loadimage(&img[1], "res\\�ɻ�.jpg", MyPlaneWIDYH, MyPlaneHEIGHT);
	loadimage(&img[2], "res\\�л�.jpg", EnemyPlaneWIDYH, EnemyPlaneHEIGHT);
	loadimage(&img[3], "res\\�ӵ�.jpg", BulletWIDYH, BulletHEIGHT);

	MyPlane.x = BGWIDTH / 2 - MyPlaneWIDYH / 2;
	MyPlane.y = BGHEIGHT - MyPlaneHEIGHT - 30;
	MyPlane.speed = 10;
	MyPlane.next = NULL;
}

//��ʼ�����溯��
void DrawMap()
{
	BeginBatchDraw();              //��ʼ��������ͼƬ

	putimage(0, 0, &img[0]);       //�ڴ��ڻ���ͼƬ
	putimage(MyPlane.x, MyPlane.y, &img[1]);
	putimage(300, 50, &img[2]);
	putimage(300, 250, &img[3]);


	EndBatchDraw();                 //������������ͼƬ
}

//����Ϸ����
void playgame()
{
	if (_kbhit())                   //�жϼ����Ƿ���
	{
		switch (_getch())           //��ȡһ���ַ������ǲ��ûس���Ҳ��������ַ�
		{
		case 'W':
		case 'w':
		case 72:
			if(MyPlane.y > 0)
				MyPlane.y -= MyPlane.speed;
			break;                  //�ж�������ַ���ʾ���Ƽ���72���ϵļ���
		case 'S':
		case 's':
		case 80:
			if (MyPlane.y < BGHEIGHT - MyPlaneHEIGHT - 20)
				MyPlane.y += MyPlane.speed;
			break;                  //�ж�������ַ���ʾ���Ƽ���72���ϵļ���
		case 'a':
		case 'A':
		case 77:
			if (MyPlane.x > 0)
				MyPlane.x += MyPlane.speed;
			break;                  //�ж�������ַ���ʾ���Ƽ���72���ϵļ���
		case 'd':
		case 'D':
		case 75:
			if (MyPlane.x < BGWIDTH - MyPlaneWIDYH)
				MyPlane.x -= MyPlane.speed;
			break;                  //�ж�������ַ���ʾ���Ƽ���72���ϵļ���

		}
	}
}




//��ʼ��Ϸ����
void start()
{
	initgraph(BGWIDTH, BGHEIGHT);   //��ʼ������

	init();
	while (1)
	{
		
		DrawMap();
		playgame();
	}

//	getchar();                       //ʹ����ͣ����
	closegraph();                    //�رմ���
}