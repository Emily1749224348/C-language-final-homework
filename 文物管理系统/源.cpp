#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <graphics.h>
#include<easyx.h>
#include"relics.h"
#include"graph.h"

#include<mmsystem.h>//音乐库
#pragma comment(lib,"winmm.lib")




int main() {
 
    int i;
//<<<<<<< Updated upstream
    num=0;
//=======
    //创建窗口,参数分别为width,height,禁止关闭窗口
    initgraph(880, 550, EW_NOCLOSE);
    IMAGE mm; //存放图片的IMAGE变量
    loadimage(&mm, "006M5y9Igy1h99fzn70mbj31900u0gwa.jpg", 880,550);//相当于为mm这个图片变量赋值
    //图片变量的地址，图片地址（相对路径）,width,height
    putimage(0, 0, &mm);//打印图片
    //x坐标，y坐标，图片变量
//>>>>>>> Stashed changes

    //设置几个按钮
    struct button *Inputt = create_button(250,190,170,50,RGB(230,240,242),(char*)"录入信息");
    struct button *Modify= create_button(250, 270, 170, 50, RGB(230, 240, 242), (char*)"修改信息");
    struct button *Deletee= create_button(250, 350, 170, 50, RGB(230, 240, 242), (char*)"删除信息");
    struct button *Search = create_button(450, 190, 170, 50, RGB(230, 240, 242), (char*)"查找文物");
    struct button *Sort = create_button(450, 270, 170, 50, RGB(230, 240, 242), (char*)"信息排序");
    struct button *Exit = create_button(450, 350, 170, 50, RGB(230, 240, 242), (char*)"退出系统");
    while (1) {
        //设置双缓冲，防止闪屏
        BeginBatchDraw();
        //刷新页面，因为后面的程序修改的是结构体里面的参数
        putimage(0, 0, &mm);
        //标题
        outtextxy(300, 40, "文物信息管理系统");
        //所以每一次循环都要重新画按钮

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

        printf("\t\t\t\t-------- 文物信息管理系统-------\n\n\n\n");     //菜单 
        printf("\t\t\t\t\t1. 增加文物信息\n\n");
        printf("\t\t\t\t\t2. 修改文物信息\n\n");
        printf("\t\t\t\t\t3. 删除文物信息\n\n");
        printf("\t\t\t\t\t4. 查询文物信息\n\n");
        printf("\t\t\t\t\t5. 按文物名称排序\n\n");
        printf("\t\t\t\t\t0. 退出\n\n\n");

        printf("请选择(0-5):");
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
