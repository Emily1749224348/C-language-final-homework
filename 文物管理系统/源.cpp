#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <graphics.h>
#include<easyx.h>
#include"relics.h"
#include"graph.h"

#include<mmsystem.h>//���ֿ�
#pragma comment(lib,"winmm.lib")




int main() {
 
    int i;
//<<<<<<< Updated upstream
    num=0;
//=======
    //��������,�����ֱ�Ϊwidth,height,��ֹ�رմ���
    initgraph(880, 550, EW_NOCLOSE);
    IMAGE mm; //���ͼƬ��IMAGE����
    loadimage(&mm, "006M5y9Igy1h99fzn70mbj31900u0gwa.jpg", 880,550);//�൱��Ϊmm���ͼƬ������ֵ
    //ͼƬ�����ĵ�ַ��ͼƬ��ַ�����·����,width,height
    putimage(0, 0, &mm);//��ӡͼƬ
    //x���꣬y���꣬ͼƬ����
//>>>>>>> Stashed changes

    //���ü�����ť
    struct button *Inputt = create_button(250,190,170,50,RGB(230,240,242),(char*)"¼����Ϣ");
    struct button *Modify= create_button(250, 270, 170, 50, RGB(230, 240, 242), (char*)"�޸���Ϣ");
    struct button *Deletee= create_button(250, 350, 170, 50, RGB(230, 240, 242), (char*)"ɾ����Ϣ");
    struct button *Search = create_button(450, 190, 170, 50, RGB(230, 240, 242), (char*)"��������");
    struct button *Sort = create_button(450, 270, 170, 50, RGB(230, 240, 242), (char*)"��Ϣ����");
    struct button *Exit = create_button(450, 350, 170, 50, RGB(230, 240, 242), (char*)"�˳�ϵͳ");
    while (1) {
        //����˫���壬��ֹ����
        BeginBatchDraw();
        //ˢ��ҳ�棬��Ϊ����ĳ����޸ĵ��ǽṹ������Ĳ���
        putimage(0, 0, &mm);
        //����
        outtextxy(300, 40, "������Ϣ����ϵͳ");
        //����ÿһ��ѭ����Ҫ���»���ť

        drawButton(Inputt);
        drawButton(Modify);
        drawButton(Deletee);
        drawButton(Search);
        drawButton(Sort);
        drawButton(Exit);
        MOUSEMSG m = GetMouseMsg();
        if(clickButton(Inputt,m)){
            

            //inputt();
        }

        if(clickButton(Modify,m)){
            modify();
        }

        if(clickButton(Deletee , m)){
            deletee();
        }

        if (clickButton(Search, m)) {
            search();
        };

        if(clickButton(Sort, m)){
            sort();
        }

        if (clickButton(Exit, m)) {
            Save();
            closegraph();
            exit(0);
        }

        Save();
        EndBatchDraw();
    }

    
    


    system("pause");
    closegraph();
    return 0;
}
/*
    while (1) {

        Load();

        printf("\t\t\t\t-------- ������Ϣ����ϵͳ-------\n\n\n\n");     //�˵� 
        printf("\t\t\t\t\t1. ����������Ϣ\n\n");
        printf("\t\t\t\t\t2. �޸�������Ϣ\n\n");
        printf("\t\t\t\t\t3. ɾ��������Ϣ\n\n");
        printf("\t\t\t\t\t4. ��ѯ������Ϣ\n\n");
        printf("\t\t\t\t\t5. ��������������\n\n");
        printf("\t\t\t\t\t0. �˳�\n\n\n");

        printf("��ѡ��(0-5):");
        scanf_s("%d", &i);
     

        switch (i) {
        case 1:inputt(); break;
        case 2:modify(); break;
        case 3:deletee(); break;
        case 4:search(); break;
        case 5:sort(); break;
        case 0:exit(0);
        default:break;
        }

        Save();
    }
    */
