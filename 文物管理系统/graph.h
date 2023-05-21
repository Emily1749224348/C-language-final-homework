#include<stdio.h>
#include<graphics.h>//用于绘图的头文件
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

//播放音乐的功能
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

struct button {//为了方便管理按钮元素，我们将其参数整理在一个结构体内
	int x;//x坐标
	int y;//y坐标
	int height;//高度
	int width;//宽度
	COLORREF color;//按钮颜色
	// COLORREF类型变量值用于描绘一个颜色变量用16进制格式，比如：　0x00bbggrr
	char* ptext;//按钮内部文字
};

struct button b1;//用在后面取消null指针的引用

//这是一个创建button的函数,为其设置参数
struct button* create_button(int x, int y, int width, int height, COLORREF color, char text[]) {
	//以上参数分别为  左上角x坐标，左上角y坐标，宽度，高度，颜色，内部文字

	char str[] = "cpm";

	//运用动态内存申请，创建一个按钮
	struct button* new_button = (struct button*)malloc(sizeof(struct button));

	//取消NULL指针对new_button的引用
	if (!new_button) {
		new_button = &b1;
	}

	//导入按钮参数
	new_button->x = x;
	new_button->y = y;
	new_button->width = width;
	new_button->height = height;
	new_button->color = color;
	new_button->ptext = (char*)malloc(strlen(text) + 2);
	if (!new_button->ptext) {
		new_button->ptext = str;
	}
	strcpy(new_button->ptext, text );
	return new_button;

}

void drawButton(struct button* pbutton) {
	//给按钮填充颜色
	setfillcolor(pbutton->color);

	//设置button的字体,要解决重载问题，将属性中字符集设置为多节字符集
	settextstyle(35, 0,"楷体");

	//设置字体颜色
	settextcolor(BLACK);

	//设置边框线颜色
	setlinecolor(BLACK);

	//设置背景模式为透明
	setbkmode(TRANSPARENT);

	//两点可以确定一个按钮，对于以下函数需要传入左上点和右下点的坐标
	fillrectangle(pbutton->x, pbutton->y, pbutton->x + pbutton->width, pbutton->y + pbutton->height);

	//设置文字的位置
	outtextxy(pbutton->x + 15, pbutton->y + 6, pbutton->ptext);
}


//判断鼠标是否在按钮上
int mouseInButton(struct button* b, MOUSEMSG m)
{//判断机理是鼠标的横纵坐标是否再按钮的横纵坐标区间内
	if (b->x <= m.x && m.x <= b->x + b->width && b->y <= m.y && b->y + b->height >= m.y)
	{
		b->color = RGB(174, 238, 238);
		return 1;
	}
	b->color = RGB(230, 240, 242);
	return 0;
}

//判断是否有点击按钮
int clickButton(struct button* b, MOUSEMSG m) {
	//鼠标在按钮上且点击了左键
	if (mouseInButton(b, m) && m.uMsg == WM_LBUTTONDOWN)
	{
		return 1;
	}
	return 0;
}

