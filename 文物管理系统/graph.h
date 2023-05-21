#include<stdio.h>
#include<graphics.h>//���ڻ�ͼ��ͷ�ļ�
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

//�������ֵĹ���
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

struct button {//Ϊ�˷������ťԪ�أ����ǽ������������һ���ṹ����
	int x;//x����
	int y;//y����
	int height;//�߶�
	int width;//���
	COLORREF color;//��ť��ɫ
	// COLORREF���ͱ���ֵ�������һ����ɫ������16���Ƹ�ʽ�����磺��0x00bbggrr
	char* ptext;//��ť�ڲ�����
};

struct button b1;//���ں���ȡ��nullָ�������

//����һ������button�ĺ���,Ϊ�����ò���
struct button* create_button(int x, int y, int width, int height, COLORREF color, char text[]) {
	//���ϲ����ֱ�Ϊ  ���Ͻ�x���꣬���Ͻ�y���꣬��ȣ��߶ȣ���ɫ���ڲ�����

	char str[] = "cpm";

	//���ö�̬�ڴ����룬����һ����ť
	struct button* new_button = (struct button*)malloc(sizeof(struct button));

	//ȡ��NULLָ���new_button������
	if (!new_button) {
		new_button = &b1;
	}

	//���밴ť����
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
	//����ť�����ɫ
	setfillcolor(pbutton->color);

	//����button������,Ҫ����������⣬���������ַ�������Ϊ����ַ���
	settextstyle(35, 0,"����");

	//����������ɫ
	settextcolor(BLACK);

	//���ñ߿�����ɫ
	setlinecolor(BLACK);

	//���ñ���ģʽΪ͸��
	setbkmode(TRANSPARENT);

	//�������ȷ��һ����ť���������º�����Ҫ�������ϵ�����µ������
	fillrectangle(pbutton->x, pbutton->y, pbutton->x + pbutton->width, pbutton->y + pbutton->height);

	//�������ֵ�λ��
	outtextxy(pbutton->x + 15, pbutton->y + 6, pbutton->ptext);
}


//�ж�����Ƿ��ڰ�ť��
int mouseInButton(struct button* b, MOUSEMSG m)
{//�жϻ��������ĺ��������Ƿ��ٰ�ť�ĺ�������������
	if (b->x <= m.x && m.x <= b->x + b->width && b->y <= m.y && b->y + b->height >= m.y)
	{
		b->color = RGB(174, 238, 238);
		return 1;
	}
	b->color = RGB(230, 240, 242);
	return 0;
}

//�ж��Ƿ��е����ť
int clickButton(struct button* b, MOUSEMSG m) {
	//����ڰ�ť���ҵ�������
	if (mouseInButton(b, m) && m.uMsg == WM_LBUTTONDOWN)
	{
		return 1;
	}
	return 0;
}

